#pragma once
#include"ILySystemStatus.h"
#include"EnumDefine.h"
class CLySystemStatus :
    public ILySystemStatus
{
public:
    CLySystemStatus();
    virtual ~CLySystemStatus();



private:
    virtual void GetNetworkInfo();

private:
    bool m_bType1 ;
    bool m_bType2 ;

public:
    virtual ELyNetworkType GetNetWorkType() override;
    
};

