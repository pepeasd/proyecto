// Contenedor de dlldata.c

#ifdef _MERGE_PROXYSTUB // Fusionar mediante combinación el archivo DLL de código auxiliar del proxy

#define REGISTER_PROXY_DLL //DllRegisterServer, etc.

#define USE_STUBLESS_PROXY	//Definido sólo con el modificador MIDL /Oicf

#pragma comment(lib, "rpcns4.lib")
#pragma comment(lib, "rpcrt4.lib")

#define ENTRY_PREFIX	Prx

#include "dlldata.c"
#include "Calculos_p.c"

#endif //_MERGE_PROXYSTUB
