#include <iostream>
#include <limits>
#include "play.h"

using namespace std;

int main() {

    
    int choice;
    do {
        showMenu();
        

        if (!(cin >> choice)) {
            cout << "Ошибка ввода! Введите число от 1 до 3.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: 
                playDurachok(); 
                break;
            case 2: 
                showRules(); 
                break;
            case 3: 
                cout << "Спасибо за игру! До свидания.\n"; 
                break;
            default: 
                cout << "Неверный пункт меню. Попробуйте снова.\n";
        }
    } while (choice != 3);

    return 0;
}