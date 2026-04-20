#ifndef MODULE_H
#define MODULE_H
#include <vector>
#include <string>
#include <cmath>
#include <stdexcept>

class Name{
private:
    std::string surname_;
    std::string firstName_;
    std::string patronymic_;

public: 
    Name(const std::string& surname="",
         const std::string& firstName="",
         const std::string& patronymic="");

    const std::string& getSurname() const;
    const std::string& getFirstName() const;
    const std::string& getPatronymic() const;

    void setSurname(const std::string& surname);
    void setFirstName(const std::string& firstName);
    void setPatronymic(const std::string& patronymic); 

    std::string getFullName() const;
    
    void print() const;
};

class House{
private:
    int floor_;

public:
    House(const int& floor=0);

    std::string getCounterFloor() const;

    void setFloor(const int&floor);
    void print() const;

};



class Department;

class Employee{
private:
    std::string name_;
    Department* department_;
public:
    Employee(const std::string& name);
    void setDepartment(Department* dept);

    Department* getDepartment() const;
    std::string getName() const;
    
    std::string toString() const;
    void print() const;


};

class Department {
private:
    std::string name_;
    Employee* manager_; 

public:
    Department(const std::string& name);
    void setManager(Employee* emp);
    
    std::string getName() const;
    Employee* getManager() const;
};




class DepartmentUpdate;


class EmployeeUpdate {
private:
    std::string name_;
    DepartmentUpdate* department_;

public:
    EmployeeUpdate(const std::string& name);
    
    void setDepartment(DepartmentUpdate* dept);
    DepartmentUpdate* getDepartment() const;
    std::string getName() const;
    

    std::vector<EmployeeUpdate*> getColleagues() const;
    
    std::string toString() const;
    void print() const;
};


class DepartmentUpdate {
private:
    std::string name_;
    EmployeeUpdate* manager_;
    std::vector<EmployeeUpdate*> employees_; 

public:
    DepartmentUpdate(const std::string& name);
    
    void setManager(EmployeeUpdate* emp);
    void addEmployee(EmployeeUpdate* emp);
    
    EmployeeUpdate* getManager() const;
    
    const std::vector<EmployeeUpdate*>& getEmployees() const; 
    std::string getName() const;
};

#endif 


#include <iostream>
#include <string>

class NameUpdate {
private:
    std::string first_name_;
    std::string surname_;
    std::string patronymic_;

public:
    
    NameUpdate(const std::string& first);
    NameUpdate(const std::string& first, const std::string& surname);
    NameUpdate(const std::string& first, const std::string& surname, const std::string& patronymic);

    
    const std::string& getFirstName() const;
    const std::string& getSurname() const;
    const std::string& getPatronymic() const;

    
    void setFirstName(const std::string& first);
    void setSurname(const std::string& surname);
    void setPatronymic(const std::string& patronymic);

    
    std::string getFullName() const;
    void print() const;
};



class Fraction {
private:
    int numerator_;
    int denominator_;

    
    static int gcd(int a, int b) {
        a = std::abs(a); b = std::abs(b);
        while (b) { int t = b; b = a % b; a = t; }
        return a;
    }
    void simplify() {
        if (denominator_ == 0) return;
        int common = gcd(numerator_, denominator_);
        numerator_ /= common;
        denominator_ /= common;
        
        if (denominator_ < 0) {
            denominator_ = -denominator_;
            numerator_ = -numerator_;
        }
    }

public:
    
    Fraction(int numerator, int denominator);
    
    
    int getNumerator() const;
    int getDenominator() const;
    
    
    std::string toString() const;
    void print() const;
    
    
    Fraction sum(const Fraction& other) const;
    Fraction sum(int val) const;
    Fraction minus(const Fraction& other) const;
    Fraction minus(int val) const;
    Fraction multiply(const Fraction& other) const;
    Fraction multiply(int val) const;
    Fraction div(const Fraction& other) const;
    Fraction div(int val) const;
};

void task1();
void task2();
void task3();
void task4();
void task5();