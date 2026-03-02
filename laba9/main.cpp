#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> 
#include "module.h"

int main(){
    using namespace std;
    int n=10;
    

    while (n!=0)
    {
        cout<<"1. Task1"<<endl;
        cout<<"2. Task2"<<endl;
        cout<<"3. Task3"<<endl;
        cout<<"4. Task4"<<endl;
        cout<<"Введите 0 для выхода"<<endl;
        cout<<"Выберите задачу и введите её номер: ";
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
        default:
            break;
        }

    }
    

}

