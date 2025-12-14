#include <iostream>
#include <locale>
#include <cwchar>
#include <string>
#include <cwctype>
#include <vector>
#include <cmath>
#include <ctime>
#include <fstream>
#include <string>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <sstream>

#include <iostream>
#include <fstream>
#include <string>
#include <locale>

std::wstring file_word() {
    std::setlocale(LC_ALL, "");
    
    std::string filename;
    std::wcout << L"Введите имя файла: ";
    
    std::wstring wfilename;
    std::wcin >> wfilename;
    
    // Конвертация wstring в string
    filename = std::string(wfilename.begin(), wfilename.end());
    
    std::wifstream file(filename);
    if (!file) return L"";
    
    std::wstring word;
    std::getline(file, word);
    return word;
}
std::wstring generator(int n) {
    using namespace std;
    wstring alpha = L"йцукенгшщзхъфывапролджэячсмитьбюё";
    wstring new_word;
    
    for (int i = 0; i < n; i++) {
        int index = rand() % alpha.size();
        new_word += alpha[index];
    }
    return new_word;
}

std::wstring generator_num(int n) {
    using namespace std;
    wstring alpha = L"1234567890AB";
    wstring new_word;
    
    for (int i = 0; i < n; i++) {
        int index = rand() % alpha.size();
        new_word += alpha[index];
    }
    return new_word;
}
void string48(){
    using namespace std;
    wstring word;

    
    int n;
    wcout<<L"Выберите режим"<<endl;
    wcout<<L"1. Ручной ввод"<<endl;
    wcout<<L"2. Случайна генерация"<<endl;
    wcout<<L"3. Из файла"<<endl;
    wcin>>n;


    switch (n)
    {
    case 1:
        wcout << L"Введите текст: ";
        wcin.ignore();
        getline(wcin, word);
        
        break;

    case 2:{
        int l;
        wcout<<L"Введите длину слова";
        wcin>>l;

        word=generator(l);
        wcout<<word;
        break;

    }
    case 3:{
        word=file_word();
    }
    
    default:
        break;
    }


    if (word.empty()) {
        std::wcout << L"Введена пустая строка" << endl;
        return;
    }

    wchar_t first_letter = word[0];
    std::wstring result = word;
    

    for(size_t i = 1; i < result.length(); i++){
        if (result[i] == first_letter){
            result[i] = L'.';
        }
    }
    std::wcout << L"Результат: " << result << endl;
}

void str20() {
    
    using namespace std;
    wstring word;

    
    int n;
    wcout<<L"Выберите режим"<<endl;
    wcout<<L"1. Ручной ввод"<<endl;
    wcout<<L"2. Случайна генерация"<<endl;
    wcout<<L"3. Из файла"<<endl;
    wcin>>n;

    switch (n)
    {
    case 1:
        wcout << L"Введите текст ";
        wcin.ignore();
        getline(wcin, word);
        
        break;

    case 2:{
        int l;
        wcout<<L"Введите длину слова";
        wcin>>l;
        word=generator(l);
        wcout<<word;
        break;

    }
    case 3:{
        word = file_word();
    }
    
    default:
        break;
    }



    vector<wchar_t> low_alpha = {
        L'й', L'ц', L'у', L'к', L'е', L'н', L'г', L'ш', L'щ', L'з', 
        L'х', L'ъ', L'ф', L'ы', L'в', L'а', L'п', L'р', L'о', L'л',
        L'д', L'ж', L'э', L'я', L'ч', L'с', L'м', L'и', L'т', L'ь',
        L'б', L'ю', L'ё'
    };
    
    vector<wchar_t> high_alpha = {
        L'Й', L'Ц', L'У', L'К', L'Е', L'Н', L'Г', L'Ш', L'Щ', L'З',
        L'Х', L'Ъ', L'Ф', L'Ы', L'В', L'А', L'П', L'Р', L'О', L'Л',
        L'Д', L'Ж', L'Э', L'Я', L'Ч', L'С', L'М', L'И', L'Т', L'Ь',
        L'Б', L'Ю', L'Ё'
    };
    

    if(low_alpha.size() != high_alpha.size()) {
        wcout << L"Ошибка: размеры векторов не совпадают!" << endl;
        return;
    }
    

    for(size_t i = 0; i < word.length(); i++) {
        wchar_t current = word[i];
        
        // Поиск символа в нижнем регистре
        bool found = false;
        for(size_t j = 0; j < low_alpha.size(); j++) {
            if(current == low_alpha[j]) {
                word[i] = high_alpha[j];  
                found = true;
                break;
            }
        }
    }
    std::wcout<<"Ваше слово с буквами в верхнем регистре: "<<word<<endl;
}

