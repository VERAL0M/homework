
#include <iostream>
#include "module.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
int main(){

    using namespace std;

    int n=10;



    while (n!=0)
    {
        
        cout<<"1. STL2Seq5"<<endl;
        cout<<"2. STL2Seq15"<<endl;
        cout<<"3. STL2Seq23"<<endl;
        cout<<"4. STL1Iter19"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Введите номер задачи: ";
        cin>>n;
        switch (n)
        {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;

        case 4:
            task4();
            break;
        case 0:
            break;
        default:
            cout<<"Не существует задачи с таким нормером";
            break;

        }
    }
    
    
}
