// "Case 1"
// #include <iostream>

// using namespace std;

// int main(){
// int num;
// cout<<"Введи число от 1 до 7: "<<endl;
// cin>>num;
// switch (num)
// {
// case 1:
// cout<<"Понедельник"<<endl;
// break;
// case 2:
// cout<<"Вторник"<<endl;
// break;
// case 3:
// cout<<"Среда"<<endl;
// break;
// case 4:
// cout<<"Четверг"<<endl;
// break;
// case 5:
// cout<<"Пятница"<<endl;
// break;
// case 6:
// cout<<"Суббота"<<endl;
// break;
// case 7:
// cout<<"Воскресенье"<<endl;
// break;
 
// default:
// cout<<"в не диапазона"<<endl;
// break;
// }
// }

// // "TheOne8"
// #include <iostream>

// using namespace std;

// int main(){
// float x,y;
// cout<<"введите x и y ";
// cin>>x>>y;
// if (y<=5 && y>=0){
// if (y<=x*x+x-1){
// cout<<"точка принадлеит заштрихованной области"<<endl;
// }
// }
// }


// // "TheOne19"

// #include <iostream>

// using namespace std;

// int main(){
// int operand;
// float l;
// for (;;){
// cout<<"Выбери перевод в желаемые еденицы измерения"<<endl;
// cout<<"1) дециметр"<<endl;
// cout<<"2) километр"<<endl;
// cout<<"3) метр"<<endl;
// cout<<"4) миллиметр"<<endl;
// cout<<"5) сантиметр "<<endl;
// cout<<"6) Выход "<<endl;
// cin>>operand;
// if (operand==6){
// cout<<"bye-bye"<<endl;
// break;
// }
// if (operand>=1 && operand<=5){
// cout<<"Введи L: ";
// cin>>l;


// switch (operand)
// {
// case 1:
// cout<<"Длинна отрезка L в метрах: "<<l/10<<endl;

// break;
// case 2:
// cout<<"Длинна отрезка L в метрах: "<<l*1000<<endl;

// break;
// case 3:
// cout<<"Длинна отрезка L в метрах: "<<l<<endl;

// break;
// case 4:
// cout<<"Длинна отрезка L в метрах: "<<l/1000<<endl;

// break;
// case 5:
// cout<<"Длинна отрезка L в метрах: "<<l/100<<endl;

// break;


// default:
// cout<<"Ошибка!"<<endl;
// break;
// }
// }
// }
// }

// // "One41"
// #include <iostream>

// using namespace std;

// int main(){
// string n;
// cout<<"Введи шестизначное число: ";
// cin>>n;
// if (n[0]==n[5]){
// if (n[0]!=n[1] && n[0]!=n[2] && n[0]!=n[3] && n[0]!=n[4] && n[1]!=n[2] && n[1]!=n[3] && n[1]!=n[4] && n[2]!=n[3] && n[2]!=n[4] && n[3]!=n[4] ){
// cout<<"True"<<endl;
// }
// else{
// cout<<"Flase"<<endl;
// }
// }
// else{
// cout<<"False"<<endl;
// }

// }


// "task 5(3)"
// #include <iostream>
// #include <cmath>
// using namespace std;

// int main(){
// float a,b, alpha;
// cout<<"Введите a, b, и угол А в градусах: "<<endl;
// cin>>a>>b>>alpha;

// cout<<0.5*a*b*sin(alpha*3.14159265358979/180)<<endl;



// }

// #include <iostream>

// using namespace std;

// int main(){
// float long_road, price_oil, oil_km;
// cout<<"Вычесление стоимости поездку на дачу."<<endl;
// cout<<"Введите исходные данные: "<<endl;
// cout<<"Растояние до дачи в одну сторону (км) ->";
// cin>>long_road;
// cout<<"Расход бензина (л на 100 км) ->";
// cin>>oil_km;
// cout<<"Цена литра бензина (руб)->";
// cin>>price_oil;
// cout<<"Поездка на дачу обойдётся "<<long_road*2*(oil_km/100)*price_oil<<" руб.";
// }

0,1461 * 3+0,0737 * 4+0,0100 * 6+0,0474 * 4+0,0212 * 5+0,0337 * 5+0,0662 * 4+0,0112 * 6+0,0137 * 6+0,0799 * 4+0,0187 * 6+0,0175 * 6+0,0337 * 5+ 0,0312 * +0,0562 * 4+0,0799 * 4+0,0187 * 6+0,0362 * 5+0,0375 * 5+0,0437 * 4+0,0212 * 5+0,0050 * 7+0,0112 * 6+0,0062 * 7+0,0100 * 7+0,0125 * 6+0,0012 * 9+0,0025 * 9+0,0125 * +0,0175 * 6+0,0025 * 8+0,0212 * 5