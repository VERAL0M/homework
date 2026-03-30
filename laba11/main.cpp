
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
        
        cout<<"1. ListWork69"<<endl;
        cout<<"2. ListWork41"<<endl;
        cout<<"3. ListWork44"<<endl;
        cout<<"4. ListWork47"<<endl;
        cout<<"5. 8"<<endl;
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
        default:
            cout<<"Не существует задачи с таким нормером";
            break;

        }
    }
    
    
}
