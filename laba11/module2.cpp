#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "module.h"

using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data=data;
        this->prev=nullptr;
        this->next=nullptr;
    }
};

class DoubleLinkedList{
private:
    Node* head;
    Node* tail;
public:
    DoubleLinkedList(){
        head=tail=nullptr;
    }
    ~DoubleLinkedList(){
        while (head!=nullptr)
        {
            pop_front();
        }
    }
    DoubleLinkedList(const DoubleLinkedList& other){
        head=tail=nullptr;
        Node* ptr=other.head;
        while (ptr!=nullptr)
        {
            this->push_back(ptr->data);
            ptr=ptr->next;
        }
        
    }

    Node* push_front(int  data){
        Node* ptr=new Node(data);
        ptr->next=head;
        if (head!=nullptr){
            head->prev=ptr;
        }
        if(tail==nullptr){
            tail=ptr;
        }
        head=ptr;
        return ptr;
    
    }
    Node* push_back(int  data){
        Node*ptr=new Node(data);
        
        ptr->prev=tail;
        
        if (tail!=nullptr){
            tail->next=ptr;

        }
        if (head==nullptr){
            head=ptr;
            
        }
        tail=ptr;
        return ptr;
    }

    void pop_front(){
        if (head==nullptr){
            return;
        }
        Node* ptr= head->next;
        if (ptr!=nullptr){
            ptr->prev=nullptr;
        }
        else{
            tail=nullptr;
        }
        delete head;
        head=ptr;
    }

    void pop_back(){
        if (tail==nullptr){
            return;
        }
        Node* ptr=tail->prev;
        if (ptr!=nullptr){
            ptr->next=nullptr;

        }
        else{
            head=nullptr;
        }
        delete tail;
        tail=ptr;

    }

    void BetweenMinMax(){
        if(head==nullptr){
            return;
        }
        Node* ptr=head->next;
        Node* ptrMin=head;
        Node* ptrMax=head;
        int n=0, indexMin=0, indexMax=0;
        while (ptr!=nullptr)
        {
            if (ptrMax->data<ptr->data){
                ptrMax=ptr;
                indexMax=n;
            }
            if (ptrMin->data>ptr->data){
                ptrMin=ptr;
                indexMin=n;
            }
            ptr=ptr->next;
            n++;
        }
        if (indexMax>indexMin){
            ptr=ptrMin->next;
            cout<<"Элементы между минимальным и максимальным: ";
            while (ptr!=ptrMax)
            {

                cout<<ptr->data<<" ";
                ptr=ptr->next;
            }
        }
        else{
            if (indexMax<indexMin){
                ptr=ptrMax->next;
                cout<<"Элементы между максимальным и минимальным: ";
                while (ptr!=ptrMin)
                {

                    cout<<ptr->data<<" ";
                    ptr=ptr->next;
                }
                
            }
            else{
                cout<<"Нет элементов между максимальным и минамальным элементами списка";
            }
        }

        cout<<endl;

    }


};
void task2() {

    DoubleLinkedList lst;


    cout << "Заполнение списка" << endl;
    int n;
    cout<<"введите кол-во элементов которое будет хранится в списке: ";
    cin>>n;
    for (int i=0; i<n; i++){
        cout<<"Введите число: ";
        int num;
        cin>>num;
        lst.push_back(num);
    }
    cout<<"Список заполнен"<<endl;

    lst.BetweenMinMax();

}
struct NodeC
{
    int data;
    NodeC* next;
    NodeC(int data){
        this->data=data;
        this->next=nullptr;
    }
};

class CyclicList{
private:
    NodeC* head;

public:
    CyclicList(){
        head=nullptr;

    }
    ~CyclicList(){
        while (head!=nullptr)
        {
            pop_back();
        }
    }

    CyclicList(const CyclicList& other){
        head = nullptr;
        
        if (other.head == nullptr) {
            return;
        }
        
        NodeC* ptr = other.head;
        
        do {
            this->push_back(ptr->data);
            ptr = ptr->next;
        } while (ptr != other.head);  
    }

