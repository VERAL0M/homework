#include "module.h"
#include <ctime>

void BinaryTree::insertRec(PNode& p, int val) {
    if (!p) { p = new Node(val); return; }
    if (val < p->key) insertRec(p->left, val);
    else insertRec(p->right, val);
}

void BinaryTree::deleteRec(PNode& p) {
    if (!p) return;
    deleteRec(p->left);
    deleteRec(p->right);
    delete p;
    p = nullptr;
}

int BinaryTree::countRec(PNode p) const {
    if (!p) return 0;
    return 1 + countRec(p->left) + countRec(p->right);
}

void BinaryTree::infixCollect(PNode p, vector<int>& out) const {
    if (!p) return;
    infixCollect(p->left, out);
    out.push_back(p->key);
    infixCollect(p->right, out);
}

void BinaryTree::printRec(PNode p, int level) const {
    if (!p) return;
    printRec(p->right, level + 1);
    for (int i = 0; i < level; i++) cout << "    ";
    cout << p->key << endl;
    printRec(p->left, level + 1);
}

BinaryTree::BinaryTree() : root(nullptr) {}
BinaryTree::~BinaryTree() { deleteRec(root); }

void BinaryTree::insert(int val) { insertRec(root, val); }
void BinaryTree::printTree() const { printRec(root, 0); }
int BinaryTree::size() const { return countRec(root); }
bool BinaryTree::isEmpty() const { return root == nullptr; }
vector<int> BinaryTree::getInfix() const {
    vector<int> res;
    infixCollect(root, res);
    return res;
}

void BinaryTree::taskTreeWork8() const {
    if (isEmpty()) { cout << "Дерево пустое!" << endl; return; }
    cout << "Результат инфиксного обхода: ";
    vector<int> res = getInfix();
    for (int v : res) cout << v << " ";
    cout << endl;
}

void BinaryTree::taskTreeWork10(int x) {
    insert(x);
    cout << "Значение " << x << " вставлено." << endl;
}

void BinaryTree::taskTreeWork18() const {
    if (isEmpty()) { cout << "Дерево пустое." << endl; return; }
    PNode parent = nullptr;
    PNode current = root;
    while (current->right != nullptr) {
        parent = current;
        current = current->right;
    }
    if (current->left != nullptr) {
        PNode second = current->left;
        while (second->right != nullptr) second = second->right;
        cout << "Второе максимальное значение: " << second->key << endl;
    } else {
        if (parent == nullptr) cout << "В дереве только одна вершина." << endl;
        else cout << "Второе максимальное значение: " << parent->key << endl;
    }
}

void TreeVerifier::runChecks(const BinaryTree& tree) {
    cout << "\nКЛАСС ПРОВЕРОК" << endl;
    cout << "Дерево не пустое: " << (tree.isEmpty() ? "НЕТ" : "ДА") << endl;
    cout << "Количество вершин: " << tree.size() << endl;
    vector<int> res = tree.getInfix();
    cout << "Элементов в выводе: " << res.size() << endl;
    cout << "Все вершины пройдены: " << (tree.size() == res.size() ? "ДА" : "НЕТ") << endl;
    bool sorted = true;
    for (size_t i = 1; i < res.size(); i++) {
        if (res[i] < res[i-1]) { sorted = false; break; }
    }
    cout << "Вывод отсортирован: " << (sorted ? "ДА" : "НЕТ") << endl;
    cout << endl;
}

void inputFromKeyboard(BinaryTree& tree) {
    int n, val;
    cout << "Введите количество элементов: ";
    cin >> n;
    cout << "Введите " << n << " чисел: ";
    for (int i = 0; i < n; i++) { cin >> val; tree.insert(val); }
}

void inputFromFile(BinaryTree& tree) {
    string filename;
    cout << "Введите имя файла: ";
    cin >> filename;
    ifstream f(filename);
    if (!f.is_open()) { cerr << "Ошибка: файл не найден!" << endl; return; }
    int val;
    while (f >> val) tree.insert(val);
}

void inputFromRandom(BinaryTree& tree) {
    int n;
    cout << "Введите размер: ";
    cin >> n;
    srand(time(0));
    cout << "Случайные числа: ";
    for (int i = 0; i < n; i++) {
        int val = rand() % 100;
        cout << val << " ";
        tree.insert(val);
    }
    cout << endl;
}

void task1() {
    int choice;
    cout << "Выберите способ ввода:\n1. Клавиатура\n2. Файл\n3. Случайные числа\nВаш выбор: ";
    cin >> choice;
    BinaryTree tree;
    if (choice == 1) inputFromKeyboard(tree);
    else if (choice == 2) inputFromFile(tree);
    else if (choice == 3) inputFromRandom(tree);
    else { cout << "Неверный выбор.\n"; return; }
    cout << "\nГРАФИЧЕСКОЕ ПРЕДСТАВЛЕНИЕ ДЕРЕВА ДО ПРЕОБРАЗОВАНИЯ:\n";
    tree.printTree();
    cout << "\nTreeWork8 (инфиксный обход):\n";
    tree.taskTreeWork8();
    cout << "\nГРАФИЧЕСКОЕ ПРЕДСТАВЛЕНИЕ ДЕРЕВА ПОСЛЕ ПРЕОБРАЗОВАНИЯ:\n";
    tree.printTree();
    TreeVerifier::runChecks(tree);
}

void task2() {
    int choice;
    cout << "Выберите способ ввода:\n1. Клавиатура\n2. Файл\n3. Случайные числа\nВаш выбор: ";
    cin >> choice;
    BinaryTree tree;
    if (choice == 1) inputFromKeyboard(tree);
    else if (choice == 2) inputFromFile(tree);
    else if (choice == 3) inputFromRandom(tree);
    else { cout << "Неверный выбор.\n"; return; }
    cout << "\nГРАФИЧЕСКОЕ ПРЕДСТАВЛЕНИЕ ДЕРЕВА ДО ПРЕОБРАЗОВАНИЯ:\n";
    tree.printTree();
    int x;
    cout << "\nВведите значение X: ";
    cin >> x;
    cout << "\nTreeWork10 (вставка X):\n";
    tree.taskTreeWork10(x);
    cout << "\nГРАФИЧЕСКОЕ ПРЕДСТАВЛЕНИЕ ДЕРЕВА ПОСЛЕ ПРЕОБРАЗОВАНИЯ:\n";
    tree.printTree();
    TreeVerifier::runChecks(tree);
}

void task3() {
    int choice;
    cout << "Выберите способ ввода:\n1. Клавиатура\n2. Файл\n3. Случайные числа\nВаш выбор: ";
    cin >> choice;
    BinaryTree tree;
    if (choice == 1) inputFromKeyboard(tree);
    else if (choice == 2) inputFromFile(tree);
    else if (choice == 3) inputFromRandom(tree);
    else { cout << "Неверный выбор.\n"; return; }
    cout << "\nГРАФИЧЕСКОЕ ПРЕДСТАВЛЕНИЕ ДЕРЕВА ДО ПРЕОБРАЗОВАНИЯ:\n";
    tree.printTree();
    cout << "\nTreeWork18 (второе максимальное значение):\n";
    tree.taskTreeWork18();
    cout << "\nГРАФИЧЕСКОЕ ПРЕДСТАВЛЕНИЕ ДЕРЕВА ПОСЛЕ ПРЕОБРАЗОВАНИЯ:\n";
    tree.printTree();
    TreeVerifier::runChecks(tree);
}

void task4() { cout << "Задача 4 не реализована.\n"; }
void task5() { cout << "Задача 5 не реализована.\n"; }