void str25() {
    using namespace std;
    int z, b;
    int  a;
 
    int n;
    wcout<<L"Выберите режим"<<endl;
    wcout<<L"1. Ручной ввод"<<endl;
    wcout<<L"2. Случайна генерация"<<endl;
    wcout<<L"3. Из файла"<<endl;
    wcin>>n;

    switch (n)
    {
    case 1:
        wcout << L"Введите число в 10-ой системе счисления";
        wcin>>a;

        break;

    case 2:{
        wcout<<L"Введите диапазон из которого будет выбрано случайное целое число"<<endl;
        wcout<<L"s: ";
        wcin>>z;
        wcout<<L"Введите b: ";
        wcin>>b;
        srand(time(0));
        a=z+rand()%b;
        wcout<<a;
        break;

    }
    case 3: {
        a = stoll(file_word());
    }
    
    default:
        break;
    }


    bool is_negative = (a < 0);
    if (is_negative) {
        a = -a;  
    }
    

    string s = to_string(a);
    
    wstring result;
    int len = s.length();
    

    int first_triad_len = len % 3;
    if (first_triad_len == 0) {
        first_triad_len = 3;
    }
    

    for (int i = 0; i < first_triad_len; i++) {
        result += s[i];
    }

    for (int i = first_triad_len; i < len; i += 3) {
        result += L'.';
        result += s[i];
        result += s[i + 1];
        result += s[i + 2];
    }

    if (is_negative) {
        result = L'-' + result;
    }
    
    wcout << L"Результат: " << result << endl;
}


void str37() {
    using namespace std;
    wstring encrypted;

    
    int n;
    wcout<<L"Выберите режим"<<endl;
    wcout<<L"1. Ручной ввод"<<endl;
    wcout<<L"2. Случайна генерация"<<endl;
    wcout<<L"3. Из файла"<<endl;
    wcin>>n;

    switch (n)
    {
    case 1:
        wcout << L"Введите зашифрованный текст: ";
        wcin.ignore();
        getline(wcin, encrypted);
        
        break;
    case 2:{
        int l;
        wcout<<L"Введите длину слова";
        wcin>>l;
        encrypted=generator(l);
        wcout<<encrypted;
        break;

    }
    case 3:{
        encrypted = file_word();

    }
    
    default:
        break;
    }

    wstring enc_letters = L"БВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯА" 
                          L"бвгдеёжзийклмнопрстуфхцчшщъыьэюяа";  
    

    wstring dec_letters = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"   
                          L"абвгдеёжзийклмнопрстуфхцчшщъыьэюя";   
    
    wstring decrypted;
    
    for (wchar_t c : encrypted) {
        size_t pos = enc_letters.find(c);
        if (pos != wstring::npos) {
            decrypted += dec_letters[pos];  
        } else {
            decrypted += c;  
        }
    }
    
    wcout << L"\nЗашифрованный текст: " << encrypted << endl;
    wcout << L"Расшифрованный текст: " << decrypted << endl;
}