    NodeC* push_back(int data){

        NodeC* ptr=new NodeC(data);
        if (head==nullptr){
            head=ptr;
            ptr->next=head;
        }
        else{
            NodeC* temp=head;
            while (temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->next=head;
            
        }
        return ptr;
        
    }
    void pop_back(){
        if (head==nullptr){
            return;
        }
        if (head->next==head){
            delete head;
            head=nullptr;
            return;
        }
        NodeC* ptr=head;
        while (ptr->next->next!=head)
        {
            ptr=ptr->next;
        }
        
        delete ptr->next;
        ptr->next=head;
        
    }
    void printStepK(int k){
        ofstream file("seeListStepK.txt");
        if (!file.is_open()){
            cout<<"Не удалось открыть файл"<< endl;
            return;
        }

        
        NodeC*ptr=head;
        NodeC*ptrPrev=nullptr;
        
        while (head!=nullptr)
        {
            for(int i=1; i<k; i++){
                ptrPrev=ptr;
                ptr=ptr->next;
                
            }
            cout<<ptr->data<<" ";
            file<<ptr->data<<" ";
            NodeC* nextNode = ptr->next;
            
            if (head->next==head){
                delete ptr;
                head=nullptr;
            }
            else{
                if(ptr==head){
                    NodeC* ptrLast=head;

                    while (ptrLast->next!=head)
                    {
                        ptrLast=ptrLast->next;
                    }
                    delete head;
                    head = nextNode;
                    ptrLast->next = head;
                }
                else{
                    ptrPrev->next=ptr->next;
                    delete ptr;

                }
                ptr = nextNode;
            }
        }
        file.close();
        cout<<"Файл заполнен"<<endl;
        
    }

};
void task1(){
    CyclicList lst;


    cout << "Заполнение списка" << endl;
    int n;
    cout<<"введите кол-во элементов которое будет хранится в списке: ";
    cin>>n;
    for (int i=0; i<n; i++){
        cout<<"Введите число: ";
        int num;
        cin>>num;
        lst.push_back(num);
    }
    cout<<"Список заполнен"<<endl;
    int k;
    cout<<"Введите шаг K: ";
    cin>>k;

    lst.printStepK(k);

}


class DoubleLinkList{
private:
    Node* first;
    Node* last;
    Node* current;
public:
    DoubleLinkList(){
        first=last=current=nullptr;
    }
    ~DoubleLinkList(){
        while (first!=nullptr)
        {
            Node* ptr=first;
            first=first->next;
            delete ptr;
        }
    }
    DoubleLinkList(const DoubleLinkList& other){
        first=nullptr;
        last=nullptr;
        current=nullptr;

        Node* ptr=other.first;
        while (ptr!=nullptr)
        {
            this->insertLast(ptr->data);
            ptr=ptr->next;
        }
        

    }

    Node* insertLast(int data){

        Node* ptr=new Node(data);
        ptr->prev=last;
        if (last!=nullptr){
            last->next=ptr;
        }

        if (first==nullptr){
            first=ptr;
        }

        last=ptr;
        current=ptr;
        return ptr;
        }

    void printAdress(){
        cout<<"First: "<<first<<endl;
        cout<<"Last: "<<last<<endl;
        cout<<"Current: "<<current<<endl;
    }
    
    void pop_back(){
        if (first==nullptr){
            return;
        }
        Node* ptr=last->prev;
        if(ptr!=nullptr){
            ptr->next=nullptr;
        }
        else{
            first=nullptr;
        }
  
        delete last;
        last=ptr;

    }
};

void task3(){

    DoubleLinkList lst;
    
    cout << "Заполнение списка" << endl;
    int n;
    cout<<"введите кол-во элементов которое будет хранится в списке: ";
    cin>>n;
    for (int i=0; i<n; i++){
        cout<<"Введите число: ";
        int num;
        cin>>num;
        lst.insertLast(num);
    }
    cout<<"Список заполнен"<<endl;

    lst.printAdress();
}

class BarierList{
private: 
    Node* current;
    Node* barier;
public:
    BarierList(){
        barier=new Node(0);
        barier->next=barier;
        barier->prev=barier;
        current=barier;
    }

