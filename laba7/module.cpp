#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <vector>
#include <iomanip>
#include "module.h"
#include <algorithm>
#include <map>
#include <climits>





void sort8() {

    using namespace std;
    int N;
    cout << "Введите количество элементов N: ";
    cin >> N;
    
    vector<int> arr(N);
    
    cout << "Введите " << N << " целых чисел: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    ofstream outFile("sort_protocol.txt");
    if (!outFile) {
        cerr << "Не удалось открыть файл для записи!" << endl;
        return;
    }
    
    outFile << "Начальный массив: ";
    for (int num : arr) {
        outFile << num << " ";
    }
    outFile << endl << "Протокол сортировки по убыванию:" << endl;
    

    for (int i = 0; i < N - 1; i++) {

        int maxIndex = i;
        for (int j = i + 1; j < N; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        
     
        if (maxIndex != i) {
            swap(arr[i], arr[maxIndex]);
        }
  
        outFile << "Итерация " << (i + 1) << ": ";

        for (int k = 0; k <= i; k++) {
            outFile << arr[k] << " ";
        }

        outFile << "| ";

        for (int k = i + 1; k < N; k++) {
            outFile << arr[k] << " ";
        }
        outFile << endl;
    }
   
    outFile << endl << "Отсортированный массив: ";
    for (int num : arr) {
        outFile << num << " ";
    }
    outFile << endl;

    cout << endl << "Массив отсортирован." << endl;
    cout << "Отсортированный массив: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    outFile.close();
    

}



bool compareStudents(const Student& a, const Student& b) {
    
    using namespace std;
    if (a.score != b.score) {
        return a.score < b.score;
    }
    return a.surname < b.surname;
}


void shellSort(std::vector<Student>& students) {
    using namespace std;
    int n = students.size();
    
    // Последовательность gap (расстояний) для сортировки Шелла
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            Student temp = students[i];
            int j;
            for (j = i; j >= gap && compareStudents(temp, students[j - gap]); j -= gap) {
                students[j] = students[j - gap];
            }
            students[j] = temp;
        }
    }
}

void Five13() {
    using namespace std;
    ifstream inputFile("Five13.txt");
    ofstream outputFile("Five13_sorted.txt");
    
    if (!inputFile.is_open()) {
        cout << "Ошибка открытия входного файла!" << endl;
        return;
    }
    
    if (!outputFile.is_open()) {
        cout << "Ошибка создания выходного файла!" << endl;
        inputFile.close();
        return;
    }
    
    vector<Student> students;
    Student temp;
    
 
    while (inputFile >> temp.surname >> temp.score) {
        students.push_back(temp);
    }
    
 
    shellSort(students);
    

    outputFile << left << "Фамилия" <<string(8, ' ')<<"| "<<right << setw(3) << "Балл" << endl;
    outputFile << string(18, '-') << endl;

    for (const auto& student : students) {


        if (student.score>100 || student.score<0){
            int spaces=(15-(student.surname.length())/2);
            outputFile<< student.surname<<string(spaces, ' ') ;
            outputFile<< "|"<<right<<setw(3)<<"ERR"<<endl;

        }
        else{
            int spaces=(15-(student.surname.length())/2);
            outputFile<< student.surname<<string(spaces, ' ') ;
            outputFile<< "|"<<right<<setw(3)<<student.score<<endl;
        }

    }
    
    cout << "Данные успешно отсортированы и сохранены в файл Five13_sorted.txt" << endl;
    cout << "Обработано " << students.size() << " записей." << endl;
    
    inputFile.close();
    outputFile.close();

}









bool compareYearResults(const YearResult& a, const YearResult& b) {
    using namespace std;

    if (a.minDuration != b.minDuration) 
        return a.minDuration < b.minDuration;
    return a.year < b.year;
}

void ExamTaskC16() {
    using namespace std;

    ifstream inputFile("ExamTaskC16.txt");
    
    if (!inputFile.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }
    
    int K, N;
    inputFile >> K >> N;
    
    // Вектор для хранения отфильтрованных записей
    vector<Record> records;
    
    // Считываем и фильтруем записи
    for (int i = 0; i < N; i++) {
        int duration, code, year, month;
        inputFile >> duration >> code >> year >> month;
        
        if (code == K && duration > 0) {
            records.push_back({duration, year, month});
        }
    }
    
    inputFile.close();
    
    if (records.empty()) {
        cout << "Нет данных" << endl;
        return;
    }
    
    // Создаем вектор для хранения уникальных годов
    vector<int> years;
    
    // Находим уникальные годы
    for (const auto& record : records) {
        bool found = false;
        for (int year : years) {
            if (year == record.year) {
                found = true;
                break;
            }
        }
        if (!found) {
            years.push_back(record.year);
        }
    }
    
    // Сортируем года по возрастанию
    sort(years.begin(), years.end());
    
    // Вектор для результатов
    vector<YearResult> results;
    
    // Для каждого года находим минимальную продолжительность
    for (int year : years) {
        int minDuration = INT_MAX;
        int bestMonth = -1;
        
        // Проходим по всем записям и ищем минимальную продолжительность для данного года
        for (const auto& record : records) {
            if (record.year == year) {
                if (record.duration < minDuration) {
                    minDuration = record.duration;
                    bestMonth = record.month;
                } else if (record.duration == minDuration && record.month > bestMonth) {
                    bestMonth = record.month;
                }
            }
        }
        
        // Добавляем результат, если нашли данные для этого года
        if (minDuration != INT_MAX) {
            results.push_back({minDuration, year, bestMonth});
        }
    }
    
    // Сортируем результаты согласно требованиям
    sort(results.begin(), results.end(), compareYearResults);
    
    // Выводим результаты
    for (const auto& result : results) {
        cout << result.minDuration << " " << result.year << " " << result.month << endl;
    }
}