#include <iostream>
#include <fstream>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "module.h"


#include <algorithm>
#include <map>
#include <climits>
#include <string>

// #include <algorithm>




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
    
    // Сортировка методом простого выбора
    for (int i = 0; i < N - 1; i++) {
        // Находим максимальный элемент в неотсортированной части
        int maxIndex = i;
        for (int j = i + 1; j < N; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        
        // Обменяем найденный максимальный элемент с элементом на позиции i
        if (maxIndex != i) {
            swap(arr[i], arr[maxIndex]);
        }
        
        // Вывод текущего состояния массива в файл
        outFile << "Итерация " << (i + 1) << ": ";
        
        // Выводим отсортированную часть
        for (int k = 0; k <= i; k++) {
            outFile << arr[k] << " ";
        }
        
        // Разделитель
        outFile << "| ";
        
        // Выводим неотсортированную часть
        for (int k = i + 1; k < N; k++) {
            outFile << arr[k] << " ";
        }
        outFile << endl;
    }
    
    // Вывод окончательного результата
    outFile << endl << "Отсортированный массив: ";
    for (int num : arr) {
        outFile << num << " ";
    }
    outFile << endl;
    
    // Также выведем результат на экран
    cout << endl << "Массив отсортирован. Протокол сохранен в файле 'sort_protocol.txt'" << endl;
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
    

    outputFile << left << setw(15) << "Фамилия" << right << setw(3) << "Балл" << endl;
    outputFile << string(18, '-') << endl;
    
    for (const auto& student : students) {

        if (student.score>100 || student.score<0){
                outputFile << left << setw(15) << student.surname 
                   << right << setw(3) << "Баллы не соответсвуют допустимым значениям от 0 до 100" << endl;

        }
        else{
            outputFile << left << setw(15) << student.surname 
                   << right << setw(3) << student.score << endl;
        }

    }
    
    cout << "Данные успешно отсортированы и сохранены в файл Five13_sorted.txt" << endl;
    cout << "Обработано " << students.size() << " записей." << endl;
    
    inputFile.close();
    outputFile.close();

}









bool compareYearResults(const YearResult& a, const YearResult& b) {
    using namespace std;
    if (a.minDuration != b.minDuration) return a.minDuration < b.minDuration;
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
    
    // Векторы для группировки по годам
    vector<int> years;  // список уникальных годов
    vector<vector<pair<int, int>>> recordsByYear;  // записи для каждого года
    
    for (int i = 0; i < N; i++) {
        int duration, code, year, month;
        inputFile >> duration >> code >> year >> month;
        
        if (code == K && duration > 0) {
            // Ищем год в векторе years
            int yearIndex = -1;
            for (int j = 0; j < years.size(); j++) {
                if (years[j] == year) {
                    yearIndex = j;
                    break;
                }
            }
            
            if (yearIndex == -1) {
                // Новый год - добавляем
                years.push_back(year);
                recordsByYear.push_back({{duration, month}});
            } else {
                // Существующий год - добавляем запись
                recordsByYear[yearIndex].push_back({duration, month});
            }
        }
    }
    
    inputFile.close();
    
    if (years.empty()) {
        cout << "Нет данных" << endl;
        return;
    }
    
    vector<YearResult> results;
    
    // Обрабатываем каждый год
    for (int i = 0; i < years.size(); i++) {
        int year = years[i];
        const auto& records = recordsByYear[i];
        
        int minDuration = INT_MAX;
        int bestMonth = -1;
        
        for (const auto& record : records) {
            int duration = record.first;
            int month = record.second;
            
            if (duration < minDuration) {
                minDuration = duration;
                bestMonth = month;
            } else if (duration == minDuration && month > bestMonth) {
                bestMonth = month;
            }
        }
        
        YearResult result;
        result.minDuration = minDuration;
        result.year = year;
        result.month = bestMonth;
        results.push_back(result);
    }
    
    sort(results.begin(), results.end(), compareYearResults);
    
    for (const auto& result : results) {
        cout << result.minDuration << " " << result.year << " " << result.month << endl;
    }
    

}