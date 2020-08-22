#include "pch.h"
#include "CLySystemStatus.h"
#include "NetworkHeader.h"

CLySystemStatus::CLySystemStatus()
{
}

CLySystemStatus::~CLySystemStatus()
{
}

void CLySystemStatus::GetNetworkInfo()
{
    m_bType1 = false;
    m_bType2 = false;
    PIP_ADAPTER_INFO pIpAdapterInfo = new IP_ADAPTER_INFO();
    //�õ��ṹ���С,����GetAdaptersInfo����
    unsigned long stSize = sizeof(IP_ADAPTER_INFO);
    //����GetAdaptersInfo����,���pIpAdapterInfoָ�����;����stSize��������һ��������Ҳ��һ�������
    int nRel = GetAdaptersInfo(pIpAdapterInfo, &stSize);
    //��¼��������
    int netCardNum = 0;
    //��¼ÿ�������ϵ�IP��ַ����
    int IPnumPerNetCard = 0;
    if (ERROR_BUFFER_OVERFLOW == nRel)
    {
        //����������ص���ERROR_BUFFER_OVERFLOW
        //��˵��GetAdaptersInfo�������ݵ��ڴ�ռ䲻��,ͬʱ�䴫��stSize,��ʾ��Ҫ�Ŀռ��С
        //��Ҳ��˵��ΪʲôstSize����һ��������Ҳ��һ�������
        //�ͷ�ԭ�����ڴ�ռ�
        delete pIpAdapterInfo;
        //���������ڴ�ռ������洢����������Ϣ
        pIpAdapterInfo = (PIP_ADAPTER_INFO)new BYTE[stSize];
        //�ٴε���GetAdaptersInfo����,���pIpAdapterInfoָ�����
        nRel = GetAdaptersInfo(pIpAdapterInfo, &stSize);
    }
    if (ERROR_SUCCESS == nRel)
    {
        //���������Ϣ
         //�����ж�����,���ͨ��ѭ��ȥ�ж�
        while (pIpAdapterInfo)
        {

            IP_ADDR_STRING* pIpAddrString = &(pIpAdapterInfo->IpAddressList);
            switch (pIpAdapterInfo->Type)
            {
            case MIB_IF_TYPE_ETHERNET:
                do
                {
                    if (strcmp(pIpAddrString->IpAddress.String, "0.0.0.0") > 0)
                    {
                        m_bType1 = true;

                    }
                    pIpAddrString = pIpAddrString->Next;
                } while (pIpAddrString);
                pIpAdapterInfo = pIpAdapterInfo->Next;
                break;
            default:
                do
                {
                    if (strcmp(pIpAddrString->IpAddress.String, "0.0.0.0") > 0)
                    {
                        m_bType2 = true;

                    }
                    pIpAddrString = pIpAddrString->Next;
                } while (pIpAddrString);
                pIpAdapterInfo = pIpAdapterInfo->Next;
                break;
            }

        }

    }
    //�ͷ��ڴ�ռ�
    if (pIpAdapterInfo)
    {
        delete pIpAdapterInfo;
    }
}

bool CLySystemStatus::GetNetWorkType()
{
    GetNetworkInfo();
    return m_bType1;
}

