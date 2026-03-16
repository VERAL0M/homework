#include <iostream>
#include "module.h"
int main(){
    using namespace std;
    int n=10;



    while (n!=0)
    {
        
        cout<<"1. Dynamic10"<<endl;
        cout<<"2. Dynamic17"<<endl;
        cout<<"3. ListWork8 "<<endl;
        cout<<"4. ListWork25"<<endl;
        cout<<"5. ListWork62"<<endl;
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
