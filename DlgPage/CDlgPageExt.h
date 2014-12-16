// CDlgPageExt.h : CCDlgPageExt 的声明

#pragma once
#include "resource.h"       // 主符号
#include "DlgPage_i.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
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
	string_list m_lsFiles;//存储文件选中的文件

};

OBJECT_ENTRY_AUTO(__uuidof(CDlgPageExt), CCDlgPageExt)
