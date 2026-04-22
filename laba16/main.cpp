#include <iostream>
#include "module.h"

int main(){

    using namespace std;

    int n=10;

    while (n!=0)
    {
        cout<<"1. TreeWork8"<<endl;
        cout<<"2. TreeWork10"<<endl;
        cout<<"3. TreeWork18"<<endl;
        cout<<"4. Заглушка 4"<<endl;
        cout<<"5. Заглушка 5"<<endl;
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


        case 0:
            break;
        default:
            cout<<"Не существует задачи с таким номером"<<endl;
            break;
        }
    }
    
    return 0;
}