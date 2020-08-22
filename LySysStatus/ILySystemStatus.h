#pragma once
#include"ExportDefine.h"
class _SYS_STATUS_HEADER_DLL_  ILySystemStatus
{
public:
    ILySystemStatus();
    virtual ~ILySystemStatus();

public:
    static ILySystemStatus* s_GetInstance();
    static void s_DestoryInstance(ILySystemStatus* pStatus);

public:
    virtual bool GetNetWorkType() = 0;
};

