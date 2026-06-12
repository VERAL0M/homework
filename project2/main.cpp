
#include <iostream>
#include <limits>
#include "play.h"

using namespace std;

int main() {

    
    int choice;
    do {
        showMenu();
        

        if (!(cin >> choice)) {
            cout << "\nОшибка ввода! Введите число от 1 до 3.\n";
            exit(EXIT_FAILURE); 
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
                exit(EXIT_FAILURE); 
        }
    } while (choice != 3);

    return 0;
}