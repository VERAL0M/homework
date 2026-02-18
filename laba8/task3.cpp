#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int K, N;
    cout << "Введите основание системы счисления K (2-10): ";
    cin >> K;
    cout << "Введите количество разрядов N (1-20): ";
    cin >> N;
    
    // Проверка ограничений
    if (K < 2 || K > 10 || N <= 1 || N >= 20 || N + K >= 26) {
        cout << "Некорректные входные данные!" << endl;
        return 1;
    }
    
    // DP массив: dp[pos][consecutive_zeros]
    // pos от 0 до N, consecutive_zeros от 0 до 3
    vector<vector<double>> dp(N + 1, vector<double>(4, 0.0));
    
    // Инициализация для первой позиции
    // Первая цифра не может быть нулём
    dp[1][0] = K - 1;  // ставим любую ненулевую цифру
    // На первой позиции не может быть нуля, поэтому zeros=1,2,3 остаются 0
    
    // Заполнение DP
    for (int pos = 2; pos <= N; pos++) {
        for (int zeros = 0; zeros <= 3; zeros++) {
            if (dp[pos-1][zeros] == 0) continue;
            
            // Вариант 1: ставим ненулевую цифру
            // Можно поставить любую из (K-1) цифр
            dp[pos][0] += dp[pos-1][zeros] * (K - 1);
            
            // Вариант 2: ставим ноль (если можно)
            if (zeros < 3) {
                dp[pos][zeros + 1] += dp[pos-1][zeros];
            }
        }
    }
    
    // Суммируем все варианты для последней позиции
    double result = 0;
    for (int zeros = 0; zeros <= 3; zeros++) {
        result += dp[N][zeros];
    }
    
    cout << fixed << setprecision(0);
    cout << "Количество " << N << "-разрядных чисел в системе с основанием " << K;
    cout << " без 4+ подряд нулей: " << result << endl;
    
    return 0;
}