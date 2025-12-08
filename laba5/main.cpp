#include <iostream>
#include <ctime>
#include <locale>
#include <string>

using namespace std;

wstring random_string(wstring russian_letters){
    int len_word;
    wstring word=L"";
    wcout<<L"Введите длину слова: ";
    wcin>>len_word;
    srand(time(0));
    int index;

    for (int i=0; i<len_word; i++){
        index = rand()%34;
        word+=russian_letters[index];
    }

    return word;
}

int main(){
    // Настройка локали для широких символов
    setlocale(LC_ALL, "");
    wcout.imbue(locale(""));
    wcin.imbue(locale(""));
    
    wstring word;
    word = random_string(L"ЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭ ЯЧСМИТЬБЮЁ");
    wcout<<word << endl;
    
    return 0;
}