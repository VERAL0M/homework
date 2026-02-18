#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main() {
    ifstream fin("input1.txt");
    int N, Z;
    fin >> N >> Z;
    
    vector<int> c(N + 1), d(N + 1);
    for (int i = 1; i <= N; i++) fin >> c[i];
    for (int i = 1; i <= N; i++) fin >> d[i];
    fin.close();
    
    // Максимальный возможный вес - сумма всех весов
    int maxWeight = 0;
    for (int i = 1; i <= N; i++) maxWeight += c[i];
    
    // dp[i][w] - минимальный налог для первых i предметов с весом w
    vector<vector<int>> dp(N + 1, vector<int>(maxWeight + 1, INF));
    vector<vector<bool>> choice(N + 1, vector<bool>(maxWeight + 1, false));
    
    // База
    dp[0][0] = 0;
    
    // Заполнение таблицы ДП
    for (int i = 1; i <= N; i++) {
        for (int w = 0; w <= maxWeight; w++) {
            // Вариант 1: не берем i-й предмет
            dp[i][w] = dp[i-1][w];
            
            // Вариант 2: берем i-й предмет
            if (w >= c[i]) {
                int newTax = dp[i-1][w - c[i]] + d[i];
                if (newTax < dp[i][w]) {
                    dp[i][w] = newTax;
                    choice[i][w] = true;
                }
            }
        }
    }
    
    // Поиск ответа - минимальный налог при весе > Z
    int minTax = INF;
    int bestWeight = -1;
    
    for (int w = Z + 1; w <= maxWeight; w++) {
        if (dp[N][w] < minTax) {
            minTax = dp[N][w];
            bestWeight = w;
        }
    }
    
    // Восстановление набора предметов
    vector<int> selected;
    int i = N, w = bestWeight;
    while (i > 0 && w > 0) {
        if (choice[i][w]) {
            selected.push_back(i);
            w -= c[i];
        }
        i--;
    }
    
    // Вывод результатов
    cout << "Номера артефактов: ";
    for (int idx : selected) {
        cout << idx << " ";
    }
    cout << endl;
    
    cout << "Суммарный вес: " << bestWeight << " кг" << endl;
    cout << "Суммарный налог: " << minTax << endl;
    
    return 0;
}