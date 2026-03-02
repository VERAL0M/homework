#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <sstream>
#include "module.h"
#include <algorithm>





bool is_solvable(const std::vector<int>& board) {

    int inversions = 0;
    
    for (int i = 0; i < 15; i++) {
        if (board[i] == 0) continue;
        
        for (int j = i + 1; j < 16; j++) {
            if (board[j] == 0) continue;
            
            if (board[i] > board[j]) {
                inversions++;
            }
        }
    }

    int empty_row = 0;
    for (int i = 0; i < 16; i++) {
        if (board[i] == 0) {
            empty_row = 4 - (i / 4);  
            break;
        }
    }
    

    return (inversions % 2) != (empty_row % 2);
    
}
std::vector<int> load(){
    using namespace std; 
    vector<int> full_vector = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    vector<int> load_vector;
    cout<<"Введите название файла + .txt: ";
    string name_file;
    cin>>name_file;
    ifstream file(name_file);

    if (!file.is_open()) {
        cout<< "Ошибка открытия файла!"<<endl;
        return load_vector;
    }
    string line;
    if (std::getline(file, line)) {
        istringstream iss(line);
        int value, counter=0;

        
        while (iss >> value) {
            if (value<=15 && value>=0){
                if (value==0){
                    counter++;
                }
                
                load_vector.push_back(value);
            }
            else{
                cout<<"Числа выходят за диапазон допустимых значений"<<endl;
                return vector<int>();
            }
            
        }
        if (counter!=1){
            cout<<"Набор входных данных должен содержать ровно одну пустую клетку"<<endl;
            return vector<int>();
        }
    }
    
    file.close();  

    vector<int> sorted_load = load_vector;
    sort(sorted_load.begin(), sorted_load.end());
    if (sorted_load!=full_vector){
        cout<<"Файл с сохранением содержит ошибку. Возможно сущетсвуют повторяющиеся числа или файл пустой"<<endl;
        return vector<int>();
    }
    if (is_solvable(load_vector)){
        return load_vector;

    }
    else{
        cout<<"Файл с сохранением содержит ошибку. НЕТ РЕШЕНИЙ"<<endl;
        return vector<int>();
    }
    

}

std::vector<int> generation_game() {
    using namespace std;
    srand(time(0));
    
    vector<int> tag_array;
    vector<int> alfa = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15, 0};
    
    do {
        
        tag_array.clear();
        vector<int> temp_alfa = alfa;  
        
        for (int i = 0; i < 16; i++) {
            int index = rand() % temp_alfa.size();
            int num = temp_alfa[index];
            temp_alfa.erase(temp_alfa.begin() + index);
            tag_array.push_back(num);
        }
    } while (!is_solvable(tag_array));  
    
    return tag_array;
}
    

void upload(std::vector<int>&l){
    using namespace std;
    cout<<"Введите название файла для сохранения прогресса: ";
    string name_file;
    cin>>name_file;
    ofstream file(name_file);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }
    for (int i=0; i<16; i++){
        file<<l[i]<<" ";

    }
    cout<<"Игра сохранена в файл: "<<name_file<<" ";

}
void show(std::vector<int> &l){
    using namespace std;
    int start_pos;
    vector<int> victory ={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};


    bool flags=true;

    while (flags){
        if (victory==l){
            cout<<"      Игра завершена"<<endl;
            cout<<"───────▄▀▄─────▄▀▄───────"<<endl;
            cout<<"──────▄█░░▀▀▀▀▀░░█▄──────"<<endl;
            cout<<"──▄▄──█░░░░░░░░░░░█──▄▄──"<<endl;
            cout<<"─█▄▄█─█░░▀░░┬░░▀░░█─█▄▄█─"<<endl;
            cout<<"█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█"<<endl;
            cout<<"█ 💗  Вы выйграли!  💗  █"<<endl;
            cout<<"█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█"<<endl;
            cout<<"──▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄──"<<endl;
            cout<<"─█░░░█░░░░░░░░░░░▄▄░██░█─"<<endl;
            cout<<"─█░▀▀█▀▀░▄▀░░▄▀░░▀▀░▄▄░█─"<<endl;
            cout<<"─█░░░▀░░░▄▄▄▄▄▄░░██░▀▀░█─"<<endl;
            cout<<"──▀▄▄▄▄▄▀──────▀▄▄▄▄▄▄▀──"<<endl;
            cout<<endl;
            cout<<"Хотите сыграть снова? да/нет"<<endl;
            string answer;
            cin>>answer;
            if (answer=="да" || answer=="ДА" || answer=="Да"){
                int n;
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

                    }
                    else{
                        cout<<"Пока"<<endl;
                        break;
                    }
                            

                }

        string control;
        for (int i=0; i<16; i++){
            if (i%4==0){
                cout<<endl;
                cout<<"---------------------"<<endl;
                cout<<"| ";
            }
            if (l[i]<10){
                if (l[i]==0){
                    start_pos = i;
                    cout<<" "<<" "<<" | ";
                }
                else{
                    cout<<" "<<l[i]<<" | ";
                }
            }
            else{
                cout<<l[i]<<" | ";
            }
            
        }
        cout<<endl;
        cout<<"Управление: W-вверх, S-вниз, A-влево, D-вправо E-выход "<<endl;
        cout<<"...";
        
        cin>>control;
        control = toupper(control[0]);
        if (control=="A" && start_pos%4!=0){
            swap(l[start_pos-1], l[start_pos]);
            cout<<"________Update_______"<<endl;
        }
        else{
            if (control=="D" && (start_pos+1)%4!=0){
                swap(l[start_pos+1], l[start_pos]);
                cout<<"________Update_______"<<endl;}
            else{
                if (control=="W" && start_pos>3){
                    swap(l[start_pos-4], l[start_pos]);
                    cout<<"________Update_______"<<endl;
                }
                else{
                    if (control=="S" && start_pos<12){
                        swap(l[start_pos+4], l[start_pos]);
                        cout<<"________Update_______"<<endl;
                    }
                    else{
                        if ("E"==control){
                            cout<<"Игра завершена"<<endl;
                            upload(l);
                            flags=false;
                            
                        }
                        else{  
                            cout<<"Введён не поддреживаемый символ"<<endl;
                        }
                       
                    }
                }        
        }
    }
} 

}
