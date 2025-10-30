#include <iostream>
#include <fstream>


int main(){
    using namespace std;
    int  n, counter=2, n_num;
    int fib1=1;
    int fib2=1;
    int i=0;

    cout<<"press N<30: ";
    cin>>n_num;
    ofstream f2;
    f2.open("d.txt", ios::out);



    n=1000;
    if (n_num==1){
        f2<<fib1<<" ";
    }
    else{
        if (n_num==2){
            f2<<fib1<<endl;
            f2<<fib2<<endl;
        }
        else{
            f2<<fib1<<endl;
            f2<<fib2<<endl;
            for (int i=2; i<n; i++){
                if (counter==n_num){
                    break;
                }
                else{
                    int sum_fib=fib1+fib2;
                    fib1=fib2;
                    fib2=sum_fib;
                    if (fib2%2!=0){
                        counter++;
                        f2<<fib2<<endl;
                    }
                }
            }
        }
    }
}
