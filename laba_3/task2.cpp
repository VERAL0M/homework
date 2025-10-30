#include <iostream>
#include <fstream>


using namespace std;


int main(){

    int a, b, n, new_a;
    ofstream f2;


    cout<<"press a: ";
    cin>>a;
    cout<<"press b: ";
    cin>>b;
    cout<<"press N: ";
    cin>>n;
    f2.open("a.txt", ios::out);
    while (a<=b){
        new_a=abs(a);
        while (new_a>0)
        {
            if (new_a%10==n){
                f2<<a<<" "<<endl;
                break;
            }
            new_a/=10;
        }
        
        // f2<<a<<" "<<endl;
        a=a+1;
    }
    return 0;
}