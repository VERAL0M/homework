#include <iostream>
#include "generate.h"

using namespace std;

int main(){
    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    int n;

    wcout << L"Выберите номер задачи:" << endl;
    wcout << L"1. String48" << endl;
    wcout << L"2. Str20" << endl;
    wcout << L"3. Str25" << endl;
    wcout << L"4. Str37" << endl;
    wcout << L"5. Str33" << endl;
    wcout << L"6. Задача 6(2)" << endl;
    wcout << L"7. Five8" << endl;
    wcout << L"Ваш выбор: ";
    

    wcin >> n;

    switch (n) {
    case 1: {

        
        string48();
        break;
    }
    case 2:
    {

        str20();
        break;
    }
    case 3:
    {
        str25();
        break;
    }
    case 4:
    {
        str37();
        break;
    }
    case 5: 
    {
        str33();
        break;
    }
    case 6:
    {
        task6();
        break;
    }
    case 7:
    {
        five8();
        break;
    }
    default:
        wcout << L"Неверный выбор. Попробуйте снова." << endl;
        break;
    }
    

}