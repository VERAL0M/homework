#include <iostream>
#include <string>
#include <limits>
#include "play.h"

using namespace std;

void push_back(Deck& deck, int value) {
    Node* new_node = new Node(value);
    if (deck.tail == nullptr) {
        // Колода пустая
        deck.head = deck.tail = new_node;
    } else {
        deck.tail->next = new_node;
        deck.tail = new_node;
    }
    deck.size++;
}

bool pop_front(Deck& deck, int& out_value) {
    if (deck.head == nullptr) return false;  
    
    Node* temp = deck.head;
    out_value = temp->value;
    deck.head = deck.head->next;
    
    if (deck.head == nullptr) {
        deck.tail = nullptr;  
    }
    
    delete temp;
    deck.size--;
    return true;
}


void clear_deck(Deck& deck) {
    int dummy;
    while (pop_front(deck, dummy)) {}
}

void show_deck(const Deck& deck, const string& name) {
    cout << name << ": ";
    Node* current = deck.head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << "(" << deck.size << " карт)\n";
}


bool isWin(int c1, int c2) {

    if (c1 == 0 && c2 == 9) return true;
    if (c2 == 0 && c1 == 9) return false;

    return c1 > c2;
}

bool readCards(Deck& deck) {
    for (int i = 0; i < 5; i++) {
        int card;
        if (!(cin >> card)) {
            return false;  
        }
        if (card < 0 || card > 9) {
            return false;
        }
        push_back(deck, card);
    }
    return true;
}

void playDurachok() {
    Deck player1, player2;
    
    cout << "\n--- Начало игры в 'Пьяницу' ---\n";
    cout << "Введите 5 карт первого игрока (0-9, через пробел):\n> ";
    
    if (!readCards(player1)) {
        cout << "Ошибка ввода! Карты должны быть числами от 0 до 9.\n";
        return;
    }
    
    cout << "Введите 5 карт второго игрока (0-9, через пробел):\n> ";
    
    if (!readCards(player2)) {
        cout << "Ошибка ввода! Карты должны быть числами от 0 до 9.\n";
        clear_deck(player1);
        return;
    }
    
    cout << "\nКарты розданы!\n";
    show_deck(player1, "Игрок 1");
    show_deck(player2, "Игрок 2");
    cout << "\n";

    int moves = 0;
    const int MAX_MOVES = 1000000;

    while (player1.size > 0 && player2.size > 0 && moves < MAX_MOVES) {
        moves++;
        
        int c1, c2;
        pop_front(player1, c1);  
        pop_front(player2, c2); 
        if (isWin(c1, c2)) {
            push_back(player1, c1);
            push_back(player1, c2);
        } else {
            push_back(player2, c1);
            push_back(player2, c2);
        }
    }
    cout << "\n--- Результат ---\n";
    if (moves >= MAX_MOVES) {
        cout << "botva\n";
    } else if (player1.size == 0) {
        cout << "second " << moves << "\n";
    } else {
        cout << "first " << moves << "\n";
    }

    clear_deck(player1);
    clear_deck(player2);
}



void showMenu() {
    cout << "\n================================\n";
    cout << "       ИГРА В ПЬЯНИЦУ\n";
    cout << "================================\n";
    cout << "1. Начать игру\n";
    cout << "2. Правила игры\n";
    cout << "3. Выход\n";
    cout << "================================\n";
    cout << "Выберите пункт: ";
}

void showRules() {
    cout << "\n--- Правила игры ---\n";
    cout << "В игре 10 карт со значениями от 0 до 9.\n";
    cout << "Колода делится поровну между двумя игроками (по 5 карт).\n";
    cout << "Каждый ход игроки вскрывают верхнюю карту.\n";
    cout << "Тот, чья карта старше, забирает обе карты под низ своей колоды.\n";
    cout << "Особое правило: карта 0 бьёт карту 9!\n";
    cout << "Победитель - тот, кто соберёт все карты.\n";
    cout << "Если игра не заканчивается за 1000000 ходов - ничья (botva).\n";
    cout << "--------------------\n";
}