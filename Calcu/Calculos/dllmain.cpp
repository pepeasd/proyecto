// dllmain.cpp : Implementación de DllMain.

#include "pch.h"
#include "framework.h"
#include "resource.h"
#include "Calculos_i.h"
#include "dllmain.h"
#include "compreg.h"
#include "xdlldata.h"

CCalculosModule _AtlModule;

class CCalculosApp : public CWinApp
{
public:

// Invalidaciones
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CCalculosApp, CWinApp)
END_MESSAGE_MAP()

CCalculosApp theApp;

BOOL CCalculosApp::InitInstance()
{
#ifdef _MERGE_PROXYSTUB
	if (!PrxDllMain(m_hInstance, DLL_PROCESS_ATTACH, nullptr))
		return FALSE;
#endif
	return CWinApp::InitInstance();
}

int CCalculosApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}
