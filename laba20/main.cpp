#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
using namespace std;

class Money{
private:
    unsigned int rubles;
    short int kopeks;
    
    void normalMoney(){
        if (kopeks >= 100) {
            rubles += kopeks / 100;
            kopeks %= 100;
        } else if (kopeks < 0) {
            long long total = static_cast<long long>(rubles) * 100 + kopeks;
            if (total < 0) total = 0;
            rubles = static_cast<unsigned int>(total / 100);
            kopeks = static_cast<short int>(total % 100);
        }
    }

public:
    Money(): rubles(0), kopeks(0){}
    Money(unsigned int rub, short int kop) : rubles(rub), kopeks(kop) {
        normalMoney();
    }
    Money(const Money& other) : rubles(other.rubles), kopeks(other.kopeks) {}

    ~Money()=default;
    unsigned int getRubles() const{
        return rubles;
    }
    short int getkopeks() const{
        return kopeks;
    }
    void setRubles(unsigned int r) {
        rubles = r;
        normalMoney(); 
    }

    void setKopeks(short int k) {
        kopeks = k;
        normalMoney();
    }
    Money subtract(const Money& other) const{
  
        long long thisTotal = static_cast<long long>(rubles)*100+kopeks;
        long long otherTotal = static_cast<long long>(other.rubles)*100+other.kopeks;
        long long diff =thisTotal-otherTotal;
        if (diff<0){
            cout<<"Недостаточно средств. Вам ещё не хватает: "<<diff*(-1)<<" копеек";
            return Money(0, 0);

        }
        else{
            return Money(static_cast<unsigned int>(diff / 100), static_cast<short int>(diff % 100));
        }
    }
    friend ostream& operator<<(ostream& os, const Money& m) {
        os << m.rubles << "." << setw(2) << setfill('0') << m.kopeks << " руб.";
        return os;
    }

    Money& operator++() {
        ++kopeks;
        normalMoney();
        return *this;
    }

    Money operator++(int) { 
        Money temp = *this; 
        ++(*this);          
        return temp;       
    }
    Money& operator--() {
        --kopeks;
        normalMoney(); 
        return *this;
    }
    Money operator--(int) {
        Money temp = *this;
        --(*this);
        return temp;
    }


    explicit operator unsigned int() const { return rubles; }
    

    operator double() const { return rubles + kopeks / 100.0; }

    Money operator+(unsigned int kopeksToAdd) const {
        long long total=static_cast<long long>(rubles)*100+kopeks + kopeksToAdd;
        return Money(static_cast<unsigned int>(total / 100), static_cast<short int>(total % 100));
    }
    Money operator-(unsigned int kopeksToSub) const {
        long long total=static_cast<long long>(rubles)*100+kopeks -kopeksToSub;
        if (total < 0) { cerr <<"Отрицательный результат. Возврат 0.00\n"; return Money(0,0); }
        return Money(static_cast<unsigned int>(total / 100), static_cast<short int>(total % 100));
    }
};



int main() {
    cout << "=== ТЕСТЫ ===\n";


    Money m1;          
    Money m2(150, 250);    
    Money m3(m2);          

    cout<<"Конструктор по умолчанию: "<< m1<<"\n";
    cout<<"Параметризированный (150, 250): "<<m2<<"\n";
    cout<<"Конструктор копирования: "<< m3<<"\n\n";


    cout << "--- Тест сеттеров ---\n";
    m1.setKopeks(-30);
    cout << "setKopeks(-30): "<<m1<<" (ожидалось 0.70, т.к. 'взят' 1 рубль)\n";

    m1.setRubles(10);
    m1.setKopeks(120);
    cout << "setRubles(10) + setKopeks(120): "<<m1<<" (ожидалось 11.20)\n\n";


    cout << "--- Тест вычитания ---\n";
    Money a(100, 0);
    Money b(50, 99);
    cout << a << " - " << b << " = " << a.subtract(b) << "\n"; 
    cout << b << " - " << a << " = " << b.subtract(a) << "\n"; 
    cout << a << " - " << a << " = " << a.subtract(a) << "\n"; 


    cout << "=== ТЕСТЫ НОВЫХ ОПЕРАТОРОВ ===\n\n";

    Money m(5, 75); 
    cout << "Исходный объект: " << m << "\n\n";


    cout << "--- Тест ++ и -- ---\n";
    ++m; cout << "++m:      " << m << "\n"; 
    m++; cout << "m++:      " << m << "\n"; 
    --m; cout << "--m:      " << m << "\n"; 
    m--; cout << "m--:      " << m << "\n"; 

    Money zero(0, 0);
    --zero; cout << "--0.00:   " << zero << " (защита от отрицательного)\n\n";


    cout << "--- Тест приведения типов ---\n";
    unsigned int r = static_cast<unsigned int>(m); 
    cout << "static_cast<unsigned int>(m): " << r << " (рубли)\n";
    
    double d = m; 
    cout << "Неявное double m:           " << fixed << setprecision(2) << d << " (копейки в рублях)\n\n";


    cout << "--- Тест бинарных операторов ---\n";
    cout << m << " + 50 коп. = " << m + 50 << "\n";
    cout << m << " - 20 коп. = " << m - 20 << "\n";
    cout << m << " - 9999 коп.= " << m - 9999 << "\n"; 


    cout << "\n--- Комплексный пример ---\n";
    Money wallet(10, 50);
    wallet = wallet + 25; 
    ++wallet;            
    cout << "Итог: " << wallet << "\n";


    return 0;
}