#include <iostream>
#include "module.h"
#include <fstream> 
#include <string>
using namespace std;


struct Node
{
    int value;
    Node* next;
};

class Stack{
private:
    Node* top;

public:

    Stack(){
        top=nullptr;

    };
    Stack(const Stack& other){
        top=nullptr;
        if(other.top==nullptr) return;

        Stack tempStack;
        Node* current=other.top;
        while (current!=nullptr)
        {
            tempStack.push(current->value);
            current=current->next;
        }
        
    }
    ~Stack(){
        while (top!=nullptr)
        {
            Node* temp=top;
            top=top->next;
            delete temp;
        }
        
    }
    void push(int val){
        Node* newNode=new Node;
        newNode->next=top;
        newNode->value=val;
        top=newNode;

    }
    int peek(){
        if (top==nullptr) return 0;
        return top->value;
    }
    bool isEmpty() const {
        return top == nullptr;
    }
    Node* getTopPtr(){
        return top;
    }

    void setTopPtr(Node* ptr){
        top=ptr;
    }

    void print()  {
        Node* current = top;
        cout << "Stack (Top->Bottom): ";
        if (current == nullptr) {
            cout << "nullptr (empty)";
        }
        while (current != nullptr) {
            cout << current->value;
            if (current->next != nullptr) cout << " -> ";
            current = current->next;
        }
        cout << endl;
    }
};

void splitStack(Stack& original, Stack& evenStack, Stack& oddStack){
    Node* current=original.getTopPtr();

    Node* evenTop=nullptr;
    Node* oddTop=nullptr;

    while (current!=nullptr)
    {
        Node* nextNode = current->next;
        if (current->value%2==0){
            current->next=evenTop;
            evenTop=current;

        }
        else{
            current->next=oddTop;
            oddTop=current;
        }
        current=nextNode;
    }
    evenStack.setTopPtr(evenTop);
    oddStack.setTopPtr(oddTop);

    original.setTopPtr(nullptr);
}

void task1(){
    Stack s1;
    int n;
    cout<<"введите кол-во элементов которое будет хрнаится в стэке: ";
    cin>>n;
    for (int i=0; i<n; i++){
        cout<<"Введите число: ";
        int num;
        cin>>num;
        s1.push(num);
    }
    cout<<"Стэк заполнен"<<endl;

    cout << "Исходный стек: ";
    s1.print();

    Stack oddStack;
    Stack evenStack;

    splitStack(s1, evenStack, oddStack);

    cout << "\n--- Результаты ---" << endl;
    
    cout << "Стек четных (адрес вершины): " << evenStack.getTopPtr() << endl;
    evenStack.print();

    cout << "Стек нечетных (адрес вершины): " << oddStack.getTopPtr() << endl;
    oddStack.print();

    cout << "Исходный стек после разделения (адрес вершины): " << s1.getTopPtr() << endl;
    s1.print();

}

struct TNode
{
    int Data;
    TNode* next;
};

