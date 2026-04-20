#include "module.h"
#include <iostream>
#include <string>
#include <vector>




Name::Name(const std::string&surname, const std::string&firstName,  const std::string&patronymic) : surname_(surname), firstName_(firstName),  patronymic_(patronymic) {}

const std::string& Name::getSurname() const {return surname_; }
const std::string& Name::getFirstName() const {return firstName_; }
const std::string& Name::getPatronymic() const {return patronymic_; }

void Name::setSurname(const std::string& surname){ surname_=surname;}
void Name::setFirstName(const std::string& firstName){firstName_=firstName;}
void Name::setPatronymic(const std::string&patronymic){patronymic_=patronymic;}

std::string Name::getFullName() const {
    std::string result;
    bool needSpace=false;
    if (!surname_.empty()){
        result+=surname_;
        needSpace=true;
    }
    if (!firstName_.empty()){
        if (needSpace) result += " ";
        result+=firstName_;
        needSpace=true;
    }
    if (!patronymic_.empty()){
        if (needSpace) result += " ";
        result+=patronymic_;
        needSpace=true;
    }
    return result;


}

void Name::print() const{
    std::cout<<getFullName()<<std::endl;
}


House::House(const int&floor) : floor_(floor){}

std::string House::getCounterFloor() const{
    std::string ending;
    
    if (floor_%10!=1 || floor_==11){
        ending=" этажами";
        
    }
    else ending=" этажом";
    return "дом с "+std::to_string(floor_)+ending;
}

void House::setFloor(const int&floor){ floor_=floor; }

void House::print() const{
    std::cout<<getCounterFloor()<<std::endl;
}

void task1(){
    std::cout << "Имена"<<std::endl;
    Name n1("", "Клеопатра", "");
    Name n2("Пушкин", "Александр", "Сергеевич");
    Name n3("Маяковский", "Владимир", "");
    
    n1.print(); 
    n2.print(); 
    n3.print();
    std::cout<<std::endl;
    std::cout << "Дома"<<std::endl;
    House h1(1), h5(5), h23(23);
    h1.print(); 
    h5.print(); 
    h23.print();
}

Employee::Employee(const std::string& name) : name_(name), department_(nullptr){}

void Employee::setDepartment(Department* dept){department_=dept;}
std::string Employee::getName() const { return name_; }
Department* Employee::getDepartment() const { return department_; }


Department::Department(const std::string& name) : name_(name), manager_(nullptr) {}

void Department::setManager(Employee* emp) { manager_ = emp; }

std::string Department::getName() const { return name_; }
Employee* Department::getManager() const { return manager_; }

std::string Employee::toString() const {
    if (!department_) return name_ + " (без отдела)";
    
    Employee* mgr = department_->getManager();
    if (mgr == this) {
        return name_ + " начальник отдела " + department_->getName();
    }
    
    std::string mgrName;
    if (mgr != nullptr) {
        mgrName = mgr->getName();
    } else {
        mgrName = "не назначен";
    }
    return name_ + " работает в отделе " + department_->getName() + 
           ", начальник которого " + mgrName;
}

void Employee::print() const {std::cout<<toString()<<std::endl; }


void task2(){

    Department it("IT");
    Employee petrov("Петров");
    Employee kozlov("Козлов");
    Employee sidorov("Сидоров");

    petrov.setDepartment(&it);
    kozlov.setDepartment(&it);
    sidorov.setDepartment(&it);


    it.setManager(&kozlov);

    std::cout<<"Вывод сотрудников"<<std::endl;
    petrov.print();
    kozlov.print();
    sidorov.print();

}

EmployeeUpdate::EmployeeUpdate(const std::string& name) 
    : name_(name),department_(nullptr) {}

void EmployeeUpdate::setDepartment(DepartmentUpdate* dept) {
    department_ =dept;
    if (dept) {
        dept->addEmployee(this); 
    }
}

DepartmentUpdate* EmployeeUpdate::getDepartment()const { return department_; }
std::string EmployeeUpdate::getName() const{ return name_; }

std::vector<EmployeeUpdate*> EmployeeUpdate::getColleagues()const {
    if (!department_) return {};
    return department_->getEmployees(); 
}

std::string EmployeeUpdate::toString() const {
    if (!department_) return name_ + " (без отдела)";
    
    EmployeeUpdate* mgr = department_->getManager();
    if (mgr == this) {
        return name_ + " начальник отдела " + department_->getName();
    }
    
    std::string mgrName = mgr ? mgr->getName() : "не назначен";
    return name_ +" работает в отделе "+ department_->getName()+ 
           ", начальник которого "+ mgrName;
}

void EmployeeUpdate::print() const { 
    std::cout << toString() << "\n"; 
}


DepartmentUpdate::DepartmentUpdate(const std::string& name) : name_(name), manager_(nullptr) {}

void DepartmentUpdate::setManager(EmployeeUpdate* emp) { manager_ = emp; }

void DepartmentUpdate::addEmployee(EmployeeUpdate* emp) {
    for (const auto& e : employees_) {
        if (e == emp) return; 
    }
    employees_.push_back(emp);
}

EmployeeUpdate* DepartmentUpdate::getManager() const { return manager_; }
const std::vector<EmployeeUpdate*>& DepartmentUpdate::getEmployees() const { return employees_; }
std::string DepartmentUpdate::getName() const { return name_; }

