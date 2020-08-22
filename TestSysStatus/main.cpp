#include"../LySysStatus/ILySystemStatus.h"
#include<iostream>
using namespace std;
int main()
{
    ILySystemStatus* m_pStatus = ILySystemStatus::s_GetInstance();

    if(m_pStatus->GetNetWorkType())
    {
        
   
        cout << "¸üÐÂ×´Ì¬" << endl;


    }
    if (m_pStatus)
    {
        ILySystemStatus::s_DestoryInstance(m_pStatus);
    }
    return 0;
    
}
