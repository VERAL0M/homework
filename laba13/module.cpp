#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <numeric>
#include <deque>
#include <cctype>

using namespace std;

vector<int> random_generic(){
    int a,b;
    cout<<"Введите число а и b (от скольки элементов массив и до скольки элементов максив вы хотите): ";
    cin>>a>>b;
    srand(time(0));
    vector<int> v;
    
    for(int i=0; i<a+rand()%b; i++){
        if ((a+rand()%b)%2==0) v.push_back(0);
        else v.push_back(1);
        
    }
    return v;
}
void printV(vector<int> v){
    cout<<"Вектор V: ";
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}


void STL3Alg8(){
    vector<int> v=random_generic();
    printV(v);
    int k;
    cout<<"Введите k>0: ";
    cin>>k;
    if (k>0){
        auto it=search_n(v.rbegin(), v.rend(), k, 0 );
        if (it != v.rend()) {
            auto itDirect=it.base();
          
            
            auto directBegin =  itDirect - k;
            v.erase(directBegin, itDirect);

            cout<<"Уделено "<<k<<" нулей c конца"<<endl;
            cout<<"===Обновлённый вектор==="<<endl;
            printV(v);
        }
        else{ 
            cout<<"Последовательность не найдена"<<endl<<endl;;
            cout<<"===Вектор оставлен без изменений==="<<endl;
            printV(v);
        }

    }
    else cout<<"K введено не корректно!"<<endl;
    cout<<endl;

}


    
list<int> random_genericList(){
    int a,b,k;
    cout<<"Введите число а, b, k-кол-во элементов в списке(должно делиться на 4) (от скольки до скольки могут принимать значения элементы масива): ";
    cin>>a>>b>>k;
    if (k%4==0){
        srand(time(0));
        list<int> v;
        
        for(int i=0; i<k; i++){
            
            v.push_back(a+rand()%b);
            
        }
        return v;
    }
    else {
        cout<<"K должно делиться на 4!";
        return {}; 
    }

}  
void print_list(list<int>& lst) {
    
    for (int x : lst) cout<<x<<" ";
    cout<<endl;
}

void STL3Alg23() {
    list<int> l1=random_genericList();
    list<int> l2=random_genericList();
    if (l1.empty() || l2.empty()){
        cout<<"Ошибка! Список пустой";
        return;

    } 
    cout<<"Только что созданые списки "<<endl;
    print_list(l1);
    print_list(l2);
    int n1=l1.size();
    int n2=l2.size();

    auto it1_beg = l1.begin();
    auto it1_mid = l1.begin();
    
    advance(it1_mid, n1/ 2); 

    auto it1_q = l1.begin();
    advance(it1_q, n1 / 4);

    swap_ranges(it1_beg, it1_q, make_reverse_iterator(it1_mid));

    auto it2_mid = l2.begin();
    advance(it2_mid, n2 / 2); 
    auto it2_end = l2.end();

    reverse(it2_mid, it2_end);

    cout<<"Списки после изменений "<<endl;
    print_list(l1);
    print_list(l2);
}


list<int> random_genericListChet(){
    int a,b,k;
    cout<<"Введите число а, b, k-кол-во элементов в списке(должно делиться на 2) (от скольки до скольки могут принимать значения элементы масива): ";
    cin>>a>>b>>k;
    if (k%2==0){
        srand(time(0));
        list<int> v;
        
        for(int i=0; i<k; i++){
            
            v.push_back(a+rand()%b);
            
        }
        return v;
    }
    else {
        cout<<"K должно быть чётным числом!";
        return {}; 
    }
}

void STL3Alg43() {
    list<int> L = random_genericListChet();
    if (L.empty()) {
        cout<<"Ошибка! Список пустой"<<endl;
        return;
    }
    cout <<"Исходный список: ";
    print_list(L);

    int n = L.size();
    auto mid = L.begin();
    advance(mid, n / 2);

    stable_partition(L.begin(), mid, [](int x) { return x % 2 == 0; });
    stable_partition(mid, L.end(), [](int x) { return x % 2 != 0; });

    cout << "Список после перегруппировки: ";
    print_list(L);
}



struct CombinePairs {
    string operator()(const string& left, const string& right) const {
        if (left.empty() || right.empty()) return "";
        return string() +  right.front() + left.back();
    }
};

list<string> inputList() {
    list<string> L;
    int n;
    cout << "Введите количество слов: ";
    cin >> n;
    if (n < 2) {
        cout << "Минимум 2 слова!" << endl;
        return L;
    }
    cout << "Введите слова:\n";
    for (int i=0; i < n; i++) {
        string s;
        cin >> s;
        for (char z: s){
            if (!isupper(z)){
                cout<<"Ошибка! Слова должны быть с заглавной буквы "<<endl;
                return {};
            }
        }
        L.push_back(s);
    }
    return L;
}

void STL3Alg61() {
    list<string> L=inputList();
    if (L.size()<2) return;

    deque<string> D;
    adjacent_difference(L.begin(), L.end(), back_inserter(D), CombinePairs());
    
    D.erase(D.begin());

    cout<<"Дек D: ";
    for (const auto& s : D) {
        cout<<s<<" ";
    }
    cout<<endl;
}

