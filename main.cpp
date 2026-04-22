#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <locale>
#include <iomanip>

using namespace std;

struct Node {
    wchar_t symbol;
    double freq;
    Node* left;
    Node* right;

    Node(wchar_t s, double f) : symbol(s), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};


void generateCodes(Node* node, const wstring& currentCode, map<wchar_t, wstring>& codes) {
    if (!node) return;

    if (!node->left && !node->right) {
        codes[node->symbol] = currentCode;
        return;
    }

    generateCodes(node->left, currentCode + L"0", codes);   // L"0" - широкий литерал
    generateCodes(node->right, currentCode + L"1", codes);  // L"1" - широкий литерал
}

void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    locale::global(locale("ru_RU.UTF-8"));
    wcout.imbue(locale());
    
    wstring text = L"У РОСТОВЫХ БЫЛИ ИМЕНИННИЦЫ НАТАЛЬИ МАТЬ И МЕНЬШАЯ ДОЧЬ С УТРА НЕ ПЕРЕСТАВАЯ ПОДЪЕЗЖАЛИ И ОТЪЕЗЖАЛИ ЦУГИ ПОДВОЗИВШИЕ ПОЗДРАВИТЕЛЕЙ К БОЛЬШОМУ ВСЕЙ МОСКВЕ ИЗВЕСТНОМУ ДОМУ ГРАФИНИ РОСТОВОЙ НА ПОВАРСКОЙ ГРАФИНЯ С КРАСИВОЙ СТАРШЕЮ ДОЧЕРЬЮ И ГОСТЯМИ НЕ ПЕРЕСТАВШИМИ СМЕНЯТЬ ОДИН ДРУГОГО СИДЕЛИ В ГОСТИНОЙ ГРАФИНЯ БЫЛА ЖЕНЩИНА С ВОСТОЧНЫМ ТИПОМ ХУДОГО ЛИЦА ЛЕТ СОРОКА ПЯТИ ВИДИМО ИЗНУРЕННАЯ ДЕТЬМИ КОТОРЫХ У НЕЙ БЫЛО ДВЕНАДЦАТЬ ЧЕЛОВЕК МЕДЛИТЕЛЬНОСТЬ ЕЕ ДВИЖЕНИЙ И ГОВОРА ПРОИСХОДИВШАЯ ОТ СЛАБОСТИ СИЛ ПРИДАВАЛА ЕЙ ЗНАЧИТЕЛЬНЫЙ ВИД ВНУШАВШИЙ УВАЖЕНИЕ КНЯГИНЯ АННА МИХАЙЛОВНА ДРУБЕЦКАЯ КАК ДОМАШНИЙ ЧЕЛОВЕК СИДЕЛА ТУТ ЖЕ ПОМОГАЯ В ДЕЛЕ ПРИНИМАНИЯ И ЗАНИМАНИЯ РАЗГОВОРОМ ГОСТЕЙ МОЛОДЕЖЬ БЫЛА В ЗАДНИХ КОМНАТАХ НЕ НАХОДЯ НУЖНЫМ УЧАСТВОВАТЬ В ПРИЕМЕ ВИЗИТОВ ГРАФ ВСТРЕЧАЛ И ПРОВОЖАЛ ГОСТЕЙ ПРИГЛАШАЯ ВСЕХ К ОБЕДУ";

    if (text.empty()) {
        wcout << L"Текст пуст!" << endl;
        return 0;
    }

    map<wchar_t, double> freqMap;
    double totalLen = static_cast<double>(text.length());
    
    for (wchar_t ch : text) {
        freqMap[ch]++;
    }

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto& p : freqMap) {
        pq.push(new Node(p.first, p.second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* parent = new Node(0, left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    if (pq.empty()) {
        wcout << L"Ошибка построения дерева!" << endl;
        return 1;
    }
    
    Node* root = pq.top();

    map<wchar_t, wstring> huffmanCodes;
    generateCodes(root, L"", huffmanCodes);

    // 5. Форматированный вывод таблицы
    wcout << L"\n" << setw(12) << L"Символ" 
          << L" | " << setw(10) << L"Частота" 
          << L" | " << setw(12) << L"Вероятность" 
          << L" | " << L"Код Хаффмана" << endl;
    wcout << wstring(60, L'-') << endl; 
    
    wcout << fixed << setprecision(4);
    int z=0;
    
    for (auto& p : freqMap) {
        wstring symDisplay;
        if (p.first == L' ') {
            symDisplay = L"[пробел]";
        } else if (p.first == L'\n') {
            symDisplay = L"[\\n]";
        } else if (p.first == L'\t') {
            symDisplay = L"[\\t]";
        } else {
            symDisplay = wstring(1, p.first);
        }
        
        
        double probability = p.second / totalLen;
        
        wcout << setw(12) << symDisplay 
              << L" | " << setw(10) << p.second 
              << L" | " << setw(12) << probability 
              << L" | " << huffmanCodes[p.first] << endl;  // Теперь типы совместимы
    }
    
    deleteTree(root);
   

    return 0;
}