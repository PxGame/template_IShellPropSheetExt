// dllmain.h : 模块类的声明。

class CDlgPageModule : public ATL::CAtlDllModuleT< CDlgPageModule >
{
public :
	DECLARE_LIBID(LIBID_DlgPageLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_DLGPAGE, "{2D021F32-8807-4C15-9EE1-0195FBF00455}")
};

extern class CDlgPageModule _AtlModule;
