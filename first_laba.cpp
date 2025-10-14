// Task One(2)
// #include <iostream>

// using namespace std;

// int main(){
//     int x,y;
//     float s;
//     cin>>x>>y;
//     s=x*y/60;
//     cout<<s<<endl;
//     return 0;

// }

// task 3
// #include <iostream>

// using namespace std;

// int main(){
//     int x,y,z;
//     float v,s;
//     cin>>x>>y>>z;
//     v=x*(100+y)/100;
//     s=v*z-x*z;
//     cout<<v<<'\n'<<s<<'\n'<<endl;
//     return 0;
// }


// #include <iostream>

// using namespace std;

// int main(){
//     float x, y, k;
//     float two_box, one_box;

//     cout<<"X "<<"Y%  "<<"k ";
//     cin>>x>>y>>k;
       
//     two_box=k*((100+y)/100);
//     one_box=two_box/x;
    
//     cout<<"All apples: "<<two_box+one_box+k<<endl;
//     return 0;
// }


// #include <iostream>

// using namespace std;

// int main(){
//     int x,y,z;
//     float weight_cat;
//     cout<<"X, Y, Z ";
//     cin>>x>>y>>z;
//     weight_cat =(z*(100-y)/100+z)*y;
//     cout<<"Weight Cat: "<<weight_cat<<endl;
//     return 0;

// }


// #include <iostream>

// using namespace std;

// int main(){
//     int t,x,z;
//     float speed_one, speed_two;
//     cout<<"t, x, z "<<endl;
//     cin>>t>>x>>z;
//     speed_one = x/t;
//     speed_two = x*(100-z)/100/t;
//     cout<<"Speed first car: "<<speed_one<<"\n"<<"Speed twice car: "<< speed_two<<endl;
//     return 0;
// }



// #include <iostream>

// using namespace std;


// int main(){
//     int x, y;
//     int Sasha, Darina;
//     cout<<"x y"<<endl;
//     cin>>x>>y;
//     Darina=y-x;
//     Sasha=2*(Darina+y);
//     cout<<"All orange: "<<Darina+Sasha+y<<endl;
//     return 0;


// }


// #include <iostream>

// using namespace std;

// int main(){
//     float x,y;
//     cout<<"Введи x: ";
//     cin>>x;
//     cout<<"Введи y: ";
//     cin>>y;
//     if (x>0 && y>0){
//         cout<<"Первая четверть";
//     }
//     else{
//         if (x>0 && y<0){
//             cout<<"Четвёртная четверть";
//         }
//         else{
//             if (x<0 && y<0){
//                 cout<<"Третья четверть";
//             }
//             else{
//                 if (x<0 && y>0){
//                     cout<<"Вторая четверть";
//                 }
//                 else{
//                     if (x==0 && y!=0){
//                         cout<<"Точка лежит на ОY";
//                     }
//                     else{
//                         if (x!=0 && y==0){
//                             cout<<"Точка лежит на ОX";
//                         }
//                         else{
//                             if (x==0 && y==0){
//                                 cout<<"Точка лежит в начале координат";
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//     }

// }


// #include <iostream>
// using namespace std;

// int main(){
//     int m,n,s, t;
//     cout<<"Введите М: ";
//     cin>>m;
//     cout<<"Введите N: ";
//     cin>>n;



//     while (m!=0 || n!=0){
//         if (m>=n){
//             s=m;
//             n=m;
//             m=s%n;
//         }

//         else{
//             if (n>m){
//                 t=n;
//                 n=m;
//                 n=t%m;
//             }
//         }
//     cout<<m+n;
//     }
// }

// #include <iostream>
// using namespace std;

// int main(){
//     float a,b;
//     cout<<"Введи а:";
//     cin>>a;
//     cout<<"Введи b:";
//     cin>>b;

//     for (int i=a; i<=b; i++){
//         // cout<<"результат: "<<i*i+i-10<<endl;
//         cout<<"x: "<<i<<"    y: "<<i*i+i-10<<endl;

//     }
    

// }



// #include <iostream>

// using namespace std;

// int main(){
//     int n, s, a, b;
//     cout<<"введите N: ";
//     cin>>n;
//     if (n==0){
//         cout<<n<<" "<<1;
//     }
//     else{
//         cout<<n<<" "<<1;
//     }


//     for (int i=0; i<=n; i++){
//         a=1;
//         if (i<=2){
//             cout<<a;
//             break;
//         }
//         else{
//             s=a+b
//         }
 
//     }
// }