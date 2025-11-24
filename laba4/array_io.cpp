#include "module.h"
#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <climits> // для констант MAX

using namespace std;

vector<vector<int>> random_array(){ // генерация массива с заполенением массвиа случайными числами в диапазоне от a до b
    int col, row,a,b;
    cout<<"Введите кол-во рядов";
    cin>>row;
    
    cout<<"Введите кол-во столбцов";
    cin>>col;
    


    cout<<"Введите а:";
    cin>>a;

    cout<<"Введите b: ";
    cin>>b;

    vector<vector<int>> matrix(row, vector<int>(col));
    
    srand(time(0));
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            matrix[i][j]=a+rand()%b;

        }
    }
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return matrix;
}


vector<vector<int>> hand_array(){ // гененрация массива и заполение ручным способом
    int col, row; 
    cout<<"Введите количство строк: ";
    cin>>row;
    cout<<"Введите количство столбцов: ";
    cout<<col;
    
    vector<vector<int>> matrix(row, vector<int>(col));

    for (int i=0; i<col; i++){
        for (int j=0; j<row; j++){
            cout<<"Введите элемент матрицы: ";
            cin>>matrix[i][j];

        }
    }
    for (int i=0; i<col; i++){
        for (int j=0; j<row; j++){

            cout<<matrix[i][j]<<" ";

        }
        cout<<endl;
    }
    return matrix;
}


vector<vector<int>> file_array(const string& name_file) {
    string line, last_line;
    int count_line = 0, count_row = 0;
    int i = 0, j = 0;

  
    ifstream file(name_file);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла." << endl;
        return {};
    }


    while (getline(file, line)) {
        ++count_line;
        last_line = line;
    }


    istringstream iss(last_line);
    string word;
    while (iss >> word) {
        ++count_row;
    }


    // vector<vector<int>> matrix(count_line, vector<int>(count_row));
    vector<vector<int>> matrix(count_row, vector<int>(count_line));


    file.clear(); // Очищаем флаги состояния потока
    file.seekg(0); // Переходим обратно в начало файла


    for (i = 0; i < count_line && getline(file, line); ++i) {
        istringstream row_stream(line);
        for (j = 0; j < count_row && row_stream >> matrix[i][j]; ++j) {}
    }

    file.close();
    return matrix;
}


vector<vector<int>> file_array() { // перенос массива из файла
    
    string line, last_line, name_file;
    cout<<"Введите имя имя файла + расширение: ";
    cin>>name_file;
    int count_line = 0, count_row = 0;
    int i = 0, j = 0;

  
    ifstream file(name_file);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла." << endl;
        return {};
    }

    while (getline(file, line)) {
        ++count_line;
        last_line = line;
    }

    istringstream iss(last_line);
    string word;
    while (iss >> word) {
        ++count_row;
    }

    // vector<vector<int>> matrix(count_line, vector<int>(count_row));
    vector<vector<int>> matrix(count_row, vector<int>(count_line));

    file.clear(); // Очищаем флаги состояния потока
    file.seekg(0); // Переходим обратно в начало файла

    for (i = 0; i < count_line && getline(file, line); ++i) {
        istringstream row_stream(line);
        for (j = 0; j < count_row && row_stream >> matrix[i][j]; ++j) {}
    }

    file.close();
    return matrix;
}


void show_matrix_file(){ //вывод массива заполненого из файла
    string name_file;
    cout<<"Введите название файла. Незабудьте указать расширение";
    cin>>name_file;

    auto result = file_array(name_file);
    for (const auto &row : result){
        for (int val : row){
            cout<< val<<" ";
        }
    }
}

// void show_random_matrix(){
//     int col, row,a,b;
//     cout<<"Введите кол-во столбцов";
//     cin>>col;
    
//     cout<<"Введите кол-во рядов";
//     cin>>row;

//     cout<<"Введите а:";
//     cin>>a;

//     cout<<"Введите b: ";
//     cin>>b;

//     auto matrix = random_array(col, row, a,b);
//     for (int i=0; i<col; i++){
//         for (int j=0; j<row; j++){
//             cout<<matrix[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }
    
// void show_hand_matrix(){
//     int row, col;
//     cout<<"Введите сol: ";
//     cin>>col;
//     cout<<"Введите row: ";
//     cin>>row;

//     auto matrix = hand_array(col, row);
//     for (int i =0; i<col; i++){
//         for (int j=0; j<row; j++){
//             cout<<matrix[i][j]<<" ";
            
//         }
//     }

// }


void Matrix26(){
    int n;
    vector<vector<int>> matrix;
    cout<<"1. Случайная генерация матрицы"<<endl;
    cout<<"2. Ручной ввод матрицы"<<endl;
    cout<<"3. Загрузка матрицы из файла"<<endl;
    cout<<"Выберите режим создания матрицы: ";
    cin>>n;


    switch (n)
    {
    case 1:
        matrix = random_array();
        break;
    case 2:
        matrix = hand_array();
        break;
    case 3:
        matrix = file_array();
        break;

    default:
        break;
    }
    
    int count_col=0, count_row=0;
    for (const auto &row : matrix){
        count_row++;
        for (int val : row){
            count_col++;
        }
    
    }
    count_col/=count_row;
    vector<long long> max_multiplications(count_col);
    for (int i=0; i<count_col; i++){
        max_multiplications[i]=1;
    }
    count_col=0;
    for (const auto &row: matrix){
        count_row++;
        for (int val: row){
            
            max_multiplications[count_col]*=val;
            count_col++;
        }
        count_col=0;
    }
    long long el=INT_MAX;


    for (const auto &col : max_multiplications){

        if (col<el){
            el=col;
        }
        cout<<"Самое маленькое произведние в столбцах "<<el<<endl;
    }
    int counter=0;
    for (const auto &col: max_multiplications){

        if (col==el){
            cout<<"Нормер столбца с минимальным произведением: "<<counter<<endl;
        }
        counter++;
    }
    
}
// void Matrix26();
void DArray8(){
    int n;
    vector<vector<int>> matrix;
    cout<<"1. Случайная генерация матрицы"<<endl;
    cout<<"2. Ручной ввод матрицы"<<endl;
    cout<<"3. Загрузка матрицы из файла"<<endl;
    cout<<"Выберите режим создания матрицы: ";
    cin>>n;


    switch (n)
    {
    case 1:
        matrix = random_array();
        break;
    case 2:
        matrix = hand_array();
        break;
    case 3:
        matrix = file_array();
        break;

    default:
        break;
    }
    
    int count_col=0, count_row=0;
    for (const auto &row : matrix){
        count_row++;
        for (int val : row){
            count_col++;
        }
    
    }
    int z;
    for (int i=0; i<count_row; i++){
        for (int j =i+1;j<count_row; j++ ){

            swap( matrix[i][j], matrix[j][i]);

        }
    }
    cout<<"Вывод новой матрицы"<<endl;
    cout<<endl;
    for (int i=0; i<count_row; i++){
        for (int j=0; j<count_row; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void DArray11();


