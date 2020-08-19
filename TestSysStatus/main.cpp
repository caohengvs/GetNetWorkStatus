#include"../LySysStatus/ILySystemStatus.h"
#include<iostream>
using namespace std;
int main()
{
    ILySystemStatus* m_pStatus = ILySystemStatus::s_GetInstance();

    switch (m_pStatus->GetNetWorkType())
    {
    case NETWORK_ETHERNET:
        cout << "��������" << endl;
        break;
    case NETWORK_WIFI:
        cout << "��������" << endl;
        break;
    case NETWORK_ALL:
        cout << "all" << endl;
        break;
    default:
        cout << "δ֪" << endl;
        break;

    }
    if (m_pStatus)
    {
        ILySystemStatus::s_DestoryInstance(m_pStatus);
    }
    return 0;
    
}