    ~BarierList(){
        Node* ptr=current->next;
        while (ptr!=barier)
        {
            Node* ptrDel=ptr;
            ptr=ptr->next;
            delete ptrDel;
            
        }
        delete barier;
    }
    BarierList(const BarierList& other) {
        barier = new Node(0);
        barier->next = barier;
        barier->prev = barier;
        current = barier;
        
        Node* ptr = other.barier->next;
        while (ptr != other.barier) {
            insertLast(ptr->data);
            ptr = ptr->next;
        }
    }

    void insertLast(int data) {
        Node* ptr = new Node(data);
        
        ptr->next = barier;
        ptr->prev = barier->prev;
        barier->prev->next = ptr;
        barier->prev = ptr;
        
        current = ptr;  
    }
    void printAddress() {
        cout<<"Адрес current: "<<current<< endl;
    }

};

void task4(){
    BarierList lst;


    cout << "Заполнение списка" << endl;
    int n;
    cout<<"введите кол-во элементов которое будет хранится в списке: ";
    cin>>n;
    for (int i=0; i<n; i++){
        cout<<"Введите число: ";
        int num;
        cin>>num;
        lst.insertLast(num);
    }
    cout<<"Список заполнен"<<endl;


    lst.printAddress();
}


#include<iostream>
#include<string>
#include<sstream>
#include<locale>
using namespace std;
size_t LettersCount(const string&str){
    size_t len=0;
    for(char c:str){
        if((c&0xC0)!=0x80)len++;
    }
    return len;
}
struct WordNode{
    string data;
    WordNode*next;
    WordNode*prev;
    WordNode(const string& data){
        this->data=data;
        this->next=nullptr;
        this->prev=nullptr;
    }
};
class WordList{
private:
    WordNode*head;
    WordNode*tail;
    size_t maxLength;
public:
    WordList(){
        head=tail=nullptr;
        maxLength=0;
    }
    WordList(const WordList& other){
        head=tail=nullptr;
        maxLength=0;
        WordNode* temp=other.head;
        while(temp!=nullptr){
            addWord(temp->data);
            temp=temp->next;
        }
    }
    ~WordList(){
        while(head!=nullptr){
            WordNode* temp=head;
            head=head->next;
            delete temp;
        }
    }
    void addWord(const string& word){
        if(word.empty())return;
        WordNode*newNode=new WordNode(word);
        if(tail==nullptr){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
        size_t wordLen=LettersCount(word);
        if(wordLen>maxLength){
            maxLength=wordLen;
        }
    }
    void addString(const string& text){
        stringstream ss(text);
        string word;
        while(ss>>word){
            addWord(word);
        }
    }
    void printLength(){
        if(head==nullptr){
            cout<<"Список пустой"<<endl;
            return;
        }
        cout<<"Вывод слов по длине:"<<endl;
        for(size_t len=1;len<=maxLength;len++){
            cout<<"Длина "<<len<<": ";
            bool found=false;
            if(len%2==1){
                WordNode*temp=head;
                while(temp!=nullptr){
                    if(LettersCount(temp->data)==len){
                        cout<<temp->data<<" ";
                        found=true;
                    }
                    temp=temp->next;
                }
            }else{
                WordNode*temp=tail;
                while(temp!=nullptr){
                    if(LettersCount(temp->data)==len){
                        cout<<temp->data<<" ";
                        found=true;
                    }
                    temp=temp->prev;
                }
            }
            if(!found){
                cout<<"В списке нет слов данной длины";
            }
            cout<<endl;
        }
    }
};
void task5(){

    WordList lst;
    cout<<"Введите текст: ";
    cin.ignore();
    string text;
    getline(cin,text);
    lst.addString(text);
    cout<<endl;
    lst.printLength();
}
