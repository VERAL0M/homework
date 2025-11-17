#include "module.h"
#include <iostream>

using namespace std;


int nod(int a, int b) { // нод
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


void sokr(int& a, int& b){ // сокращение
    int nod1 = nod(a, b);
    a=a/nod1;
    b=b/nod1;
}

void sub(int& a , int& b, int& c, int&d){ // вычитание
    int new_znamenatel, new_chiclitel; 
    sokr(a,b);
    sokr(c, d);

    new_chiclitel=a*d-c*b;
    new_znamenatel=b*d;
    
    a=new_chiclitel;
    b=new_znamenatel;
}

void mult(int& a, int& b, int& c, int& d){ // вычитание
    a=a*c;
    b=b*d;
}


void vvod(){
    int a=0,b=0,c=0,d=0,e=0,f=0;
    

    
    while (a<0 || b<=0 || c<0 || d<=0 || e<0 || d<=0){

    
        cout<<"Введёные занчения не должны быть равны 0"<<endl;

        cout<<"Введите а: ";
        cin>>a;

        cout<<"Введите b: ";
        cin>>b;

        cout<<"Введите c: ";
        cin>>c;

        cout<<"Введите d: ";
        cin>>d;

        cout<<"Введите e: ";
        cin>>e;
        cout<<"Введите f: ";
        cin>>f;
    
    }
    
    sub(a,b,c,d);
    mult(a,b,e,f);

    cout<<a<<"/"<<b<<endl;
    sokr(a,b);
    cout<<"Сокращённая дробь: "<<a<<"/"<<b<<endl;

}


void cat(){
    cout<<"⣿⣿⣿⠟⠛⠛⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⢋⣩⣉⢻"<<endl;
    cout<<"⣿⣿⣿⠀⣿⣶⣕⣈⠹⠿⠿⠿⠿⠟⠛⣛⢋⣰⠣⣿⣿⠀⣿"<<endl;
    cout<<"⣿⣿⣿⡀⣿⣿⣿⣧⢻⣿⣶⣷⣿⣿⣿⣿⣿⣿⠿⠶⡝⠀⣿"<<endl;
    cout<<"⣿⣿⣿⣷⠘⣿⣿⣿⢏⣿⣿⣋⣀⣈⣻⣿⣿⣷⣤⣤⣿⡐⢿"<<endl;
    cout<<"⣿⣿⣿⣿⣆⢩⣝⣫⣾⣿⣿⣿⣿⡟⠿⠿⠦⠀⠸⠿⣻⣿⡄⢻"<<endl;
    cout<<"⣿⣿⣿⣿⣿⡄⢻⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣾⣿⣿⣿⣿⠇⣼"<<endl;
    cout<<"⣿⣿⣿⣿⣿⣿⡄⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣰"<<endl;
    cout<<"⣿⣿⣿⣿⣿⣿⠇⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢀⣿"<<endl;
    cout<<"⣿⣿⣿⣿⣿⠏⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿"<<endl;
    cout<<"⣿⣿⣿⣿⠟⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⣿"<<endl;
    cout<<"⣿⣿⣿⠋⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⣿"<<endl;
    cout<<"⣿⣿⠋⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⢸"<<endl;
    cout<<"⣿⠏⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡯⢸"<<endl;
}