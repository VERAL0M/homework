#ifndef MODULE_H
#define MODULE_H
#include <string>

struct fitnes_center
{
    int month;
    int year;
    int hours;
    int code;
    
};
struct Student
{
    
    std::string surname;
    std::string name;
    int student_class;
    union info_spec
    {
        short int reading_speed;
        float point;
        short int mark;
    } info;

};
void task2();

struct Book{
    std::string name;
    std::string author;
    int year;

};
void task3();
void append_book();
void show_library();
void find_author();
void find_name();
void examtask4();
#endif 