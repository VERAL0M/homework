#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

struct Node
{
    int value;
    Node* next;
    Node* prev;
    Node(int val) : value(val), next(nullptr), prev(nullptr) {}

};


class DoublyLinkedList{
private:
    Node* head;
    Node* tail;

    void clear(){
        while (head)
        {
            Node* newNode=head;
            head=head->next;
            delete newNode;
        }
        head = nullptr; 
        tail = nullptr;

    }

    void printBetweenMinMax(){
        if(!head){
            cout<<"список пуст"<<endl;
            return;
        }
        Node* minNode=head;
        Node* maxNode=head;
        Node* current=head;

        while (current)
        {
            if(current->value > maxNode->value){
                maxNode=current;
            }

            if(current->value<minNode->value){
                minNode=current;
            }
            current=current->next;
        }
        


    // Определяем порядок: кто стоит раньше в списке?
    Node* firstFound = nullptr;
    current = head;

    while (current) {
        if (current == minNode || current == maxNode) {
            if (firstFound == nullptr) {
                firstFound = current;  // Запоминаем первого встреченного
            } else {
                break;  // Второго нашли — выходим
            }
        }
        current = current->next;
    }

    // Назначаем start и end в правильном порядке
    Node* start = firstFound;
    Node* end = (firstFound == minNode) ? maxNode : minNode;

    // Теперь выводим элементы между start и end
    cout << "Элементы между мин и макс: ";
    current = start->next;
    bool found = false;
    while (current && current != end) {
        cout << current->value << " ";
        found = true;
        current = current->next;
    }
    if (!found) cout << "(нет элементов между ними)";
    cout << endl;

    }
    

public: 

    DoublyLinkedList() : head(nullptr), tail(nullptr) {
        cout << "Вызван конструктор по умолчанию." << endl;
    }

    // 2. Конструктор копирования (Глубокое копирование)
    DoublyLinkedList(const DoublyLinkedList& other) : head(nullptr), tail(nullptr) {
        cout << "Вызван конструктор копирования." << endl;
        Node* current = other.head;
        while (current) {
            pushBack(current->value); // Используем публичный метод для заполнения
            current = current->next;
        }
    }


    ~DoublyLinkedList() {
        cout << "Вызван деструктор." << endl;
        clear();
    }
    void pushBack(int val){
        Node* newNode=new Node(val);
        if(!head){
            head=tail=newNode;

        }
        else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }

    }

    void printList() const {
        if (!head) {
            cout << "Список пуст." << endl;
            return;
        }
        Node* current = head;
        cout << "Список: ";
        while (current) {
            cout << current->value;
            if (current->next) cout << " <-> ";
            current = current->next;
        }
        cout << endl;
    }


    void solveVariantTask() {
        cout << "\n--- Решение задачи ListWork41 ---" << endl;
        printBetweenMinMax();
    }
};


void task2() {

    // setlocale(LC_ALL, "Russian");

    


    DoublyLinkedList list1;

    
    cout << "\nЗаполнение первого списка..." << endl;
    int n;
    cout<<"введите кол-во элементов которое будет хрнаится в классе: ";
    cin>>n;
    for (int i=0; i<n; i++){
        cout<<"Введите число: ";
        int num;
        cin>>num;
        list1.pushBack(num);
    }
    cout<<"Список заполнен"<<endl;

    list1.printList();


    list1.solveVariantTask();


}


struct NodeC {
    int value;
    NodeC* next;
    

    NodeC(int val) : value(val), next(nullptr) {}
};

class CircularList {
private:
    NodeC* head;  // Указатель на "первый" элемент (точка входа)
    int size;    // Размер списка (для удобства и отладки)

    // Процедура: найти узел, стоящий ПЕРЕД данным (в циклическом списке)
    NodeC* findPrevious(NodeC* target) const {
        if (!head || !target) return nullptr;
        if (head->next == head) return head; // единственный элемент
        
        NodeC* current = head;
        // Идём, пока next не укажет на target
        while (current->next != target) {
            current = current->next;
        }
        return current;
    }

public:

