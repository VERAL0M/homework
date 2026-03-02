#include "func.h"
#include <iostream>

int main(){
    using namespace std;

    int n;
    cout<<"Введите номер задачи"<<endl;
    cout<<"1. Cумма элементов массива"<<endl;
    cout<<"2. Подсчёт счётных числел"<<endl;
    cout<<"3. Поиск максимального и минимального элемента"<<endl;
    cout<<"4. Среднее арифметическое"<<endl;
    cout<<"5. Количество положительных и отрицательных чисел"<<endl;
    cout<<"6. Инверсия массива"<<endl;
    cout<<"7. Количество локальных максимумов"<<endl;
    cout<<"9. Объединение двух массивов"<<endl;
    cout<<"10. Удаление всех нулей из массива"<<endl;
    
    cin>>n;
    switch (n)
    {
    case 1:
        task1();
        break;
    case 2:
        task2();
        break;
    case 3:
        task3();
        break;
    case 4:
        task4();
        break;
    default:
        break;
    }
}


