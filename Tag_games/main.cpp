#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <sstream>
#include "module.h"




int main(){
    using namespace std;
    int n;
    cout<<"_____Игра Пятнашки_____"<<endl;
    cout<<endl;
    cout<<"Цель: "<<endl;
    cout<<"Расположить костяшки в правильном порядке:"<<endl;
    cout<<"1. Числа от 1 до 15 должны идти по возрастанию слева направо, сверху вниз"<<endl;
    cout<<"2. Пустая ячейка должна оказаться в правом нижнем углу"<<endl;
    cout<<endl;
    cout<<"Выберите режим игры"<<endl;
    cout<<"1. Старт"<<endl;
    cout<<"2. Загрузить сохранение"<<endl;
    cout<<"Введите: ";
    cin>>n;

    vector<int> game_board;  

    switch (n) {
        case 1:
            game_board = generation_game(); 
            show(game_board);
            break;
            
        case 2:
            game_board = load();  
            show(game_board);

            break;
        default:
            break;
        }

    return 0;

}