void str33() {
    using namespace std;
    wstring num12;

    
    int n;
    wcout<<L"Выберите режим"<<endl;
    wcout<<L"1. Ручной ввод"<<endl;
    wcout<<L"2. Случайна генерация"<<endl;
    wcout<<L"3. Из файла"<<endl;
    wcin>>n;

    switch (n)
    {
    case 1:
        wcout << L"Введите число в 12-ой системе счисления: ";
        wcin>>num12;

        break;

    case 2:{
        int l;
        wcout<<L"Создание случайного числа"<<endl;
        wcout<<L"Введите длину числа >0: ";
        
        wcin>>l;
        
        num12=generator_num(l);
        while (!num12.empty() && num12[0]==L'0')
        {
            wcout<<L"Введите длину числа >0";
            wcin>>l;
            num12=generator_num(l);
        }
        

        wcout<<num12;
        break;

    }
    case 3:{
        num12 = file_word();
    }
    
    default:
        break;
    }


    if (num12.empty()) {
        wcout << L"Ошибка: пустой ввод!" << endl;
        return;
    }
    
    long long decimal = 0;
    for (int i = 0; i < num12.length(); i++) {
        char c = toupper(num12[i]);  
        int value;
        
        if (c >= '0' && c <= '9') {
            value = c - '0';
        } else if (c == 'A' ) {
            value = 10;
        } else if (c == 'B' ) {
            value = 11;
        } else {
            wcout << L"Ошибка: недопустимый символ '" << c << L"'" << endl;
            return;
        }
        
        int power = num12.length() - i - 1;
        decimal += value * pow(12, power);
    }
    
    string base4;
    long long temp = decimal;
    
    if (temp == 0) {
        base4 = "0";
    } else {
        while (temp > 0) {
            base4 = to_string(temp % 4) + base4;
            temp /= 4;
        }
    }
    
    wcout << L"\nРезультат перевода:" << endl;
    wcout << L"12-ричное: " << num12.c_str() << endl;
    wcout << L"10-ричное: " << decimal << endl;
    wcout << L"4-ричное:  " << base4.c_str() << endl;
}

void task6() {
    using namespace std;
    wstring word;
        

    int n;
    wcout<<L"Выберите режим"<<endl;
    wcout<<L"1. Ручной ввод"<<endl;
    wcout<<L"2. Случайна генерация"<<endl;
    wcout<<L"3. Из файла"<<endl;
    wcin>>n;

    switch (n)
    {
    case 1:
        wcout << L"Введите слово: ";
        wcin.ignore();
        getline(wcin, word);
        
        break;

    case 2:{
        int l;
        wcout<<L"Введите длину слова";
        wcin>>l;
        word=generator(l);
        wcout<<word;
        break;

    }
    case 3:{
        word=file_word();
    }
    
    default:
        break;
    }

    
    srand(time(0));
    int count = 0;
    wstring new_word;
    
    wcout << endl;
    
    do {

        vector<wchar_t> s;
        for (int i = 0; i < word.length(); i++) {
            s.push_back(word[i]);
        }

        new_word.clear();

        int letters_left = s.size();
        for (int i = 0; i < word.length(); i++) {
            int index = rand() % letters_left;
            new_word += s[index];         
            s.erase(s.begin() + index);   
            letters_left--;
        }
        
        wcout << new_word << endl;
        count++;
        
    } while (new_word != word);
    
    wcout << count << L" попыток" << endl;
}

// Конвертация двоичных чисел
int binaryToDecimal(const std::string& binary) {
    using namespace std;
    int decimal = 0;
    int power = 1; 
    
    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += power;
        } else if (binary[i] != '0') {
            return -1;  
        }
        power *= 2;
    }
    
    return decimal;
}

std::string decimalToBinary(int decimal) {
    using namespace std;
    if (decimal == 0) return "0";
    
    string binary;
    while (decimal > 0) {
        binary = to_string(decimal % 2) + binary;
        decimal /= 2;
    }
    
    return binary;
}

