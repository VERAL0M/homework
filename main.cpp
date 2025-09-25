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

// // "Task 8"
// #include <iostream>

// using namespace std;

// int main(){
//     float a,b,c,d,e;
//     int mouse=1;
//     cout<<"a b c d e"<<endl;
//     cin>>a>>b>>c>>d>>e;
//     float cat=mouse*e;
//     float dog=cat*d;
//     float girl=dog*c;
//     float grandmother=girl*b;
//     float grandfather=grandmother*a;
//     float turnip=mouse+cat+dog+girl+grandfather+grandmother;
//     cout<<turnip/mouse<<endl;
//     return 0;
// }


// // "Task 9"
// #include <iostream>

// using namespace std;

// int main(){
//     int v1, v2,x,y;
//     float s;
//     cout<<"v1 v2 x y"<<endl;
//     cin>>v1>>v2>>x>>y;
//     float y_hours=float(y)/60;
//     s=v2*y_hours+v1*x;

//     cout<<"Растояние между городом А и деревней Б "<<s<<"км"<<endl;
//     return 0;
// }





// // "Task 10"
// #include <iostream>

// using namespace std;


// int main(){
//     float s, v;
//     cout<<"Введи S: "<<endl;
//     cin>>s;
//     cout<<"Введи V: "<<endl;
//     cin>>v;
//     cout<<(3*60)-(s*1000/v)<<endl;
//     return 0;
// }


// // Task 11
// #include <iostream>

// using namespace std;

// int main(){
//     float x,y,z;
//     cout<<"Введите количество слов в минуту первой тётеньки: "<<endl;
//     cin>>x;
//     cout<<"Введите количество слов в минуту второй тётеньки: "<<endl;
//     cin>>y;
//     cout<<"Введите кол-во часов: "<<endl;
//     cin>>z;
//     cout<<(x+y)*z*60<<endl;
//     return 0;
// }


// // Task 12

// #include <iostream>

// using namespace std;

// int main(){
//     int y;
//     float s, x;
//     cout<<"Введите S: "<<endl;
//     cin>>x;
//     s=x*100/100;
//     cout<<"Бабушка собрала "<<s<<"коп."<<endl;
//     return 0;
// }


