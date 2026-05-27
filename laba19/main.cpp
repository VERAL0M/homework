#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <locale>
#include <limits>

using namespace std;

bool isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

void printBits(const vector<int>& bits) {
    for (int b : bits) wcout << b;
    wcout << endl;
}

void task1() {
    wstring inputStr = L"0010100001010";
    vector<int> message;
    for (wchar_t c : inputStr) message.push_back(c - L'0');
    int k = message.size();

    wcout << L"Код Хемминга (k=" << k << L")\n";
    wcout << L"Исходное сообщение: "; printBits(message);

    int m = 0;
    while ((1 << m) < k + m + 1) m++;
    int n = k + m;
    wcout << L"Контрольных битов: m = " << m << L"\n";
    wcout << L"Длина кодового слова: n = " << n << L"\n\n";

    vector<int> code(n);
    int msgIdx = 0;
    for (int pos = 1; pos <= n; ++pos) {
        if (isPowerOfTwo(pos)) code[pos - 1] = 0;
        else code[pos - 1] = message[msgIdx++];
    }

    for (int p = 1; p <= n; p <<= 1) {
        if (p > n) break;
        int parity = 0;
        for (int i = 1; i <= n; ++i) if (i & p) parity ^= code[i - 1];
        code[p - 1] = parity;
    }

    wcout << L"Кодовое слово: "; printBits(code);
    wcout << L"Позиции контрольных битов: 1, 2, 4, 8, 16\n\n";

    int errPos;
    wcout << L"Введите позицию ошибки (1-" << n << L"): ";
    wcin >> errPos;
    if (errPos < 1 || errPos > n) { wcout << L"Неверная позиция\n"; return; }

    vector<int> received = code;
    received[errPos - 1] ^= 1;
    wcout << L"Принято с ошибкой: "; printBits(received);

    int syndrome = 0;
    for (int j = 0; j < m; ++j) {
        int p = 1 << j;
        int parityCheck = 0;
        for (int i = 1; i <= n; ++i) if (i & p) parityCheck ^= received[i - 1];
        if (parityCheck) syndrome |= p;
    }

    wcout << L"Синдром (десятичный): " << syndrome << L"\n";
    if (syndrome != 0) {
        wcout << L"Ошибка в позиции " << syndrome << L". Исправлено.\n";
        received[syndrome - 1] ^= 1;
    } else {
        wcout << L"Ошибок нет.\n";
    }

    vector<int> decoded;
    for (int pos = 1; pos <= n; ++pos)
        if (!isPowerOfTwo(pos)) decoded.push_back(received[pos - 1]);

    wcout << L"Восстановлено: "; printBits(decoded);
    wcout << L"Исходное:       "; printBits(message);
}

struct Node {
    wchar_t ch;
    int freq;
    Node* left;
    Node* right;
    Node(wchar_t c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct CompareNode {
    bool operator()(Node* a, Node* b) { return a->freq > b->freq; }
};

void generateCodes(Node* root, wstring code, map<wchar_t, wstring>& codes) {
    if (!root) return;
    if (!root->left && !root->right) codes[root->ch] = code;
    generateCodes(root->left, code + L'0', codes);
    generateCodes(root->right, code + L'1', codes);
}

void printTree(Node* node, int level) {
    if (!node) return;
    for (int i = 0; i < level; i++) wcout << L"  ";
    if (!node->left && !node->right) wcout << L"[" << node->ch << L":" << node->freq << L"]\n";
    else wcout << L"{" << node->freq << L"}\n";
    printTree(node->left, level + 1);
    printTree(node->right, level + 1);
}

void deleteTree(Node* node) {
    if (!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

void task2() {
    wstring text = L"у ёлки иголки колки.";
    map<wchar_t, int> freq;
    for (wchar_t c : text) freq[c]++;

    priority_queue<Node*, vector<Node*>, CompareNode> pq;
    for (auto& p : freq) pq.push(new Node(p.first, p.second));

    while (pq.size() > 1) {
        Node* l = pq.top(); pq.pop();
        Node* r = pq.top(); pq.pop();
        Node* p = new Node(0, l->freq + r->freq);
        p->left = l; p->right = r;
        pq.push(p);
    }

    Node* root = pq.top();
    map<wchar_t, wstring> codes;
    generateCodes(root, L"", codes);

    wcout << L"\nКоды Хаффмана:\n";
    for (auto& p : freq) wcout << L"'" << p.first << L"' -> " << codes[p.first] << L"\n";

    wcout << L"\nДерево:\n";
    printTree(root, 0);

    int uniformBits = 0;
    while ((1 << uniformBits) < freq.size()) uniformBits++;
    if (uniformBits == 0) uniformBits = 1;

    int total = text.length();
    int sizeUniform = total * uniformBits;
    int sizeHuffman = 0;
    for (auto& p : freq) sizeHuffman += p.second * codes[p.first].length();

    wcout << L"\nРавномерный код: " << sizeUniform << L" бит\n";
    wcout << L"Код Хаффмана: " << sizeHuffman << L" бит\n";

    deleteTree(root);
}

void task3() {
    wstring text;
    int key, mode;
    wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
    wcout << L"Введите текст: ";
    getline(wcin, text);
    wcout << L"Введите ключ: ";
    wcin >> key;
    wcout << L"1 - шифрование, 2 - дешифрование: ";
    wcin >> mode;

    wstring alpha = L"АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдежзийклмнопрстуфхцчшщъыьэюя";
    wstring result;
    int len = alpha.length();
    int shift = (mode == 1) ? key : -key;

    for (size_t i = 0; i < text.length(); ++i) {
        size_t pos = alpha.find(text[i]);
        if (pos != wstring::npos) {
            int new_pos = (pos + shift) % len;
            if (new_pos < 0) new_pos += len;
            result += alpha[new_pos];
        } else {
            result += text[i];
        }
    }

    if (mode == 1) wcout << L"Зашифровано: " << result << L"\n";
    else wcout << L"Расшифровано: " << result << L"\n";
}

int main() {
    setlocale(LC_ALL, "");
    wcout.imbue(locale(""));
    wcin.imbue(locale(""));

    int n = 1;
    while (n != 0) {
        wcout << L"1. Код Хемминга\n";
        wcout << L"2. Код Хаффмана\n";
        wcout << L"3. Шифр Цезаря\n";
        wcout << L"0. Выход\n";
        wcout << L"Выберите задачу: ";
        wcin >> n;
        switch (n) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 0: wcout << L"Выход.\n"; break;
            default: wcout << L"Нет такой задачи.\n"; break;
        }
        wcout << L"\n";
    }
    return 0;
}