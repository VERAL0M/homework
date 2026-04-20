#include "module.h"
#include <iostream>





int main(){

    using namespace std;

    int n=10;

    while (n!=0)
    {
        
        cout<<"1. task1"<<endl;
        cout<<"2. task2"<<endl;
        cout<<"3. task3"<<endl;
        cout<<"4. task4"<<endl;
        cout<<"5. task5"<<endl;
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
        case 5:
            task5();
            break;
        case 0:
            break;
        default:
            cout<<"Не существует задачи с таким нормером";
            break;

        }
    }
    
    
}
