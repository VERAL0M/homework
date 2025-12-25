#ifndef MODULE_H
#define MODULE_H
#include <string>
#include <vector>

struct Student {
    std::string surname;
    int score;
};

struct TrainingRecord {
    int duration;     
    int clientCode;    
    int year;          
    int month;         
};

// Структура для хранения результата по году
struct YearResult {
    int minDuration;   
    int year;         
    int month;         
};

void sort8();
void Five13();
void ExamTaskC16();
void shellSort(std::vector<Student>& students);
bool compareStudents(const Student& a, const Student& b);


#endif 