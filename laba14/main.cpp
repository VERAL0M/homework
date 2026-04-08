
#include <iostream>
#include "module.h"



int main(){

    using namespace std;

    int n=10;

    while (n!=0)
    {
        
        cout<<"1. STL5Assoc3"<<endl;
        cout<<"2. STL5Assoc15"<<endl;
        cout<<"3. STL5Assoc22"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Введите номер задачи: ";
        cin>>n;
        switch (n)
        {
        case 1:
            STL5Assoc3();
            break;
        case 2:
            STL5Assoc15();
            break;
        case 3:
            STL5Assoc22();
            break;

        case 0:
            break;
        default:
            cout<<"Не существует задачи с таким нормером";
            break;

        }
    }
    
    
}
