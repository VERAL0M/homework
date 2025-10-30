// #include <iostream>
// #include <fstream>

// using namespace std;

// int main(){
//     int a, count=1;
//     string b;
//     ifstream f1;
//     ofstream f2;
//     f1.open("a.txt", ios::in);

//     f2.open("b.txt", ios::out);
//     if (!f1.is_open()){
//         cout<<"error";
//         return 1;
//     }
//     else{
//         z=f1.read()
//         while (f1>>b)
//         {
//             if (count%2==0){
//                 f2<<b<<" "<<endl;
                
//             }
//             else{
//                 f2<<b<<" ";
//             }
//             count+=1;
            

//         }
        
//     }
//     f1.close();
//     f2.close();
//     cout<<"all work";


// }

// #include <iostream>
// #include <fstream>


// using namespace std;


// int main(){

//     int a, b, n, new_a;
//     ofstream f2;


//     cout<<"press a: ";
//     cin>>a;
//     cout<<"press b: ";
//     cin>>b;
//     cout<<"press N: ";
//     cin>>n;
//     f2.open("a.txt", ios::out);
//     while (a<=b){
//         new_a=abs(a);
//         while (new_a>0)
//         {
//             if (new_a%10==n){
//                 f2<<a<<" "<<endl;
//                 break;
//             }
//             new_a/=10;
//         }
        
//         // f2<<a<<" "<<endl;
//         a=a+1;
//     }
//     return 0;

    
    


// }


// #include <iostream>
// #include <fstream>


// int fib(int n);

// int main(){
//     using namespace std;
//     int  n, counter=2, n_num;
//     int fib1=1;
//     int fib2=1;
//     int i=0;

//     cout<<"press N<30: ";
//     cin>>n_num;
//     ofstream f2;
//     f2.open("d.txt", ios::out);



//     n=1000;
//     if (n_num==1){
//         f2<<fib1<<" ";
//     }
//     else{
//         if (n_num==2){
//             f2<<fib1<<endl;
//             f2<<fib2<<endl;
//         }
//         else{
//             f2<<fib1<<endl;
//             f2<<fib2<<endl;
//             for (int i=2; i<n; i++){
//                 if (counter==n_num){
//                     break;
//                 }
//                 else{
//                     int sum_fib=fib1+fib2;
//                     fib1=fib2;
//                     fib2=sum_fib;
//                     if (fib2%2!=0){
//                         counter++;
//                         f2<<fib2<<endl;
//                     }
//                 }
//             }
//         }
//     }
// }


// #include <iostream>
// #include <fstream>
// #include <string>

// using namespace std;

// int main() {
//     ifstream fin("c.txt");

//     if (!fin.is_open()) {
//         cerr << "Ошибка открытия файла.\n";
//         return 1;
//     }

//     string s;
//     getline(fin, s);  // Первая строка содержит число N


//     int maxLength = 0;   // Максимально обнаруженная длина числа
//     int curLen = 0;      // Текущая длина числа
//     bool hasDigit = false;// Логическая переменная, была ли встречена хотя бы одна цифра

//     getline(fin, s);  // Получаем строку с числами

//     for (size_t pos = 0; pos <= s.size(); pos++) {
//         // Добавляем длину текущей цифры
//         curLen += (isdigit((pos < s.size()) ? s[pos] : ' ') & 1);
        
//         // Обновляем максимальное значение через логическое AND
//         maxLength += (((curLen > maxLength) & 1) * (curLen - maxLength));

//         // Отмечаем наличие цифры
//         hasDigit |= isdigit((pos < s.size()) ? s[pos] : ' ');

//         // Сбрасываем длину, если достигнута граница числа
//         curLen *= !(hasDigit & !isdigit((pos < s.size()) ? s[pos] : ' '));

//         // Сбрасываем флаг наличия цифры
//         hasDigit &= !!isdigit((pos < s.size()) ? s[pos] : ' ');
//     }

//     cout << "Максимальное количество цифр в числе: " << maxLength << '\n';

//     fin.close();
//     return 0;
// }
