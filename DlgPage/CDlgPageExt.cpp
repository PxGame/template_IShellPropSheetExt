// CDlgPageExt.cpp : CCDlgPageExt µÄÊµÏÖ
#include "stdafx.h"
#include "CDlgPageExt.h"
# include "dllmain.h"

BOOL CALLBACK PropPageDlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
UINT CALLBACK PropPageCallbackProc(HWND hwnd, UINT uMsg, LPPROPSHEETPAGE ppsp);
BOOL OnInitDialog(HWND hwnd, LPARAM lParam);

// CCDlgPageExt
STDMETHODIMP CCDlgPageExt::Initialize(
	LPCITEMIDLIST pidlFolder, LPDATAOBJECT pDataObj, HKEY hProgID)
{
	TCHAR szFile[MAX_PATH];
	UINT uNumFiles;
	HDROP hDrop;
	FORMATETC etc = { CF_HDROP, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL };
	STGMEDIUM stg;
	INITCOMMONCONTROLSEX iccex = { sizeof(INITCOMMONCONTROLSEX), ICC_DATE_CLASSES };

	//Init the common controls.
	InitCommonControlsEx(&iccex);

	//Read the list of folders from the data object.
	if (FAILED(pDataObj->GetData(&etc, &stg)))
	{
		return E_INVALIDARG;
	}

	//Get an HDROP handle.
	hDrop = (HDROP)GlobalLock(stg.hGlobal);

	if (NULL == hDrop)
	{
		ReleaseStgMedium(&stg);
		return E_INVALIDARG;
	}

	//Determine how many file are involved in this operation.
	uNumFiles = DragQueryFile(hDrop, 0XFFFFFFFF, NULL, 0);

	for (UINT uFile = 0; uFile < uNumFiles; uFile++)
	{
		//Get the next filename.
		if (0 == DragQueryFile(hDrop, uFile, szFile, MAX_PATH))
		{
			continue;
		}

		//Add the filename to string_list.
		m_lsFiles.push_back(szFile);
	}

	//Release resource.
	GlobalUnlock(stg.hGlobal);
	ReleaseStgMedium(&stg);

	//Checkhow many files were selected.
	//If the number is greater than the maximum number of property pages, truncate list.
	if (m_lsFiles.size() > MAXPROPPAGES)
	{
		m_lsFiles.resize(MAXPROPPAGES);
	}

	//If we found ang files we can work with, return S_OK.
	return (m_lsFiles.size() > 0) ? S_OK : E_FAIL;
}

STDMETHODIMP CCDlgPageExt::AddPages(
	LPFNADDPROPSHEETPAGE lpfnAddPageProc, LPARAM lParam)
{
	PROPSHEETPAGE psp;
	HPROPSHEETPAGE hPage;
	TCHAR szPageTitle[MAX_PATH];

	string_list::const_iterator it, itEnd;

	for (it = m_lsFiles.begin(), itEnd = m_lsFiles.end(); it != itEnd; it++)
	{
		//This points at the next filename.
		//Allocate a new copy of the string that the page will own.
		LPCTSTR szFile = _tcsdup(it->c_str());

		if (NULL == szFile)
		{
			return E_OUTOFMEMORY;
		}

		//Strip the path and extension from the filename - this will be the page title.
		//The name is truncated at 24 chars so it fits on the tab.
		lstrcpyn(szPageTitle, szFile, MAX_PATH);//Copy path
		PathStripPath(szPageTitle);//Removes the path portion of a fully qualified path and file.
		PathRemoveExtension(szPageTitle);//Removes the file name extension from a path, if one is present.
		szPageTitle[24] = '\0';

		//Set up the PROPSHEETPAGE struct.
		ZeroMemory(&psp, sizeof(PROPSHEETPAGE));

		psp.dwSize = sizeof(PROPSHEETPAGE);
		psp.dwFlags = PSP_USEREFPARENT | PSP_USETITLE | PSP_DEFAULT |
			PSP_USEICONID | PSP_USECALLBACK;
		psp.hInstance	= _AtlBaseModule.GetResourceInstance();
		psp.lParam		= (LPARAM)szFile;
		psp.pszTitle	= szPageTitle;
		psp.pcRefParent = (UINT *)&_AtlModule.m_nLockCnt;
		psp.pszTemplate = MAKEINTRESOURCE(IDD_PROPPAGE);
		psp.pszIcon		= MAKEINTRESOURCE(IDI_ICON);
		psp.pfnDlgProc	= (DLGPROC)PropPageDlgProc;
		psp.pfnCallback = PropPageCallbackProc;

		///Create the page and get a handle.
		hPage = CreatePropertySheetPage(&psp);

		if (NULL != hPage)
		{
			//Call the shell`s callback function, 
			//so it add s the page to the property sheet
			if (!lpfnAddPageProc(hPage, lParam))
			{
				DestroyPropertySheetPage(hPage);
			}
		}
	}
	
	return S_OK;
}

BOOL CALLBACK PropPageDlgProc(
	HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	BOOL bRet = FALSE;;
	switch (uMsg)
	{
	case WM_INITDIALOG:
		bRet = OnInitDialog(hwnd, lParam);
		break;
	default:
		break;
	}

	return bRet;
}

UINT CALLBACK PropPageCallbackProc(
	HWND hwnd, UINT uMsg, LPPROPSHEETPAGE ppsp)
{
	switch (uMsg)
	{
	case PSPCB_RELEASE:
		free((void *)ppsp->lParam);
		break;
	}
	return TRUE;
}

BOOL OnInitDialog(HWND hwnd, LPARAM lParam)
{
	PROPSHEETPAGE* ppsp = (PROPSHEETPAGE *)lParam;
	LPCTSTR szFile = (LPCTSTR)ppsp->lParam;
	return TRUE;
}