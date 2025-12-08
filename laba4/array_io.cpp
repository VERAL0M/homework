#include "module.h"
#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <climits> // для констант MAX

using namespace std;

vector<vector<int>> random_array(int row, int col, int a, int b){ // генерация массива с заполенением массвиа случайными числами в диапазоне от a до b


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



vector<vector<int>> file_array() { // перенос массива из файла
    
    string line, last_line, filename;
    cout<<"Введите имя имя файла + расширение: ";
    cin>>filename;

    int count_lines = 0, count_columns = 0;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла." << endl;
        return {};
    }

    // Чтение всех строк, подсчёт количества строк и запоминание последней строки
    while (getline(file, line)) {
        ++count_lines;
        last_line = line;
    }

    // Определение числа столбцов по последнему элементу
    istringstream iss(last_line);
    string word;
    while (iss >> word) {
        ++count_columns;
    }

    // Создаем правильную матрицу: count_lines строк и count_columns столбцов
    vector<vector<int>> matrix(count_lines, vector<int>(count_columns));

    // Возвращаемся в начало файла
    file.clear();
    file.seekg(0);

    // Заполняем матрицу данными из файла
    for (int i = 0; i < count_lines && getline(file, line); ++i) {
        istringstream row_stream(line);
        for (int j = 0; j < count_columns && row_stream >> matrix[i][j]; ++j) {}
    }

    file.close();
    return matrix;
}


void show_matrix_file(){ //вывод массива заполненого из файла
    string name_file;
    cout<<"Введите название файла. Незабудьте указать расширение";
    cin>>name_file;

    auto result = file_array();
    for (const auto &row : result){
        for (int val : row){
            cout<< val<<" ";
        }
    }
}


int regime(){
    int n;
    cout<<"1. Случайная генерация матрицы"<<endl;
    cout<<"2. Ручной ввод матрицы"<<endl;
    cout<<"3. Загрузка матрицы из файла"<<endl;
    cout<<"Выберите режим создания матрицы: ";
    cin>>n;
    return n;
}


void random_matrix_vvod(int& a, int& b, int& col, int& row){

        cout<<"Введите кол-во рядов M";
        cin>>row;
        
        cout<<"Введите кол-во столбцов N";
        cin>>col;
        
        cout<<"Введите а:";
        cin>>a;

        cout<<"Введите b: ";
        cin>>b;
}

void out(vector<vector<int>> &matrix){
        for (const auto& row : matrix){
            for (int val :  row){
                cout<<val<<" ";
            }
        cout<<endl;
        }
        
}

void save_as_file(vector<vector<int>> &matrix){
    cout<<"Сохраняем матрицу в файл"<<endl;
    ofstream f2; 
    f2.open("save.txt", ios::out);
    for (const auto &row: matrix){
        for (int val : row){
            f2<<val<<" ";
        }
    f2<<endl;
    }
}

void Matrix26(){

    vector<vector<int>> matrix;
    int n=regime();

    switch (n)
    {
    case 1:
        int col, row,a,b;
        random_matrix_vvod(a,b,col, row);

        matrix = random_array(row, col, a ,b);
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
    }
    cout<<"Самое маленькое произведние в столбцах "<<el<<endl;
        
    int counter=0;
    for (const auto &col: max_multiplications){

        if (col==el){
            cout<<"Нормер столбца с минимальным произведением: "<<counter<<endl;
        }
        counter++;
    }
    
}

void DArray8(){

    vector<vector<int>> matrix;
    int n=regime();


    switch (n)
    {
    case 1:
        int col, row,a,b;
        random_matrix_vvod(a,b,col, row);
        matrix = random_array(row, col, a ,b);

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
    cout<<"Выберите как хотите получить новую матрицу"<<endl;
    cout<<"1. Вывод в консоль"<<endl;
    cout<<"2. Сохранить в файл save.txt"<<endl;
    cin>>n;
    cout<<"Вывод новой матрицы"<<endl;

    switch (n)
    {
    case 1:
        out(matrix);
        break;
    case 2:
        save_as_file(matrix);
        

        break;
    
    default:
        cout<<"Нет такого режима вывода"<<endl;
        break;
    }



}


void DArray11(){
    int n=regime();
 
    vector<vector<int>> matrix;
    switch (n)
    {
    case 1:
        int col, row,a,b;
        random_matrix_vvod(a,b,col, row);
        matrix = random_array(col, row, a ,b);
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
    
    int count_col=0, count_row=0, max_el_index_row, max_el_index_col, minel=INT_MIN;
    
    
    for (const auto &row : matrix){
        count_col=0;
        
        for (int val : row){
            cout<<val<<" ";
            if (minel<val){
                minel=val;
                max_el_index_row=count_row;
                max_el_index_col=count_col;

            }
            count_col++;
        }
        cout<<endl;
        count_row++;

    }
    
    cout<<"index row: "<< max_el_index_row<<endl;
    cout<<"index col: "<<max_el_index_col<<endl;
    cout<<"Максимальный элемент матрицы: "<<matrix[max_el_index_row][max_el_index_col]<<endl;
    

}

bool isNegativeColumn(const vector<vector<int>>& matrix, int columnIndex) {
    for (const auto& row : matrix) {
        if (row[columnIndex] >= 0) {
            return false;
        }
    }
    return true;
}

void Matrix54(){
    int n;
    int mode = regime(); 
    vector<vector<int>> matrix;

    switch(mode) {
        case 1: {
            int a, b, col, row;
            random_matrix_vvod(a, b, col, row);
            matrix = random_array(row, col, a, b);
            break;
        }
        case 2: { 
            matrix = hand_array();
            break;
        }
        case 3: { 
            matrix = file_array();
            break;
        }
        default: {
            cerr << "Ошибка: неверный выбор режима.";
            return;
        }
    }


    const int columns = matrix.empty() ? 0 : matrix.front().size();

    int negColIdx = -1;
    for (int col = 0; col < columns; ++col) {
        if (isNegativeColumn(matrix, col)) {
            negColIdx = col;
            break;
        }
    }

    const int lastCol = columns - 1;

    // Производим обмен столбцами, если нужен столбец с отрицательными элементами
    if (negColIdx != -1) {
        for (int row = 0; row < matrix.size(); ++row) {
            swap(matrix[row][lastCol], matrix[row][negColIdx]); // Меняем соответствующие ячейки каждой строки
        }
    }

    cout<<"Выберите как хотите получить новую матрицу"<<endl;
    cout<<"1. Вывод в консоль"<<endl;
    cout<<"2. Сохранить в файл save.txt"<<endl;
    cin>>n;
    cout<<"Вывод новой матрицы"<<endl;

    switch (n)
    {
    case 1:
        out(matrix);
        break;
    case 2:
        save_as_file(matrix);
        break;
    
    default:
        cout<<"Нет такого режима вывода"<<endl;
        break;
    }

}


