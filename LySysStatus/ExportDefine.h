#pragma once
#ifdef _SYS_STATUS_DLL_
#define _SYS_STATUS_HEADER_DLL_ _declspec(dllexport)
#define _SYS_STATUS_FUN_HEADER_DLL_  extern "C" __declspec(dllexport)
#else
#define _SYS_STATUS_HEADER_DLL_ __declspec(dllimport)
#define _SYS_STATUS_FUN_HEADER_DLL_  extern "C" __declspec(dllimport)
#endif