class Queue{
private:
    TNode* tail;
    TNode* head;
public:
    Queue(){
        tail=nullptr;
        head=nullptr;
    }
    ~Queue(){
        while (head!=nullptr)
        {
            TNode* temp=head;
            head=head->next;
            delete temp;
        }
    }
    void push(int num){
        TNode* newNode=new TNode;
        newNode->Data=num;
        newNode->next=nullptr;
        if (head==nullptr){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    TNode* getHead(){
        return head;
    }
    TNode* getTail(){
        return tail;
    }
    void setHead(TNode* h){
        head=h;
    }
    void setTail(TNode* t){
        tail=t;
    }
    void print(){
        cout << "Queue (head→tail): ";
        if (head==nullptr){
            cout << "nullptr (empty)";
        }
        else{
            TNode* current=head;
            while (current!=nullptr)
            {
                cout<<current->Data;
                if (current->next != nullptr) cout << " → ";
                current=current->next;
            }
            
        }
        cout << endl;
    }
};
void addToQueueEnd(TNode*& head, TNode*& tail, int num) {
    TNode* newNode=new TNode;
    newNode->Data=num;
    newNode->next=nullptr;
    if (head==nullptr){
        head=newNode;
        tail=newNode;
    }
    else{
        tail->next=newNode;
        tail=newNode;
    }
}

void task2(){
    Queue q1;
    int n;
    cout<<"введите кол-во элементов которое будет хрнаится в очереди: ";
    cin>>n;
    for (int i=0; i<n; i++){
        cout<<"Введите число: ";
        int num;
        cin>>num;
        q1.push(num);
    }
    cout<<"Очередь заполнена"<<endl;
        cout << "Исходная очередь: ";
    q1.print();
    
    cout << "Введите число для добавления: ";
    int newnum;
    cin >> newnum;
    
    q1.push(newnum);  
    
    cout << "\nИтоговая очередь:" << endl;
    q1.print(); 
}
class LinkedList{
private:
    Node* tail;
    Node* head;
    int size=0;
public: 
    LinkedList(){
        tail=nullptr;
        head=nullptr;
        size=0;
    }
    LinkedList(const LinkedList& other){
        head = nullptr;
        tail = nullptr;
        size = 0;
        
        if (other.head == nullptr) return;
        Node* current = other.head;
        while (current != nullptr) {
            push_back(current->value);
            current = current->next;
        }

    }
    ~LinkedList(){
        
        while (head!=nullptr)
        {
            Node*temp=head;
            head=temp->next;
            delete temp;
        }
        
    }
    void push_back(int val){
        Node* newNode=new Node;
        newNode->value=val;
        newNode->next=nullptr;
        if (head==nullptr){

            head=newNode;
            tail=newNode;
        }
        else{
            
            tail->next=newNode;
            tail=newNode;
        }
        size++;
    }
    Node* find9(){
        Node* current=head;
        for (int i=1; i<9; i++){
            current=current->next;
        }
        return current;
    }
    void insert(int M) {
        if (head == nullptr) return;  
        
        Node* current = head;  
        int position = 1;      
        while (current != nullptr) {
           
       
            if (position % 2 == 1 && current->next != nullptr) {
               
                Node* newNode = new Node;
                newNode->value = M;
                
                
                newNode->next = current->next;  // Новый узел указывает на следующий
                current->next = newNode;        // Текущий указывает на новый
                
                
                if (newNode->next == nullptr) {
                    tail = newNode;
                }
                
                size++; 
                
                
                current = newNode->next;
                position += 2;  
            }
            else {
                
                current = current->next;
                position++;
            }
        }
        
        
        tail = head;
        while (tail != nullptr && tail->next != nullptr) {
            tail = tail->next;
        }
    }

    Node* getHead() {
        return head;
    }

    int getSize()  {
        return size;
    }
        void print()  {
        cout << "Список: ";
        if (head == nullptr) {
            cout << "nullptr (пусто)";
        }
        else {
            Node* current = head;
            int index = 1;
            while (current != nullptr) {
                cout << "[" << index << "]=" << current->value;
                if (current->next != nullptr) cout << " -> ";
                current = current->next;
                index++;
            }
        }
        cout << endl;
    }

    void insertSorted(int val) {
        Node* newNode = new Node;
        newNode->value = val;
        newNode->next = nullptr;
        
        // Случай 1: список пуст или новый элемент больше головы
        if (head == nullptr || val > head->value) {
            newNode->next = head;
            head = newNode;
            if (tail == nullptr) tail = newNode;  // если список был пуст
        }
        // Случай 2: ищем позицию для вставки
        else {
            Node* current = head;
            // Ищем узел, после которого нужно вставить (пока следующий > val)
            while (current->next != nullptr && current->next->value > val) {
                current = current->next;
            }
            // Вставляем
            newNode->next = current->next;
            current->next = newNode;
            // Обновляем tail, если вставили в конец
            if (newNode->next == nullptr) {
                tail = newNode;
            }
        }
        size++;
    }

    bool loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Ошибка открытия файла: " << filename << endl;
            return false;
        }
        
        int n;
        file >> n;  // читаем N
        
        for (int i = 0; i < n; i++) {
            int num;
            file >> num;
            insertSorted(num);  // 🔑 вставляем с сортировкой
        }
        
        file.close();
        return true;
    }
};

void task3(){
    LinkedList ll;

    int n;
    cout<<"введите кол-во элементов которое будет хрнаится в односвязном списке(9>=): ";
    cin>>n;
    if(n>=9){
        for (int i=0; i<n; i++){
            cout<<"Введите число: ";
            int num;
            cin>>num;
            ll.push_back(num);
        }
        cout<<"Односвязный список заполнен"<<endl;
        cout << "Исходный односвязный список : ";
        ll.print();

        cout << "Исходный односвязный список : ";
        ll.print();
        cout<<"Указатель на 9 элемент: "<<ll.find9()<<endl;


    }
    else{
        cout<<"!!!ОШИБКА!!! Число элементо списка должно быть 9>="<<endl;;
    }

    
    
}
void task4(){
    LinkedList ll;

    int n;
    cout<<"введите кол-во элементов которое будет хрнаится в односвязном  ";
    cin>>n;
    
    for (int i=0; i<n; i++){
            cout<<"Введите число: ";
            int num;
            cin>>num;
            ll.push_back(num);
        }
    cout<<"Введиче симло которое хотите вставыить: ";
    int z;
    cin>>z;
    ll.insert(z);
    cout << "Новый односвязный список : ";
    ll.print();
    cout<<"Односвязный список заполнен"<<endl;
}


void task5(){
    LinkedList ll;
    string filename;
    cout << "Имя файла: ";
    cin >> filename;
    if (!ll.loadFromFile(filename)) return;
    cout << "Результат: ";
    ll.print();
}