// Проверка правильности решения арифметического выражения
bool checkExample(const std::string& example, std::string& correctAnswer) {
    using namespace std;
    // Примеры в формате: "101+110=1011"
    
    size_t plusPos = example.find('+');
    size_t multiplyPos = example.find('*');
    size_t equalsPos = example.find('=');
    
    if (equalsPos == string::npos) {
        return false;  // Нет знака равенства
    }
    
    char operation;
    size_t opPos;
    
    if (plusPos != string::npos) {
        operation = '+';
        opPos = plusPos;
    } else if (multiplyPos != string::npos) {
        operation = '*';
        opPos = multiplyPos;
    } else {
        return false;  // Нет операции
    }
    
    // Извлекаем операнды и ответ
    string operand1 = example.substr(0, opPos);
    string operand2 = example.substr(opPos + 1, equalsPos - opPos - 1);
    string answer = example.substr(equalsPos + 1);
    
    // Проверяем, что все части - двоичные числа
    for (char c : operand1 + operand2 + answer) {
        if (c != '0' && c != '1') {
            return false;  // Не двоичное число
        }
    }
    
    // Преобразуем в десятичную систему
    int dec1 = binaryToDecimal(operand1);
    int dec2 = binaryToDecimal(operand2);
    int decAnswer = binaryToDecimal(answer);
    
    if (dec1 == -1 || dec2 == -1 || decAnswer == -1) {
        return false;  // Ошибка преобразования
    }
    
    // Вычисляем правильный результат
    int correctResult;
    if (operation == '+') {
        correctResult = dec1 + dec2;
    } else { // operation == '*'
        correctResult = dec1 * dec2;
    }
    
    // Преобразуем правильный результат обратно в двоичную систему
    correctAnswer = decimalToBinary(correctResult);
    
    // Сравниваем с ответом ученика
    return (correctAnswer == answer);
}

// Автоматизированная проверка домашнего задания
void five8() {
    using namespace std;
    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    string inputFilename = "FN1.txt";
    string outputFilename = "FN2.txt";
    

    ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        wcout << L"Ошибка: не удалось открыть файл " << inputFilename.c_str() << endl;
        return;
    }
    

    ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        wcout << L"Ошибка: не удалось создать файл " << outputFilename.c_str() << endl;
        inputFile.close();
        return;
    }
    
    wcout << L"Проверка домашней работы..." << endl;
    wcout << L"Входной файл: " << inputFilename.c_str() << endl;
    wcout << L"Выходной файл: " << outputFilename.c_str() << endl;
    wcout << endl;
    
    string line;
    int totalExamples = 0;
    int correctExamples = 0;
    

    while (getline(inputFile, line)) {

        if (line.empty()) {
            outputFile << endl;
            continue;
        }
        
        totalExamples++;
        
        // Проверяем пример
        string correctAnswer;
        bool isCorrect = checkExample(line, correctAnswer);
        
        if (isCorrect) {
            // Пример решен верно
            outputFile << line << endl;
            correctExamples++;
            wcout << L"✓ " << line.c_str() << L" - правильно" << endl;
        } else {
            // Пример решен неверно
            outputFile << line << " -" << endl;
            
            size_t equalsPos = line.find('=');
            if (equalsPos != string::npos) {
                string beforeEquals = line.substr(0, equalsPos + 1);
                wcout << L"✗ " << beforeEquals.c_str() 
                      << L" (ответ: " << line.substr(equalsPos + 1).c_str() 
                      << L", правильно: " << correctAnswer.c_str() << L")" << endl;
            } else {
                wcout << L"✗ " << line.c_str() << L" - ошибка формата" << endl;
            }
        }
    }
    

    inputFile.close();
    outputFile.close();

    wcout << endl;
    wcout << L"Результаты проверки:" << endl;
    wcout << L"Всего примеров: " << totalExamples << endl;
    wcout << L"Правильно решено: " << correctExamples << endl;
    wcout << L"Неправильно решено: " << (totalExamples - correctExamples) << endl;
    
    wcout << L"\nРезультаты записаны в файл " << outputFilename.c_str() << endl;
}



