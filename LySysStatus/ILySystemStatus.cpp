#include "pch.h"
#include "ILySystemStatus.h"
#include "CLySystemStatus.h"


ILySystemStatus::ILySystemStatus()
{
}

ILySystemStatus::~ILySystemStatus()
{
}

ILySystemStatus* ILySystemStatus::s_GetInstance()
{
    CLySystemStatus* pStatus = new CLySystemStatus;
    if (pStatus)
    {
        return pStatus;
    }
    return nullptr;

}

void ILySystemStatus::s_DestoryInstance(ILySystemStatus* pStatus)
{
    if (pStatus)
    {
        delete pStatus;
        pStatus = nullptr;
    }
}

