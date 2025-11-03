#include <iostream>
#include <math.h>
using namespace std;

// void swap(int& x, int& y){
//     cout<<x<<"  "<<y<<endl;
//     int t;
//     t=x;
//     x=y;
//     y=t;
//     cout<<x<<" "<<y<<endl;
// }

// int main(){
//     int a,b;
//     cin>>a>>b;
//     swap(a, b);
//     cout<< a<<"  "<<b<<endl;
//     return 0;
// }

int Arctg1(int x=3, float e=0.01){
    float n=1, sum_arc=0, num;
    num=x;
    
    while (abs(num)>e)
    {
        sum_arc+=num;
        num=pow(-1, n)*pow(x, 2*n-1)/(2*n+1);
        n++;
    }
    cout<<sum_arc;
    return 1;
    
}


float reccur13(int n, float x){
    float s=0;

    if (n==1){
        
        return x;
    }
    else{
        return pow(-1, n-1)*n*pow(x, n)+ reccur13(n-1, x);


    }
    
}
int main(){

    int n=2;
    int x=4;
    // for (int i=1; i<=n; i++){
    //     s+=pow(-1, i)*i*pow(x, i);

    // }
    cout<<reccur13(n, x);


}
