// // task 1
// #include <iostream>
// #include <iomanip>
// #include <string>
// #include <cmath>

// using namespace std;

// int main() {
//     float x1, y1,x2,y2;
//     cin>>x1>>y1>>x2>>y2;
//     double length1=pow(pow((x2-x1),2)+pow((y2-y1),2),0.5);
//     cout << length1 << endl;
    
//     return 0;
// }


// task 2

// #include <iostream>
// #include <string>
// #include <cmath>
// #include <iomanip>

// using namespace std;

// int main(){
//     float x1,y1,x2,y2,x3,y3;
//     cin>>x1>>y1>>x2>>y2>>x3>>y3;
//     double a=pow(pow(abs(x2-x1),2)+pow(abs(y2-y1),2),0.5);
//     double b=pow(pow(abs(x3-x2),2)+pow(abs(y3-y2),2),0.5);
//     double c=pow(pow(abs(x3-x1),2)+pow(abs(y3-y1),2),0.5);
//     double p=(a+b+c)/2;
    
//     double s=pow(p*(p-a)*(p-b)*(p-c),0.5);
//     cout<<"Square: "<<s<<"\n"<<"perimeter: "<<p*2<<"\n"<<endl;
//     return 0;
    
// }

// // task 3
// #include <iostream>
// #include <string>
// #include <iomanip>

// using namespace std;

// int main() {
//     double temperature;
//     cin>>temperature;
//     double new_temperature=1.8*temperature+32;
//     cout<<new_temperature<<endl;
//     return 0;
// }

// #include <iostream> 
// using namespace std;

// int main(){
//     int m,n;
//     cin>>m>>n;
//     while (m!=n)
//     {
//         if (m>n){
//             m-=n;
//         }
//         else{
//             n-=m;
//         }
        
//     }
//     cout<<m;
//     return 0;
    
    
// }


// #include <iostream>

// using namespace std;

// int main(){
//     int v,t;
//     float s;
//     cin>>v>>t;
//     s=v*3.6*t;


//     cout<<s<<endl;
//     return 0;
    

// }


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


// #include <iostream>
// #include <iomanip>
// #include <ctime>
// #include <cmath>


// using namespace std;


// // int main()
// // {
// //     srand(static_cast<unsigned int >(time (0)) );
// //     int randx= rand()%101-50;
// //     cout << randx << endl;
// //     int randu= rand();
// //     cout << randx << endl << randu << endl;


// //     return 0;
// // }

// int main(){
//     int choose;
//     double a,b;
//     for(;;){
//         cout<<"Введи"<<endl;
//         cout<<"1) + "<<endl;
//         cout<<"2) - "<<endl;
//         cout<<"3) * "<<endl;
//         cout<<"4) / "<<endl;
//         cout<<"5) Выход "<<endl;
//         cin>>choose;
//         if (choose==5){
//             cout<<"bye"<<endl;
//             break;
//         }
//         if (choose<=4 && choose>=1){
//             cout<<"введи a и b"<<endl;
//             cin>>a>>b;
//             switch (choose)
//             {
//             case 1:
//                 cout<<"answer: "<<a+b<<endl;
                
//                 break;
//             case 2:
//                 cout<<"answer: "<<a-b<<endl;
//                 break;
//             case 3: 
//                 cout<<"answer: "<<a*b<<endl;
//                 break;
//             case 4: 
//                 if (b!=0){
//                     cout<<"answer: "<<a/b<<endl;
                    
//                 }
//                 else{
//                     cout<<"введены не корректные значения";
                    
//                 }
//                 break;
                
            
//             default:
//                 cout<<"неверный выбор"<<endl;
//                 break;
//             }
//         }

//     }
// }



// "Case 1"
// #include <iostream>

// using namespace std;

