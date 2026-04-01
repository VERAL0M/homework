#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <deque>
#include <algorithm>

using namespace std;
void task1() {
    int n;
    cout<<"Введите N кратное 3: ";
    cin>>n;

    if (n%3!=0) {
        cout<<"Введёно значение не кратно 3"<<endl;
        return;
    }

    vector<int> v(n);
    for (int i = 0; i<n; i++) {
        cout<<"Введите число: ";
        cin >> v[i];
    }

    list<int> l(v.begin(), v.end());

    int k = n/3;
    auto it = l.begin();

    for (int i=0; i<k; i++) {
        cout << *it << " ";
        it++;
    }
    cout << endl;

    auto it2 = it;
    for (int i = 0; i < k; i++) {
        it2++;
    }

    list<int> l2(it, it2);
    for (auto rit = l2.rbegin(); rit != l2.rend(); rit++) {
        cout << *rit << " ";
    }
    cout << endl;

    auto it3 = l.end();
    list<int> l3(it2, it3);
    for (auto rit = l3.rbegin(); rit != l3.rend(); rit++) {
        cout << *rit << " ";
    }
    cout << endl;
}


void task2() {
    int n;
    cout<<"Введите чётное число N: ";
    cin>>n;

    if (n%2!=0) {
        cout<<"N должно быть четным"<< endl;
        return;
    }
    vector<int> v(n);
    
    for (int i = 0; i < n; i++) {
        cout<<"Введите число: ";
        cin >> v[i];
    }

    deque<int> d(v.begin(), v.end());

    int k=n/2;
    for (int i=0; i< k;i++) {
        d.insert(d.begin() +i*2,1, -1);
    }

    for (auto it = d.begin(); it!=d.end(); it++) {
        cout<<*it<<" ";
    }
    cout<<endl;

}





void task3() {
    int n;
    cout<<"Введите размер списка L: ";
    cin>>n;

    vector<int> vL(n);
    for (int i=0; i<n; i++) {
        cout<<"Введите число: ";
        cin>>vL[i];
    }
    list<int> l(vL.begin(), vL.end());

    int m;
    cout<<"Введите размер дека D число должно быть чётное: ";
    cin>>m;

    if (m%2!=0) {
        cout<<"размер D должен быть чётным!"<<endl;
        return;
    }

    vector<int> vD(m);
    for (int i = 0; i < m; i++) {
        cout<<"Введите число: ";
        cin>>vD[i];
    }
    deque<int> d(vD.begin(), vD.end());

    int k=m/2;

    l.insert(l.begin(), d.begin(), d.begin()+k);
    d.erase(d.begin(), d.begin()+k);

    cout << "Список L: ";
    for (auto it = l.begin(); it!=l.end(); it++) {
        cout<<*it<<" ";
    }
    cout << endl;

    cout << "Дек D: ";
    for (auto it=d.begin(); it !=d.end(); it++) {
        cout<< *it<< " ";
    }
    cout<<endl;

    return;
}




void task4() {
    double A, D;
    int N;
    cout << "Введите A, D, N, и количество первых членов: ";
    istream_iterator<double> in(cin);
    A = *in++;
    D = *in++;
    N = (int)*in++;

    generate_n(ostream_iterator<double>(cout, " "), N, [A, D]() mutable {
        double val = A;
        A += D;
        return val;
    });

    cout << endl;
    return;
}