#include "module.h"

#include <iostream>
#include <math.h>
using namespace std;


bool isPrime(int n){
    int count=0;
    for (int i=1; i<=sqrt(n); i++){
        if (n%i==0){
            count+=2;
        }
    }
    if (count>2){
        return false;
    }
    else 
    {
        return true;
    }

}
void cin_isPrime(){
    int n, count=0;
    for (int i=1; i<=10; i++){
        cout<<"Введите число n: ";
        cin>>n;
        if (isPrime(n)){
            count++;
        }
    }
    cout<<"Количетсво простых числе в данном наборе: "<<count<<endl;
}



void ShiftRight3(float a, float b, float c){
    float y,z;

    y=b;
    z=c;

    c=a;
    b=z;
    a=y;
     cout<<"Новое значение а: "<<a<<" Новое значение b: "<<b<<" Новое значение с: "<<c<<endl;
    
}

void vvod_ShiftRight3(){

    float a,b,c;
    for (int i=1; i<=2; i++){
        cout<<"Введите a: ";
        cin>>a;
        cout<<"Введите b: ";
        cin>>b;
        cout<<"Введите c: ";
        cin>>c;
        cout<<"Начальное значение а: "<<a<<" Начальное значение b: "<<b<<" Начальное значение с: "<<c<<endl;
        ShiftRight3(a,b,c);

    }
    
}


float Arctg1(float x, float e){
    float n=1, sum_arc, num;
    num=x;
    sum_arc=num;
    
    while (abs(num)>e)
    {
        
        num=pow(-1, n)*pow(x, 2*n-1)/(2*n+1);
        sum_arc+=num;
        n++;
    }
    return sum_arc;
    
}

void cin_Arctg1(){
    float x, e;
    cout<<"Введите x: ";
    cin>>x;
    for (int i=1; i<=6;i++){

        cout<<"Введите e: ";
        cin>>e;
        
        cout<<"Значание arcttg(x) при текущем значании е: "<<Arctg1(x,e)<<endl;
    }
}


long long int conversion(int x, int p){
    long long int s=0;
    int  n=0;
    while (x!=0)
    {
        s=(x%p)*pow(10, n)+s;
        x/=p;
        n++;
    }
    return s;
    

}
void cin_conversion(){
    int x, p;
    cout<<"Введите x: ";
    cin>>x;
    cout<<"Введите (2<=p<=9) ";
    cin>>p;
    cout<<"Число x:"<<x<<" переведено из 10-ой системы счисления в "<<p<<"-ую и в новой системе счисления оно выглядит так: "<<conversion(x,p)<<endl;

}

long double reccur13(int n, float x){
    float s=0;

    if (n==1){
        return x;
    }
    else{
        return pow(-1, n+1)*pow(2, n-1)*pow(x, n)+ reccur13(n-1, x);

    }
}

void rec13(){
    int n;
    float x;
    cout<<"Введите n<10:";
    cin>>n;
    cout<<"Введите x: ";
    cin>>x;

    cout<<"Сумма ряда равна: "<<reccur13(n,x)<< endl;
}

