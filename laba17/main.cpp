#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

//CalcTree8
class Node8 {
public:
    int data;
    Node8 *left, *right;
    Node8(int d) : data(d), left(nullptr), right(nullptr) {}
};

class Validator8 {
public:
    static bool isOp(int c) { return c >= -6 && c <= -1; }
    static bool isNum(int c) { return c >= 0 && c <= 9; }
    static int toCode(char c) {
        switch(c) {
            case '+': return -1; case '-': return -2; case '*': return -3;
            case '/': return -4; case '%': return -5; case '^': return -6;
        } return 0;
    }
    static char toChar(int c) {
        switch(c) {
            case -1: return '+'; case -2: return '-'; case -3: return '*';
            case -4: return '/'; case -5: return '%'; case -6: return '^';
        } return '?';
    }
};

void printTree8(Node8* root, int level) {
    if (!root) return;
    printTree8(root->right, level + 1);
    for(int i=0; i<level; i++) cout << setw(4) << ' ';
    if (Validator8::isOp(root->data)) cout << setw(4) << Validator8::toChar(root->data) << endl;
    else cout << setw(4) << root->data << endl;
    printTree8(root->left, level + 1);
}

int calcNode8(int op, int l, int r) {
    switch(op) {
        case -1: return l+r; case -2: return l-r; case -3: return l*r;
        case -4: return l/r; case -5: return l%r; case -6: return (int)pow(l,r);
    } return 0;
}


void transform8(Node8*& root) {
    if (!root) return;
    transform8(root->left);
    transform8(root->right);
    if (Validator8::isOp(root->data) && root->left && root->right &&
        Validator8::isNum(root->left->data) && Validator8::isNum(root->right->data)) {
        int res = calcNode8(root->data, root->left->data, root->right->data);
        delete root->left; delete root->right;
        root->left = root->right = nullptr;
        root->data = res; 
    }
}

void runTask8() {
    cout << "\n   CalcTree8 \nВыберите ввод: 1-клава, 2-файл, 3-строка\n> ";
    int ch; cin >> ch;
    string expr;
    if (ch == 1) { cout << "Выражение: "; cin.ignore(); getline(cin, expr); }
    else if (ch == 2) { string fn; cout << "Файл: "; cin >> fn; ifstream f(fn); if(f) getline(f, expr); f.close(); }
    else expr = "+ * 3 4 - 8 2";

    istringstream iss(expr);
    string tok;
    stack<Node8*> st;
    vector<string> tokens;
    while(iss >> tok) tokens.push_back(tok);

    // Построение из префиксной записи (справа налево)
    for (int i = tokens.size()-1; i >= 0; i--) {
        string& s = tokens[i];
        int val;
        if (s.length()==1 && !isdigit(s[0])) val = Validator8::toCode(s[0]);
        else val = stoi(s);
        
        Node8* node = new Node8(val);
        if (Validator8::isOp(val) && st.size() >= 2) {
            node->left = st.top(); st.pop();
            node->right = st.top(); st.pop();
        }
        st.push(node);
    }
    Node8* root = st.empty() ? nullptr : st.top();

    cout << "\nДо преобразования:\n"; printTree8(root, 0);
    transform8(root);
    cout << "\nПосле преобразования:\n"; printTree8(root, 0);
    cout << "Адрес корня: " << root << " | Значение корня: " << (root ? root->data : 0) << endl;

 
    stack<Node8*> del; if(root) del.push(root);
    while(!del.empty()) {
        Node8* cur = del.top(); del.pop();
        if(cur) { if(cur->left) del.push(cur->left); if(cur->right) del.push(cur->right); delete cur; }
    }
}

//CalcTree26) 
struct TNode26 { int Data; TNode26 *Left, *Right; };
typedef TNode26* PNode26;

int Priority26(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '^') return 3;
    return -1;
}

int searchBracket26(string s, int k) {
    int cnt = 1;
    while (cnt != 0) { k--; if(s[k]==')') cnt++; if(s[k]=='(') cnt--; }
    return k;
}


