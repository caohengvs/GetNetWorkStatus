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
    bool m_bType1; //�����Ƿ�Ϊ��������������
    bool m_bType2;
public:
    virtual bool GetNetWorkType() override;

};

