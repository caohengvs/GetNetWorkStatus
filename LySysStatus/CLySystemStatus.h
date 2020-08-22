#pragma once
#include"ILySystemStatus.h"
class CLySystemStatus :
    public ILySystemStatus
{
public:
    CLySystemStatus();
    virtual ~CLySystemStatus();



private:
    virtual void GetNetworkInfo();

private:
    bool m_bType1; //保存是否为有有线网络连接
    bool m_bType2;
public:
    virtual bool GetNetWorkType() override;

};