void task3(){
    DepartmentUpdate it("IT");
    EmployeeUpdate petrov("Петров");
    EmployeeUpdate kozlov("Козлов");
    EmployeeUpdate sidorov("Сидоров");

    
    petrov.setDepartment(&it);
    kozlov.setDepartment(&it);
    sidorov.setDepartment(&it);

    
    it.setManager(&kozlov);

    std::cout << "Вывод всех сотрудников "<<std::endl;
    petrov.print();
    kozlov.print();
    sidorov.print();

    std::cout<<std::endl;
    std::cout << "Коллеги Козлова "<<std::endl;
    const auto& team = kozlov.getColleagues();
    for (const auto& emp : team) {
        std::cout << " - "<<emp->getName() << "\n";
    }
}

NameUpdate::NameUpdate(const std::string& first, const std::string& surname, const std::string& patronymic): first_name_(first), surname_(surname), patronymic_(patronymic) {}


NameUpdate::NameUpdate(const std::string& first, const std::string& surname): NameUpdate(first, surname, "") {}

NameUpdate::NameUpdate(const std::string& first): NameUpdate(first, "", "") {}

const std::string& NameUpdate::getFirstName() const {return first_name_;}
const std::string& NameUpdate::getSurname()const {return surname_;}
const std::string& NameUpdate::getPatronymic() const {return patronymic_;}

void NameUpdate::setFirstName(const std::string& first) {first_name_=first; }
void NameUpdate::setSurname(const std::string& surname) {surname_=surname; }
void NameUpdate::setPatronymic(const std::string& patronymic) {patronymic_=patronymic; }


std::string NameUpdate::getFullName() const {
    std::string result;
    bool need_space=false;
    
    if (!surname_.empty()) {
        result += surname_;
        need_space = true;
    }
    if (!first_name_.empty()) {
        if (need_space) result += " ";
        result += first_name_;
        need_space = true;
    }
    if (!patronymic_.empty()) {
        if (need_space) result +=" ";
        result+=patronymic_;
    }
    return result;
}

void NameUpdate::print() const {
    std::cout<<getFullName()<<std::endl;
}

void task4(){
    NameUpdate n1("Клеопатра");
    NameUpdate n2("Александр", "Пушкин", "Сергеевич");
    NameUpdate n3("Владимир", "Маяковский");
    NameUpdate n4("Христофор", "Бонифатьевич");

    std::cout << "Вывод имён"<<std::endl;
    std::cout << "1. "; n1.print();
    std::cout << "2. "; n2.print();
    std::cout << "3. "; n3.print();
    std::cout << "4. "; n4.print();

}

Fraction::Fraction(int numerator, int denominator) : numerator_(numerator), denominator_(denominator) {
    if (denominator_ == 0) throw std::invalid_argument("Знаменатель не может быть равен нулю");
    simplify();
}

int Fraction::getNumerator() const{return numerator_; }
int Fraction::getDenominator() const  {return denominator_; }

std::string Fraction::toString() const {
    return std::to_string(numerator_) + "/" + std::to_string(denominator_);
}

void Fraction::print() const { std::cout << toString() << "\n"; }

// Сложение
Fraction Fraction::sum(const Fraction& other) const {
    int n = numerator_ *other.denominator_ + other.numerator_ *denominator_;
    int d = denominator_ *other.denominator_;
    return Fraction(n, d); 
}
Fraction Fraction::sum(int val) const { return sum(Fraction(val, 1)); }


Fraction Fraction::minus(const Fraction& other) const {
    int n = numerator_ *other.denominator_ - other.numerator_ *denominator_;
    int d = denominator_ *other.denominator_;
    return Fraction(n, d);
}
Fraction Fraction::minus(int val) const { return minus(Fraction(val, 1)); }


Fraction Fraction::multiply(const Fraction& other) const {
    return Fraction(numerator_ * other.numerator_, denominator_ * other.denominator_);
}
Fraction Fraction::multiply(int val) const {return Fraction(numerator_ * val, denominator_); }


Fraction Fraction::div(const Fraction& other) const {
    if (other.numerator_ == 0) throw std::invalid_argument("Деление на нулевую дробь");
    return Fraction(numerator_ * other.denominator_, denominator_ * other.numerator_);
}
Fraction Fraction::div(int val) const {
    if (val == 0) throw std::invalid_argument("Деление на ноль");
    return Fraction(numerator_, denominator_ * val);
}

void task5(){
    Fraction f1(1, 3);
    Fraction f2(2, 3);
    Fraction f3(3, 4);
    Fraction f4(5, 2);

    std::cout << "Примеры использования методов"<<std::endl;

    std::cout<<f1.toString()<<" + "<<f2.toString() << " = "<<f1.sum(f2).toString()<<std::endl;
    std::cout<<f2.toString()<<" - "<<f3.toString() << " = "<<f2.minus(f3).toString()<<std::endl;
    std::cout<<f1.toString()<<" * "<<f2.toString() << " = "<<f1.multiply(f2).toString()<<std::endl;
    std::cout<<f2.toString()<<" / "<<f3.toString() << " = "<<f2.div(f3).toString()<<std::endl;
    
    std::cout<<std::endl;

    std::cout<< "Операции с целым числом"<<std::endl;
    std::cout<<f4.toString()<<" + 2 = "<<f4.sum(2).toString()<<std::endl;
    std::cout<<f4.toString()<<" - 1 = "<<f4.minus(1).toString()<<std::endl;
    std::cout<<f4.toString()<<" * 3 = "<<f4.multiply(3).toString()<<std::endl;
    std::cout<<f4.toString()<<" / 2 = "<<f4.div(2).toString()<<std::endl;

    std::cout<<std::endl;
    std::cout << "Цепочка: f1.sum(f2).div(f3).minus(5)"<<std::endl;
    Fraction result = f1.sum(f2).div(f3).minus(5);
    std::cout << "Результат: ";
    result.print();
}