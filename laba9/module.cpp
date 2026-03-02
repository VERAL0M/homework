#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> 
#include <string>
#include "module.h"
#include <ctime>

void task1(){
    using namespace std;
    vector<int> arrplus;
    vector<int> arrnotplus;
    
    fstream file("num.bin", ios::binary | ios::out | ios::trunc);

    if (file.is_open()){
        cout<<"Файл успешно создан"<<endl;
        
    }
    else{
        cerr<<"Ошибка создания файла"<<endl;

    }
    int n;
    cout<<"Введите количестов чисел: ";
    cin>>n;
    for (int i=0; i<n; i++){
        int num;
        cout<<"Введите число: ";
        cin>>num;
        file.write(reinterpret_cast<char*>(&num), sizeof(num));

    }
    file.close();

    fstream read_file("num.bin",  ios::binary | ios::in);
    if(!read_file.is_open()){
        cerr<<"Ошибка открытия файла"<<endl;
    }
    read_file.seekg(0, ios::end);
    streampos file_size = read_file.tellg();
    read_file.seekg(0, ios::beg);

    int count_num=file_size/sizeof(int);

    cout<<"Найдено чисел в файле: "<<count_num<<endl;

    for (int i=0; i<count_num; i++){
        int value;
        read_file.read(reinterpret_cast<char*>(&value), sizeof(int));
        if (read_file){
            cout<< value<<endl;

            if (value>0){
                
                arrplus.push_back(value);
                

            } 
            else {
                if (value < 0) {
                    
                    arrnotplus.push_back(value);
                    
                    
                }
            }
        }
    }
    reverse(arrplus.begin(), arrplus.end());
    reverse(arrnotplus.begin(), arrnotplus.end());

    fstream plus_file("num_plus.bin", ios::binary | ios::out | ios::trunc);
    fstream notplusfile("num_notplus.bin", ios::binary | ios::out | ios::trunc);

    for (int i=0; i<arrplus.size(); i++){
        int num_plus=arrplus[i];
        
        
        plus_file.write(reinterpret_cast<char*>(&num_plus), sizeof(num_plus));
        
    }
    plus_file.close();

    for (int i=0; i<arrnotplus.size(); i++){
        int num_minus=arrnotplus[i];
        
        notplusfile.write(reinterpret_cast<char*>(&num_minus), sizeof(num_minus));
        
    }
    notplusfile.close();


}

void task2(){
    using namespace std;
    vector<int> list_num;
    string name;
    cout<<"Введите название файла: ";
    cin>>name;

    fstream file(name, ios::binary | ios::out | ios::trunc);
    if (!file.is_open()){
        cerr<<"Ошибка создания файла"<<endl;
    }
    int n;
    cout<<"Введите кол-во чисел которые будут записаны в файл: ";
    cin>>n;
    for (int i=0; i<n; i++){
        int num;
        cout<<"Введите число: ";
        cin>>num;
        list_num.push_back(num);
        file.write(reinterpret_cast<char*>(&num), sizeof(num));

    }
    file.close();

    fstream file_read(name, ios::binary | ios::in);
    if(!file_read.is_open()){
        cerr<<"Ошибка открытия файла"<<endl;
    }
    file_read.seekg(0, ios::end);
    streampos file_size = file_read.tellg();
    file_read.seekg(0, ios::beg);

    int count_num=file_size/sizeof(int);

    cout<<"Найдено чисел в файле: "<<count_num<<endl;
    file_read.close();

    fstream file_write(name, ios::binary | ios::out);
    for (int i=0; i<2; i++){
        for (int j=0; j<n; j++){
            int el =list_num[j];
            file_write.write(reinterpret_cast<char*>(&el), sizeof(el));
        }

    }
    file_write.close();
    cout<<"Файл обновлён"<<endl;
    fstream read_file(name,  ios::binary | ios::in);
    if(!read_file.is_open()){
        cerr<<"Ошибка открытия файла"<<endl;
    }
    read_file.seekg(0, ios::end);
    streampos file_siz = read_file.tellg();
    read_file.seekg(0, ios::beg);

    int count_nu=file_siz/sizeof(int);

    cout<<"Найдено чисел в файле обновлённом: "<<count_num<<endl;

    for (int i=0; i<count_nu; i++){
        int value;
        read_file.read(reinterpret_cast<char*>(&value), sizeof(int));
        cout<<value<<" ";
    }

}

void createRandomFile(const std::string& filename, int count) {
    
    using namespace std;
    fstream file(filename, ios::binary | ios::out | ios::trunc);
    if (!file.is_open()) {
        cerr << "Ошибка создания файла " << filename << endl;
        return;
    }
    
    for (int i = 0; i < count; i++) {
        // Случайное число от -100 до 100
        int num = rand() % 201 - 100;  // -100..100
        file.write(reinterpret_cast<char*>(&num), sizeof(int));
    }
    
    file.close();
    cout << "Создан файл " << filename << " с " << count << " числами" << endl;
}


