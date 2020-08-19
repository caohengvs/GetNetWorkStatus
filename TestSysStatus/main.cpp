#include"../LySysStatus/ILySystemStatus.h"
#include<iostream>
using namespace std;
int main()
{
    ILySystemStatus* m_pStatus = ILySystemStatus::s_GetInstance();

    switch (m_pStatus->GetNetWorkType())
    {
    case NETWORK_ETHERNET:
        cout << "有线网络" << endl;
        break;
    case NETWORK_WIFI:
        cout << "无线网络" << endl;
        break;
    case NETWORK_ALL:
        cout << "all" << endl;
        break;
    default:
        cout << "未知" << endl;
        break;

    }
    if (m_pStatus)
    {
        ILySystemStatus::s_DestoryInstance(m_pStatus);
    }
    return 0;
    
}
