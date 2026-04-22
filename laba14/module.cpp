#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <string>
#include <cctype>
using namespace std;

void STL5Assoc3() {
    int N;
    cout << "Введите N (количество векторов V1..VN): ";
    cin >> N;
    if (N <= 0) {
        cout << "Ошибка! N должно быть больше 0"<<endl;
        return;
    }
    int sz0;
    cout<<"Введите размер вектора V0: ";
    cin>>sz0;
    vector<int> V0(sz0);
    cout << "Введите элементы V0: "<<endl;
    for (int i = 0; i < sz0; ++i) cin >> V0[i];

    multiset<int> ms0(V0.begin(), V0.end());
    int matchCount = 0;

    for (int i = 1; i <= N; ++i) {
        int szI;
        cout << "Введите размер вектора V" << i << ": ";
        cin >> szI;
        vector<int> Vi(szI);
        cout << "Введите элементы V" << i << ": "<<endl;
        for (int j = 0; j < szI; ++j) cin >> Vi[j];

        multiset<int> msi(Vi.begin(), Vi.end());
        if (includes(ms0.begin(), ms0.end(), msi.begin(), msi.end())) {
            ++matchCount;
        }
    }
    cout << "\nРезультат: " << matchCount << " вектор(ов) содержат все элементы V0."<<endl;
}

void STL5Assoc15() {
    int n;
    cout << "Введите количество элементов вектора V: ";
    cin >> n;
    vector<int> V(n); 
    cout << "Введите элементы вектора V:"<<endl;
    for (int i = 0; i < n; i++) cin >> V[i];

    map<int, int> M;
    for (auto it = V.begin(); it != V.end(); it++) {
        M[*it]++;
    }

    cout << "Результат (элемент количество):"<<endl;
    for (auto mit = M.begin(); mit != M.end(); mit++) {
        cout << mit->first << " " << mit->second << endl;
    }
}

void STL5Assoc22() {
    int n;
    cout << "Введите количество слов: ";
    cin >> n;
    vector<string> V(n); 
    cout << "Введите слова (заглавными буквами):\n";
    for (int i = 0; i < n; i++) {
        cin >> V[i];
        for (char z: V[i]){
            if (!isupper(z)){
                cout<<"Ошибка. Слова должны быть с заглавной буквы!"<<endl;
                return;
            }
        }

    }

    multimap<char, string> M;
    for (auto& word : V) {
        M.insert({word.back(), word});
    }

    cout << "Результат группировки: "<<endl;
    for (auto& p : M) {
        cout << p.first << " " << p.second << endl;
    }
}