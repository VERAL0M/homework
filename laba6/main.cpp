#include <iostream>
#include <fstream>
#include "module.h"


int main(){
    using namespace std;
    int n;
    
    cout<<"1. examtask4"<<endl;
    cout<<"2. task2"<<endl;
    cout<<"3. task3"<<endl;;
    cout<<"Выберите нормер задачи: ";
    cin>>n;
    switch (n)
    {
    case 1:
        examtask4();
        break;
    case 2:
        task2();
        break;
    case 3:
        task3();
        break;
    default:
        break;
    }

}