    CircularList() : head(nullptr), size(0) {}
    

    
    // Конструктор копирования
    CircularList(const CircularList& other) : head(nullptr), size(0) {
        if (other.head == nullptr) return;
        
        // Копируем первый элемент
        head = new NodeC(other.head->value);
        head->next = head;
        size = 1;
        
        // Копируем остальные
        NodeC* currentOther = other.head->next;
        NodeC* tail = head;
        
        while (currentOther != other.head) {
            NodeC* newNode = new NodeC(currentOther->value);
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
            size++;
            currentOther = currentOther->next;
        }
    }
    
    // Деструктор
    ~CircularList() {
        while (size > 0) {
            NodeC* temp = head;
            if (size == 1) {
                head = nullptr;
            } else {
                NodeC* prev = findPrevious(head);
                prev->next = head->next;
                head = head->next;
            }
            delete temp;
            size--;
        }
    }


    

    void pushBack(int val) {
        NodeC* newNode = new NodeC(val);
        if (!head) {
            head = newNode;
            head->next = head; // Замыкаем на себя
        } else {
            NodeC* tail = findPrevious(head);
            tail->next = newNode;
            newNode->next = head;
        }
        size++;
    }
    
    // Вывод списка для отладки
    void print() const {
        if (!head) {
            cout << "пусто";
            return;
        }
        NodeC* current = head;
        do {
            cout << current->value << " -> ";
            current = current->next;
        } while (current != head);
        cout << "head";
    }

    // Вывод с шагом k в файл с удалением элементов
    bool solveWithStepK(int k, const string& filename) {
        // Проверка входных данных
        if (!head || k <= 0) {
            cerr << "Ошибка: пустой список или некорректный шаг k" << endl;
            return false;
        }
        
        // Открываем файл для записи
        ofstream outFile(filename);
        if (!outFile.is_open()) {
            cerr << "Ошибка: не удалось создать файл " << filename << endl;
            return false;
        }
        
        NodeC* current = head;
        
        cout << "Результат: ";
        
        // Основной цикл: пока есть элементы
        while (size > 0) {
            // 1. Выводим текущий элемент (в консоль и файл)
            outFile << current->value << " ";
            cout << current->value << " ";
            
            // 2. Если это последний элемент — просто удаляем и выходим
            if (size == 1) {
                delete current;
                head = nullptr;
                size = 0;
                break;
            }
            
            // 3. Находим предыдущий узел (чтобы перенаправить ссылку)
            NodeC* prev = findPrevious(current);
            
            // 4. Запоминаем, куда идти дальше (следующий после удаляемого)
            NodeC* nextNode = current->next;
            
            // 5. Удаляем текущий узел из кольца
            prev->next = nextNode;  // Предыдущий теперь указывает на следующего
            
            // Если удалили голову — обновляем указатель head
            if (current == head) {
                head = nextNode;
            }
            
            delete current;  // Освобождаем память
            size--;
            
            // 6. Делаем (k-1) шагов от nextNode
    
            for (int i = 0; i < k - 1; i++) {
                nextNode = nextNode->next;
            }
            
            
            current = nextNode;
        }
        
    
        outFile << endl;
        outFile.close();
        
        cout << "\nЗапись завершена. Файл: " << filename << endl;
        return true;
    }
    
    // Геттеры
    int getSize() const { return size; }
    bool isEmpty() const { return size == 0; }
};


