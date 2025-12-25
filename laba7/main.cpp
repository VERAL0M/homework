#include <iostream>
#include "module.h"

int main(){
    using namespace std;
    int n;
    
    cout<<"1. Sort 8"<<endl;
    cout<<"2. ExamTaskC16"<<endl;
    cout<<"3. Five13"<<endl;
    cout<<"Введите номер задачи: ";
    cin>>n;
    switch (n)
    {
    case 1:
        sort8();

        break;
    case 2:
        ExamTaskC16();
    case 3:
        Five13();
    default:
        break;
    }
}



