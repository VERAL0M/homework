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
        
        cout<<"1. STL3Alg8"<<endl;
        cout<<"2. STL3Alg23"<<endl;
        cout<<"3. STL3Alg43"<<endl;
        cout<<"4. STL3Alg61"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Введите номер задачи: ";
        cin>>n;
        switch (n)
        {
        case 1:
            cout<<"Необходимо было удалить K подряд идущих нулей с конца"<<endl;
            STL3Alg8();
            break;
        case 2:
            STL3Alg23();
            break;
        case 3:
            STL3Alg43();
            break;
        case 4:
            STL3Alg61();
            break;
        case 0:
            break;
        default:
            cout<<"Не существует задачи с таким нормером";
            break;

        }
    }
    
    
}