void task1() {

    // setlocale(LC_ALL, "Russian");
    
    cout << "Циклический список: вывод с шагом K" << endl;

    CircularList list;

    cout << "Введите количество элементов, которое будет храниться в списке: ";
    int n;
    cin >> n;


    for (int i = 0; i < n; i++) {
        cout << "Введите число " << (i + 1) << ": ";
        int num;
        cin >> num;
        list.pushBack(num);  
    }
    cout << "\nСписок заполнен!" << endl;

    cout << "\nИсходный циклический список: ";
    list.print();
    cout << endl << endl;


    cout << "Введите шаг K: ";
    int k;
    cin >> k;

    string filename = "output.txt";
    cout << "\nВыполнение задачи (вывод с шагом " << k << ")..." << endl;
    
    if (list.solveWithStepK(k, filename)) {
        cout << "Результат записан в файл: " << filename << endl;
    } else {
        cout << "Ошибка!" << endl;
    }


    cout << "\n Список после выполнения: ";
    if (list.isEmpty()) {
        cout << "nullptr" << endl;
    } else {
        list.print();
    }

    cout << "\n Содержимое файла " << filename << ":" << endl;
    ifstream inFile(filename);
    if (inFile.is_open()) {
        string line;
        getline(inFile, line);
        cout << "   " << line << endl;
        inFile.close();
    }

    cout << "\n Программа завершена" << endl;
    

}








class DoublyLinkedListPtr {
private:
    // === ИНКАПСУЛИРОВАННАЯ структура узла ===
    struct Node {
        int value;
        Node* prev;
        Node* next;
        
        Node(int val) : value(val), prev(nullptr), next(nullptr) {}
    };
    
    // === Приватные данные (аналог P1, P2, P3 из условия) ===
    Node* First;    // Указатель на первый элемент (P1)
    Node* Last;     // Указатель на последний элемент (P2)
    Node* Current;  // Указатель на текущий элемент (P3)
    
    // === ПРОЦЕДУРЫ (приватные вспомогательные методы) ===
    
    // Процедура: очистка памяти
    void clear() {
        while (First != nullptr) {
            Node* temp = First;
            First = First->next;
            delete temp;
        }
        First = nullptr;
        Last = nullptr;
        Current = nullptr;
    }
    
    // Процедура: вывод адресов 
    void printAddressesInternal() const {
        cout << "Адрес первого элемента (First):  " << setw(18) << First << endl;
        cout << "Адрес последнего элемента (Last): " << setw(17) << Last << endl;
        cout << "Адрес текущего элемента (Current): " << setw(16) << Current << endl;
    }

public:
    // === КОНСТРУКТОРЫ И ДЕСТРУКТОР ===
    
    // 1. Конструктор по умолчанию: пустой список (P1 = P2 = P3 = nullptr)
    DoublyLinkedListPtr() : First(nullptr), Last(nullptr), Current(nullptr) {}
    
    // 2. Конструктор копирования 
    DoublyLinkedListPtr(const DoublyLinkedListPtr& other) 
        : First(nullptr), Last(nullptr), Current(nullptr) {
        
        if (other.First == nullptr) return;  // Копируем пустой список
        
        // Копируем узлы по порядку
        Node* src = other.First;
        Node* prevNode = nullptr;
        
        while (src != nullptr) {
            Node* newNode = new Node(src->value);
            
            if (First == nullptr) {
                First = newNode;  // Первый узел
            } else {
                prevNode->next = newNode;
                newNode->prev = prevNode;
            }
            
            // Если копируемый узел был Current — запоминаем новый как Current
            if (src == other.Current) {
                Current = newNode;
            }
            
            prevNode = newNode;
            src = src->next;
        }
        
        Last = prevNode;  // Последний скопированный узел
        
        // Если в оригинале Current был nullptr — оставляем так
        if (other.Current == nullptr) {
            Current = nullptr;
        }
    }
    
    // 3. Деструктор
    ~DoublyLinkedListPtr() {
        clear();
    }
    
    
    
    // 🔹 ПРОЦЕДУРА InsertLast: добавить элемент в конец списка

    void InsertLast(int D) {
        Node* newNode = new Node(D);
        
        if (First == nullptr) {
            // Список пустой: новый элемент становится первым, последним и текущим
            First = newNode;
            Last = newNode;
            Current = newNode;
        } else {
            // Список не пустой: добавляем в конец
            newNode->prev = Last;
            Last->next = newNode;
            Last = newNode;
            // Новый элемент становится текущим (по условию)
            Current = newNode;
        }
    }
    

    
    // 🔹 Получить адрес текущего элемента 
    Node* getCurrentAddress() const {
        return Current;
    }
    
