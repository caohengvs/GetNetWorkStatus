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
    //得到结构体大小,用于GetAdaptersInfo参数
    unsigned long stSize = sizeof(IP_ADAPTER_INFO);
    //调用GetAdaptersInfo函数,填充pIpAdapterInfo指针变量;其中stSize参数既是一个输入量也是一个输出量
    int nRel = GetAdaptersInfo(pIpAdapterInfo, &stSize);
    //记录网卡数量
    int netCardNum = 0;
    //记录每张网卡上的IP地址数量
    int IPnumPerNetCard = 0;
    if (ERROR_BUFFER_OVERFLOW == nRel)
    {
        //如果函数返回的是ERROR_BUFFER_OVERFLOW
        //则说明GetAdaptersInfo参数传递的内存空间不够,同时其传出stSize,表示需要的空间大小
        //这也是说明为什么stSize既是一个输入量也是一个输出量
        //释放原来的内存空间
        delete pIpAdapterInfo;
        //重新申请内存空间用来存储所有网卡信息
        pIpAdapterInfo = (PIP_ADAPTER_INFO)new BYTE[stSize];
        //再次调用GetAdaptersInfo函数,填充pIpAdapterInfo指针变量
        nRel = GetAdaptersInfo(pIpAdapterInfo, &stSize);
    }
    if (ERROR_SUCCESS == nRel)
    {
        //输出网卡信息
         //可能有多网卡,因此通过循环去判断
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
    //释放内存空间
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