// int main(){
//     int num;
//     cout<<"Введи число от 1 до 7: "<<endl;
//     cin>>num;
//     switch (num)
//     {
//     case 1:
//         cout<<"Понедельник"<<endl;
//         break;
//     case 2:
//         cout<<"Вторник"<<endl;
//         break;
//     case 3:
//         cout<<"Среда"<<endl;
//         break;
//     case 4:
//         cout<<"Четверг"<<endl;
//         break;
//     case 5:
//         cout<<"Пятница"<<endl;
//         break;
//     case 6:
//         cout<<"Суббота"<<endl;
//         break;
//     case 7:
//         cout<<"Воскресенье"<<endl;
//         break;
 
//     default:
//         cout<<"в не диапазона"<<endl;
//         break;
//     }
// }

// // "TheOne8"
// #include <iostream>

// using namespace std;

// int main(){
//     float x,y;
//     cout<<"введите x и y ";
//     cin>>x>>y;
//     if (y<=5 && y>=0){
//         if (y<=x*x+x-1){
//             cout<<"точка принадлеит заштрихованной области"<<endl;
//         }
//     }
// }


// // "TheOne19"

// #include <iostream>

// using namespace std;

// int main(){
//     int operand;
//     float l;
//     for (;;){
//         cout<<"Выбери перевод в желаемые еденицы измерения"<<endl;
//         cout<<"1) дециметр"<<endl;
//         cout<<"2) километр"<<endl;
//         cout<<"3) метр"<<endl;
//         cout<<"4) миллиметр"<<endl;
//         cout<<"5) сантиметр "<<endl;
//         cout<<"6) Выход "<<endl;
//         cin>>operand;
//     if (operand==6){
//         cout<<"bye-bye"<<endl;
//         break;
//     }
//     if (operand>=1 && operand<=5){
//         cout<<"Введи L: ";
//         cin>>l;

    
//         switch (operand)
//         {
//         case 1:
//             cout<<"Длинна отрезка L в метрах: "<<l/10<<endl;

//             break;
//         case 2:
//             cout<<"Длинна отрезка L в метрах: "<<l*1000<<endl;
            
//             break;
//         case 3:
//             cout<<"Длинна отрезка L в метрах: "<<l<<endl;
            
//             break;
//         case 4:
//             cout<<"Длинна отрезка L в метрах: "<<l/1000<<endl;
            
//             break;
//         case 5:
//             cout<<"Длинна отрезка L в метрах: "<<l/100<<endl;
            
//             break;


//         default:
//             cout<<"Ошибка!"<<endl;
//             break;
//         }
//     }
// }
// }

// // "One41"
// #include <iostream>

// using namespace std;

// int main(){
//     string n;
//     cout<<"Введи шестизначное число: ";
//     cin>>n;
//     if (n[0]==n[5]){
//         if (n[0]!=n[1] && n[0]!=n[2] && n[0]!=n[3] && n[0]!=n[4] && n[1]!=n[2] && n[1]!=n[3] && n[1]!=n[4] && n[2]!=n[3] && n[2]!=n[4] && n[3]!=n[4] ){
//             cout<<"True"<<endl;
//         }
//         else{
//             cout<<"Flase"<<endl;
//         }
//     }
//     else{
//         cout<<"False"<<endl;
//     }

// }


// "task 5(3)"
// #include <iostream>
// #include <cmath>
// using namespace std;

// int main(){
//     float a,b, alpha;
//     cout<<"Введите a, b, и угол А в градусах: "<<endl;
//     cin>>a>>b>>alpha;
    
//     cout<<0.5*a*b*sin(alpha*3.14159265358979/180)<<endl;



// }

// #include <iostream>

// using namespace std;

// int main(){
//     float long_road, price_oil, oil_km;
//     cout<<"Вычесление стоимости поездку на дачу."<<endl;
//     cout<<"Введите исходные данные: "<<endl;
//     cout<<"Растояние до дачи в одну сторону (км) ->";
//     cin>>long_road;
//     cout<<"Расход бензина (л на 100 км) ->";
//     cin>>oil_km;
//     cout<<"Цена литра бензина (руб)->";
//     cin>>price_oil;
//     cout<<"Поездка на дачу обойдётся "<<long_road*2*(oil_km/100)*price_oil<<" руб.";
// }