    // 🔹 Получить значение текущего элемента
    int getCurrentValue() const {
        return Current ? Current->value : -1;
    }
    
    // 🔹 Проверка на пустоту
    bool isEmpty() const {
        return First == nullptr;
    }
    
    // 🔹 Получить размер списка
    int getSize() const {
        int count = 0;
        Node* current = First;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
    
    // 🔹 Вывод содержимого списка
    void printList() const {
        cout << "Содержимое списка: ";
        if (First == nullptr) {
            cout << "пусто";
        } else {
            Node* current = First;
            while (current != nullptr) {
                cout << current->value;
                if (current->next != nullptr) cout << " <-> ";
                current = current->next;
            }
        }
        cout << endl;
    }
    
    // 🔹 Вывод адресов First, Last, Current (требование задачи)
    void printAddresses() const {
        printAddressesInternal();
    }
};


void task3() {
    // setlocale(LC_ALL, "Russian");
    

    
    // 1. Создание объекта (конструктор по умолчанию)
    //    По условию: пустой список → First = Last = Current = nullptr
    DoublyLinkedListPtr list;
    
    cout << "1. Исходный список (пустой):" << endl;
    list.printAddresses();
    cout << endl;
    
    // 2. Ввод числа N (> 0)
    cout << "2. Введите количество элементов N (> 0): ";
    int N;
    cin >> N;
    
    if (N <= 0) {
        cerr << "Ошибка: N должно быть больше 0!" << endl;
        return;
    }
    
    // 3. Ввод N чисел и добавление через InsertLast
    cout << "\n3. Введите " << N << " чисел:" << endl;
    for (int i = 0; i < N; i++) {
        int D;
        cout << "   Число " << (i + 1) << ": ";
        cin >> D;
        
        // 🔹 ВЫЗОВ МЕТОДА-ПРОЦЕДУРЫ InsertLast
        list.InsertLast(D);
        
        cout << "  Элемент " << D << " добавлен. Current = " << list.getCurrentAddress() << endl;
    }
    cout << endl;
    
    // 4. Вывод результатов (требование задачи)
    cout << "=== РЕЗУЛЬТАТЫ ===" << endl << endl;
    
    cout << "Содержимое списка:" << endl;
    list.printList();
    cout << endl;
    
    cout << "ТРЕБУЕМЫЙ ВЫВОД (адреса элементов):" << endl;
    list.printAddresses();  // ← ГЛАВНОЕ ТРЕБОВАНИЕ: вывести адреса First, Last, Current
    cout << endl;
    

    cout << endl;
    

}


class BarrierList {
public:
    struct Node {
        int value;
        Node* prev;
        Node* next;
        Node(int val) : value(val), prev(nullptr), next(nullptr) {}
    };
    
private:
    Node* Barrier;
    Node* Current;
    
    void clear() {
        if (!Barrier) return;
        if (Barrier->next != Barrier) {
            Node* cur = Barrier->next;
            while (cur != Barrier) {
                Node* nxt = cur->next;
                delete cur;
                cur = nxt;
            }
        }
        delete Barrier;
        Barrier = nullptr;
        Current = nullptr;
    }
    
public:
    // Конструктор по умолчанию: пустой список с барьером
    BarrierList() {
        Barrier = new Node(0);
        Barrier->next = Barrier;
        Barrier->prev = Barrier;
        Current = Barrier;
    }
    
    // Конструктор копирования
    BarrierList(const BarrierList& other) {
        Barrier = new Node(0);
        Barrier->next = Barrier;
        Barrier->prev = Barrier;
        Current = Barrier;
        if (other.Barrier->next != other.Barrier) {
            Node* src = other.Barrier->next;
            Node* last = nullptr;
            while (src != other.Barrier) {
                Node* newNode = new Node(src->value);
                newNode->prev = last ? last : Barrier;
                newNode->next = Barrier;
                if (last) last->next = newNode;
                else Barrier->next = newNode;
                Barrier->prev = newNode;
                if (src == other.Current) Current = newNode;
                last = newNode;
                src = src->next;
            }
            if (Current == Barrier) Current = Barrier->next;
        }
    }
    