void printFileContent(const std::string& filename) {
    
    using namespace std;
    fstream file(filename, ios::binary | ios::in);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла " << filename << endl;
        return;
    }
    
    cout << "Содержимое файла " << filename << ": ";
    
    int num;
    while (file.read(reinterpret_cast<char*>(&num), sizeof(int))) {
        cout << num << " ";
    }
    cout << endl;
    
    file.close();
}
void task3(){

    using namespace std;

    srand(time(0));
    
    string archive_name;
    int N;
    
    cout << "Введите имя файла-архива: ";
    cin >> archive_name;
    
    cout << "Введите количество файлов (≤ 4): ";
    cin >> N;
    
    if (N > 4) {
        cerr << "Ошибка: N должно быть ≤ 4" << endl;
        return;
    }
    

    vector<string> filenames;
    

    cout << "\n--- СОЗДАНИЕ ИСХОДНЫХ ФАЙЛОВ ---\n";
    for (int i = 0; i < N; i++) {
        filenames.push_back("file" + to_string(i + 1) + ".bin");
        
        // Случайный размер файла от 3 до 10 чисел
        int file_size = rand() % 8 + 3;  // 3..10
        createRandomFile(filenames[i], file_size);
    }
    

    cout << "\n--- СОДЕРЖИМОЕ ИСХОДНЫХ ФАЙЛОВ ---\n";
    for (int i = 0; i < N; i++) {
        printFileContent(filenames[i]);
    }
    

    cout << "\n--- СОЗДАНИЕ АРХИВА ---\n";
    fstream archive(archive_name, ios::binary | ios::out | ios::trunc);
    if (!archive.is_open()) {
        cerr << "Ошибка создания архива" << endl;
        return;
    }

    for (int i = 0; i < N; i++) {

        fstream source(filenames[i], ios::binary | ios::in);
        if (!source.is_open()) {
            cerr << "Ошибка открытия файла " << filenames[i] << endl;
            continue;
        }
        

        source.seekg(0, ios::end);
        streampos file_size = source.tellg();
        source.seekg(0, ios::beg);
        
        int element_count = file_size / sizeof(int);

        archive.write(reinterpret_cast<char*>(&element_count), sizeof(int));
        cout << "Записываем размер файла " << filenames[i] << ": " << element_count << endl;
        

        cout << "Записываем числа: ";
        for (int j = 0; j < element_count; j++) {
            int num;
            source.read(reinterpret_cast<char*>(&num), sizeof(int));
            archive.write(reinterpret_cast<char*>(&num), sizeof(int));
            cout << num << " ";
        }
        cout << endl;
        
        source.close();
    }
    
    archive.close();
    cout << "\nАрхив " << archive_name << " успешно создан!" << endl;
    

    cout << "\n--- ПРОВЕРКА СОДЕРЖИМОГО АРХИВА ---\n";
    fstream check_archive(archive_name, ios::binary | ios::in);
    if (check_archive.is_open()) {
        int pos = 0;
        for (int i = 0; i < N; i++) {
            int size;
            check_archive.read(reinterpret_cast<char*>(&size), sizeof(int));
            cout << "Файл " << i+1 << " (размер " << size << "): ";
            
            for (int j = 0; j < size; j++) {
                int num;
                check_archive.read(reinterpret_cast<char*>(&num), sizeof(int));
                cout << num << " ";
            }
            cout << endl;
        }
        check_archive.close();
    }
    

}



int parse(const std::string& s, int& pos) {
    using namespace std;

    if (isdigit(s[pos])) {
        return s[pos++] - '0';
    }
    
    bool isMax = (s[pos] == 'M');
    pos += 2;
    
    int result = parse(s, pos);
    
    while (s[pos] == ',') {
        pos++;
        int value = parse(s, pos);
        if (isMax) result = max(result, value);
        else result = min(result, value);
    }
    
    pos++;
    return result;
}

int evaluate(const std::string& s) {
    int pos = 0;
    return parse(s, pos);
}

void task4(){
    using namespace std;


    string filename = "expression.bin";
    

    string expression = "M(5,m(3,8),2)";
    

    fstream outFile(filename, ios::binary | ios::out);
    int len = expression.length();
    outFile.write(reinterpret_cast<char*>(&len), sizeof(int));
    outFile.write(expression.c_str(), len);
    outFile.close();
    
    cout << "Записано в файл: " << expression << endl;
    

    fstream inFile(filename, ios::binary | ios::in);
    inFile.read(reinterpret_cast<char*>(&len), sizeof(int));
    
    char* buffer = new char[len + 1];
    inFile.read(buffer, len);
    buffer[len] = '\0';
    string readExpr(buffer);
    delete[] buffer;
    inFile.close();
    
    cout << "Прочитано из файла: " << readExpr << endl;
    
    // Вычисляем результат
    int result = evaluate(readExpr);
    cout << "Результат: " << result << endl;
    
}



