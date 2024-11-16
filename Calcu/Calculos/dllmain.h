// dllmain.h : Declaración de clase de módulo.

class CCalculosModule : public ATL::CAtlDllModuleT< CCalculosModule >
{
public :
	DECLARE_LIBID(LIBID_CalculosLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_CALCULOS, "{b4581a64-da70-408b-8e06-1dac125d7d2b}")
};

extern class CCalculosModule _AtlModule;
