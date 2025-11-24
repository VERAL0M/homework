#include "module.h"
#include "array_io.h"
#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;



int main(){
    int n;
    cout<<"1. Matrix26"<<endl;
    cout<<"2. Matrix54"<<endl;
    cout<<"3. DArray8"<<endl;
    cout<<"4. DArray11"<<endl;
    cin>>n;

    switch (n)
    {
    case 1:
        Matrix26();
        break;
    case 2:
        // Matrix54();
        break;
    case 3:
        // DArray8();
        break;
    case 4:
        // DArray11();
        break;
    default:
        break;
    }

}


// void choice_task(){
//     int n;
//     cout<<"1. Matrix26"<<endl;
//     cout<<"2. Matrix26"<<endl;
//     cout<<"3. DArray8"<<endl;
//     cout<<"4. DArray11"<<endl;
//     cin>>n;

//     switch (n)
//     {
//     case 1:
//         void Matrix26();
//         break;
//     case 2:
//         void  Matrix26();
//         break;
//     case 3:
//         void DArray8();
//         break;
//     case 4:
//         void DArray11();
//         break;
//     default:
//         break;
//     }
// }