    // Деструктор
    ~BarrierList() { clear(); }
    
    // Процедура LBInsertLast: добавить элемент в конец списка
    void LBInsertLast(int D) {
        Node* newNode = new Node(D);
        newNode->next = Barrier;
        newNode->prev = Barrier->prev;
        Barrier->prev->next = newNode;
        Barrier->prev = newNode;
        Current = newNode;  // Добавленный элемент становится текущим
    }
    
    // Вывод адреса текущего элемента (требование задачи)
    void printCurrentAddress() const {
        cout << "Адрес текущего элемента (Current): " << setw(18) << Current << endl;
    }
};

// === Функция task4 (ListWork47) ===
void task4() {
    setlocale(LC_ALL, "Russian");
    
    // 1. Создаём пустой список с барьером (конструктор по умолчанию)
    BarrierList list;
    
    // 2. Ввод N (как в ваших предыдущих задачах)
    cout << "Введите кол-во элементов которое будет хранится в списке: ";
    int n;
    cin >> n;
    
    // 3. Ввод чисел и добавление через LBInsertLast
    for (int i = 0; i < n; i++) {
        cout << "Введите число: ";
        int num;
        cin >> num;
        list.LBInsertLast(num);
    }
    cout << "Список заполнен" << endl;
    
    // 4. Требуемый вывод: адрес текущего элемента
    list.printCurrentAddress();
}

class WordList {
public:
    struct Node {
        string word;
        Node* prev;
        Node* next;
        Node(const string& w) : word(w), prev(nullptr), next(nullptr) {}
    };
    
private:
    Node* head;
    Node* tail;
    int size;
    
    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
public:
    WordList() : head(nullptr), tail(nullptr), size(0) {}
    
    WordList(const WordList& other) : head(nullptr), tail(nullptr), size(0) {
        Node* current = other.head;
        while (current) {
            pushBack(current->word);
            current = current->next;
        }
    }
    
    ~WordList() { clear(); }
    
    void pushBack(const string& word) {
        Node* newNode = new Node(word);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }
    
    void printByLength() {
        if (!head) return;
        
        // Находим максимальную длину слова
        int maxLen = 0;
        Node* current = head;
        while (current) {
            if ((int)current->word.length() > maxLen)
                maxLen = current->word.length();
            current = current->next;
        }
        
        // Для каждой длины от 1 до maxLen
        for (int len = 1; len <= maxLen; len++) {
            // Чередование: нечётная длина → прямой проход, чётная → обратный
            if (len % 2 == 1) {
                // Прямой проход (от head к tail)
                current = head;
                while (current) {
                    if ((int)current->word.length() == len)
                        cout << current->word << " ";
                    current = current->next;
                }
            } else {
                // Обратный проход (от tail к head)
                current = tail;
                while (current) {
                    if ((int)current->word.length() == len)
                        cout << current->word << " ";
                    current = current->prev;
                }
            }
        }
        cout << endl;
    }
    
    int getSize() const { return size; }
    bool isEmpty() const { return size == 0; }
};

void task5() {
    // setlocale(LC_ALL, "Russian");
    
    cout << "Введите строку слов (разделенных пробелами): ";
    cin.ignore();
    
    // Читаем всю строку
    string line;
    getline(cin, line);
    
    
    // Создаём список
    WordList list;
    
    // Разбиваем строку на слова и добавляем в список
    istringstream iss(line);
    string word;
    while (iss >> word) {
        list.pushBack(word);
    }
    
    cout << "Список заполнен (" << list.getSize() << " слов)" << endl;
    
    // Вывод слов по длине (с чередованием направления)
    cout << "Результат: ";
    list.printByLength();
}
