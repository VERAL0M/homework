#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int layer = min(min(i, j), min(n - 1 - i, n - 1 - j));
            int base = 4 * layer * (n - layer);
            
            if (i == layer) {
                cout << base + (j - layer) + 1 << " ";
            } else if (j == n - layer - 1) {
                cout << base + (n - 2 * layer - 1) + (i - layer) + 1 << " ";
            } else if (i == n - layer - 1) {
                cout << base + 2 * (n - 2 * layer - 1) + (n - layer - 1 - j) + 1 << " ";
            } else {
                cout << base + 3 * (n - 2 * layer - 1) + (n - layer - 1 - i) + 1 << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