int SearchOp26(string s, int pr) {
    int k = s.length()-1; bool found = false;
    while (k >= 0 && !found) {
        if (s[k] == ')') k = searchBracket26(s, k);
        if (k >= 0 && Priority26(s[k]) == pr) found = true;
        else k--;
    }
    return found ? k : -1;
}

int OpCode26(char ch) {
    switch(ch) {
        case '+': return -1; case '-': return -2; case '*': return -3;
        case '/': return -4; case '%': return -5; case '^': return -6;
    } return 0;
}

char OpChar26(int op) {
    switch(op) {
        case -1: return '+'; case -2: return '-'; case -3: return '*';
        case -4: return '/'; case -5: return '%'; case -6: return '^';
    } return ' ';
}

PNode26 CreateTree26(string s) {
    while(s.size() && s[0]==' ') s.erase(0,1);
    while(s.size() && s.back()==' ') s.pop_back();
    if(s.size()>1 && s[0]=='(' && s.back()==')' && searchBracket26(s, s.size()-1)==0) {
        s.erase(0,1); s.pop_back();
    }
    int k = SearchOp26(s, 1);
    if(k==-1) k = SearchOp26(s, 2);
    if(k==-1) k = SearchOp26(s, 3);
    
    if(k==-1) {
        PNode26 n = new TNode26;
        n->Data = (s=="x") ? -100 : stoi(s);
        n->Left = n->Right = nullptr;
        return n;
    }
    PNode26 n = new TNode26;
    n->Data = OpCode26(s[k]);
    n->Left = CreateTree26(s.substr(0, k));
    n->Right = CreateTree26(s.substr(k+1));
    return n;
}

void PrintTree26(PNode26 r, int lvl, ostream& out) {
    if(!r) return;
    PrintTree26(r->Right, lvl+1, out);
    for(int i=0; i<lvl; i++) out << setw(8) << ' ';
    if(r->Data < 0 && r->Data != -100) out << setw(8) << OpChar26(r->Data) << endl;
    else if(r->Data == -100) out << setw(8) << 'x' << endl;
    else out << setw(8) << r->Data << endl;
    PrintTree26(r->Left, lvl+1, out);
}

int Calc26(PNode26 r, int x) {
    if(r->Data == -100) return x;
    if(r->Data >= 0) return r->Data;
    int l = Calc26(r->Left, x);
    int rv = Calc26(r->Right, x);
    switch(r->Data) {
        case -1: return l+rv; case -2: return l-rv; case -3: return l*rv;
        case -4: return l/rv; case -5: return l%rv; case -6: return (int)pow(l,rv);
    } return 0;
}

void Transform26(PNode26 r, int x) {
    if(!r) return;
    if(r->Data == -100) { r->Data = x; return; }
    Transform26(r->Left, x);
    Transform26(r->Right, x);
}

void Del26(PNode26 r) {
    if(r) { Del26(r->Left); Del26(r->Right); delete r; }
}

void runTask26() {
    ifstream fin("FN1.txt");
    string expr;
    if(!fin) { cout << "Ошибка: файл FN1.txt не найден\n"; return; }
    getline(fin, expr);
    fin.close();

    int x; cout << "Введите значение x: "; cin >> x;

    PNode26 root = CreateTree26(expr);

    cout << "\nИсходное дерево:\n";
    PrintTree26(root, 0, cout);

    int res = Calc26(root, x);
    cout << "Результат при x=" << x << ": " << res << endl;

    Transform26(root, x);

    ofstream fout("FN2.txt");
    fout << res << endl;
    PrintTree26(root, 0, fout);
    fout.close();

    Del26(root);
    cout << "Преобразованное дерево и результат записаны в FN2.txt\n";
}

//MAIN 
int main() {
    setlocale(LC_ALL, "ru");
    int choice;

    do {
        cout << "\n ВЫБОР ЗАДАЧИ \n";
        cout << "1. CalcTree8 \n";
        cout << "2. CalcTree26\n";
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;
        
        if(choice == 1) runTask8();
        else if(choice == 2) runTask26();
    } while(choice != 0);
    
    return 0;
}