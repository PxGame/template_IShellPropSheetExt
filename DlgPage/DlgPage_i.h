

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Tue Dec 16 11:18:23 2014
 */
/* Compiler settings for DlgPage.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __DlgPage_i_h__
#define __DlgPage_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ICDlgPageExt_FWD_DEFINED__
#define __ICDlgPageExt_FWD_DEFINED__
typedef interface ICDlgPageExt ICDlgPageExt;
#endif 	/* __ICDlgPageExt_FWD_DEFINED__ */


#ifndef __CDlgPageExt_FWD_DEFINED__
#define __CDlgPageExt_FWD_DEFINED__

#ifdef __cplusplus
typedef class CDlgPageExt CDlgPageExt;
#else
typedef struct CDlgPageExt CDlgPageExt;
#endif /* __cplusplus */

#endif 	/* __CDlgPageExt_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ICDlgPageExt_INTERFACE_DEFINED__
#define __ICDlgPageExt_INTERFACE_DEFINED__

/* interface ICDlgPageExt */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ICDlgPageExt;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E274E943-FA1E-4D6D-B748-A379B2857AE8")
    ICDlgPageExt : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct ICDlgPageExtVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICDlgPageExt * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICDlgPageExt * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICDlgPageExt * This);
        
        END_INTERFACE
    } ICDlgPageExtVtbl;

    interface ICDlgPageExt
    {
        CONST_VTBL struct ICDlgPageExtVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICDlgPageExt_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICDlgPageExt_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICDlgPageExt_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICDlgPageExt_INTERFACE_DEFINED__ */



#ifndef __DlgPageLib_LIBRARY_DEFINED__
#define __DlgPageLib_LIBRARY_DEFINED__

/* library DlgPageLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_DlgPageLib;

EXTERN_C const CLSID CLSID_CDlgPageExt;

#ifdef __cplusplus

class DECLSPEC_UUID("54BE5184-2212-4D34-829A-6ABDF8CA8EB3")
CDlgPageExt;
#endif
#endif /* __DlgPageLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


