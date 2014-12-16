// CDlgPageExt.h : CCDlgPageExt ������

#pragma once
#include "resource.h"       // ������
#include "DlgPage_i.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;

// CCDlgPageExt

class ATL_NO_VTABLE CCDlgPageExt :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCDlgPageExt, &CLSID_CDlgPageExt>,
	public IShellExtInit,
	public IShellPropSheetExt
{
public:
	CCDlgPageExt()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_CDLGPAGEEXT)

DECLARE_NOT_AGGREGATABLE(CCDlgPageExt)

BEGIN_COM_MAP(CCDlgPageExt)
	COM_INTERFACE_ENTRY(IShellExtInit)
	COM_INTERFACE_ENTRY(IShellPropSheetExt)
END_COM_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	//IShellExtInit
	STDMETHOD(Initialize)(LPCITEMIDLIST, LPDATAOBJECT, HKEY);

	//IShellPropSheetExt
	STDMETHOD(AddPages)(LPFNADDPROPSHEETPAGE, LPARAM);
	STDMETHOD(ReplacePage)(UINT, LPFNADDPROPSHEETPAGE, LPARAM){
		return E_NOTIMPL;
	}

protected:
	string_list m_lsFiles;//�洢�ļ�ѡ�е��ļ�

};

OBJECT_ENTRY_AUTO(__uuidof(CDlgPageExt), CCDlgPageExt)
