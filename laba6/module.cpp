#include <iostream>
#include <fstream>
#include <string>
#include "module.h"
#include <iomanip>




void examtask4(){
    using namespace std;
    ifstream database("1.txt");
    int count_client;
    database>>count_client;
    int min_hours=1;
    int need_month, need_year;
    fitnes_center fitnes;
    for (int i=1; i<=count_client; i++){
        int month, year, code, hours;

        database>>fitnes.month>>fitnes.year>>fitnes.code>>fitnes.hours;
        if (fitnes.month>12 || fitnes.month<=0 || fitnes.year<2000 || fitnes.year>2010 || fitnes.hours>30 || fitnes.hours<1){
            cout<<"Не вернные входные данные, строка не будет рассматриваться"<<endl;
            break;
        }
        
        if (min_hours<=fitnes.hours){
            min_hours=fitnes.hours;
            need_month=fitnes.month;
            need_year=fitnes.year;
        }
    }
    cout<<"Максимальная продолжительность занятий: "<<min_hours<<" часов "<<"Год: "<<need_year<<" "<<"Месяц: "<<need_month<<endl;
    database.close();
};


void task2(){
    using namespace std;

    Student student;
    int n; 
    cout<<"Введите кол-во учеников: ";
    cin>>n;
    ofstream student_base("2.txt", std::ios::out);

    if (!student_base) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }


    for(int i=0; i<n; i++){
        cout<<"Фамилия: ";
        cin>>student.surname;
        
        cout<<"Имя: ";
        cin>>student.name;
        cout<<"Класс: ";
        cin>>student.student_class;
        student_base<<student.surname<<"\t"<<student.name<<"\t"<<student.student_class<<"\t";
        if (student.student_class==1){
            cout<<"Введите скорость чтения ученика: ";
            cin>>student.info.reading_speed;

            student_base<<student.info.reading_speed;
 
        }
        
        if (student.student_class==4){
            cout<<"Введите результаты итоговой атестации: ";
            cin>>student.info.point;
            if (student.info.point<1 || student.info.point>100){
                cout<<"Результат итоговой атестации превышает диапазон допустимых значений"<<endl;
                break;
            }
            else{
                student_base<<student.info.point;
            }
        }
        
        if (student.student_class==3 || student.student_class==2){
            cout<<"Введите результаты контрольной по математике: ";
            cin>>student.info.mark;
            if (student.info.mark<1 || student.info.mark>10){
                cout<<"Результат контрольной по математике превышает диапазон допустимых значений"<<endl;
                break;
            }
            else{
                student_base<<student.info.mark;
            }
            
        }
        student_base<<endl;

    }
    student_base.close();
    cout << "\n\n=== ТАБЛИЦА СТУДЕНТОВ ===\n" << endl;
    
    ifstream file("2.txt");
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }
    

    cout << "+---------------------+---------------+---------+-------------------------+" << endl;
    cout << "| Фамилия             | Имя           | Класс   | Результат              |" << endl;
    cout << "+---------------------+---------------+---------+-------------------------+" << endl;
    
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        
        size_t pos1 = line.find('\t');
        size_t pos2 = line.find('\t', pos1 + 1);
        size_t pos3 = line.find('\t', pos2 + 1);
        
        if (pos1 != string::npos && pos2 != string::npos && pos3 != string::npos) {
            cout << "| " << left << setw(20) << line.substr(0, pos1)
                 << "| " << setw(14) << line.substr(pos1 + 1, pos2 - pos1 - 1)
                 << "| " << setw(8) << line.substr(pos2 + 1, pos3 - pos2 - 1)
                 << "| " << setw(24) << line.substr(pos3 + 1)
                 << "|" << endl;
        }
    }
    
    cout << "+---------------------+---------------+---------+-------------------------+" << endl;
    
    file.close();
}


void append_book(){
    using namespace std;
    Book book;

    ofstream library("book.txt", std::ios::app);
    cout<<"Введите название книги: ";
    cin>>book.name;
    cout<<"Введите имя автора: ";
    cin>>book.author;
    cout<<"Год издания: ";
    cin>>book.year;
    library<<book.name<<"\t"<<book.author<<"\t"<<book.year<<endl;
    
    library.close();
}
void show_library(){
    using namespace std;
    ifstream file("book.txt");
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }
    string line;
    while (getline(file, line))
    {
        cout<<line<<endl;
    }

}
void find_author(){
    using namespace std;
    string author;
    int count=0;
    cout<<"Введите автора ";
    cin>>author;
    ifstream file("book.txt");
        if (!file.is_open()) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }
    string line;
    while (getline(file, line))
    {
        if (line.empty()) continue;
        size_t pos1= line.find('\t');
        size_t pos2= line.find('\t', pos1+1);
        
        if (pos1 != string::npos && pos2 != string::npos) {
        string name = line.substr(pos1+1, pos2-pos1-1);
    
            if (name==author){
                count=1;
                cout<<"Вот что удалось найти: ";
                cout<<line<<endl;
            }
            if (count==0){
                cout<<"Ничего не найдено по вашему запросу("<<endl;
            }
        }
    }
}
void find_name(){
    using namespace std;
    int count=0;
    string find_book;
    cout<<"Введите название книги, которую нужно найти: ";
    cin>>find_book;
    ifstream file("book.txt");
        if (!file.is_open()) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }
    string line;
    while (getline(file, line))
    {
        if (line.empty()) continue;
        size_t pos1= line.find('\t');
        if (pos1 == string::npos) continue;

        string name = line.substr(0, pos1);
        if (name.find(find_book) != string::npos){
            count=1;
            cout<<"Вот что удалось найти: ";
            cout<<line<<endl;
        }
        if (name.find(find_book) == string::npos && count==0){
            cout<<"Ничего не найдено по вашему запросу("<<endl;
        }
    }


}
void task3(){
    using namespace std;


    int n;
    cout<<"Выберите режим работы"<<endl;
    cout<<"1. Добавление книги"<<endl;
    cout<<"2. Вывод инфрмации о книгах"<<endl;
    cout<<"3. Поиск по автору"<<endl;
    cout<<"4. Поиск по частичному совпадению заголовка"<<endl;
    cout<<"0. Выход"<<endl;
    cin>>n;


    switch (n)
    {
    case 1:
        append_book();
        task3();
            
        break;
    case 2:
        show_library();
        task3();
        break;
    case 3: 
        find_author();
        task3();
        break;
    case 4:
        find_name();
        task3();
        break;
    case 0:
        break;
    default:
        break;
    }


    }
    
