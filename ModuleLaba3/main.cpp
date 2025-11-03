
#include <iostream>
#include "module.h"
int main() {
    using namespace std;

    int n;
    cout<<"Введите номер задачи"<<endl;
    cout<<"1. Proc28: " <<endl;
    cout<<"2. Proc14: "<<endl;
    cout<<"3. Proc44: "<<endl;
    cout<<"4. TheTri14: "<<endl;
    cout<<"5. Reccur13: "<<endl;

    cin>>n;
    switch (n) {
        case 1:
            cin_isPrime();
            
            break;
        case 2:
            vvod_ShiftRight3();
        
            break;
        case 3:
            cin_Arctg1();
            break;
        case 4:
            cin_conversion();
            break;
        case 5:
            rec13();
            break;


    }

    return 0;
}