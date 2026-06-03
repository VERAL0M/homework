#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <locale>

using namespace std;

void task_graf2() {
    ifstream fin("FileName1");
    if (!fin) {
        cout << "Oshibka: net faila FileName1\n";
        return;
    }

    int n;
    fin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin >> a[i][j];
        }
    }
    fin.close();

    int m = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] == 1) {
                m++;
            }
        }
    }

    vector<vector<int>> b(n, vector<int>(m, 0));
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] == 1) {
                b[i][k] = 1;
                b[j][k] = 1;
                k++;
            }
        }
    }

    ofstream fout("FileName2");
    if (!fout) {
        cout << "Oshibka: ne udalos sozdat FileName2\n";
        return;
    }

    fout << n << " " << m << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fout << b[i][j] << " ";
        }
        fout << "\n";
    }
    fout.close();
    cout << "Rezultat v faile FileName2.\n";
}

void task_graf7() {
    ifstream fin("FileName");
    if (!fin) {
        cout << "Oshibka: net faila FileName\n";
        return;
    }

    int n;
    fin >> n;
    
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin >> g[i][j];
        }
    }

    int k1, k2, L;
    fin >> k1 >> k2 >> L;
    fin.close();

    auto get_dist = [&](int start) {
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v = 0; v < n; v++) {
                if (g[u][v] == 1 && dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
    };

    vector<int> d1 = get_dist(k1 - 1);
    vector<int> d2 = get_dist(k2 - 1);

    vector<int> res;
    int max_d = L + 1; 

    for (int i = 0; i < n; i++) {
        if (i != k1 - 1 && i != k2 - 1) { 
            if (d1[i] != -1 && d2[i] != -1 && d1[i] <= max_d && d2[i] <= max_d) {
                res.push_back(i + 1);
            }
        }
    }

    if (res.empty()) {
        cout << "-1\n";
    } else {
        for (int x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

void task_graf9() {
    ifstream fin("FileName1");
    if (!fin) {
        cout << "Oshibka: net faila FileName1\n";
        return;
    }

    int n;
    fin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin >> mat[i][j];
        }
    }

    int k1, k2, L;
    if (!(fin >> k1 >> k2 >> L)) {
        cout << "Vvedite K1, K2, L cherez probel: ";
        cin >> k1 >> k2 >> L;
    }
    fin.close();

    vector<vector<int>> results;
    
    auto dfs = [&](auto& self, int u, int target, int steps_left, vector<int>& path, vector<bool>& visited) -> void {
        if (steps_left == 0) {
            if (u == target) {
                results.push_back(path);
            }
            return;
        }
        
        for (int v = 1; v <= n; v++) {
            if (mat[u - 1][v - 1] == 1 && !visited[v]) {
                visited[v] = true;
                path.push_back(v);
                
                self(self, v, target, steps_left - 1, path, visited);
                
                path.pop_back();
                visited[v] = false;
            }
        }
    };

    vector<int> path;
    vector<bool> visited(n + 1, false);
    
    path.push_back(k1);
    visited[k1] = true;

    dfs(dfs, k1, k2, L + 1, path, visited);

    ofstream fout("FileName2");
    if (!fout) {
        cout << "Oshibka sozdaniya FileName2\n";
        return;
    }

    if (results.empty()) {
        fout << -1 << "\n";
    } else {
        fout << results.size() << "\n";
        for (const auto& r : results) {
            for (size_t j = 0; j < r.size(); j++) {
                fout << r[j] << (j + 1 == r.size() ? "" : " ");
            }
            fout << "\n";
        }
    }
    fout.close();


    cout << "  /\\_/\\  \n";
    cout << " ( o.o ) \n";
    cout << "  > ^ <  \n";
}

int main() {
    setlocale(LC_ALL, "");

    int n = 1;
    while (n != 0) {
        cout << "1. Graf2 (Matritsa intsidentnosti)\n";
        cout << "2. Graf7 (Sfery vliyaniya)\n";
        cout << "3. Graf9 (Marshruty s peresadkami)\n";
        cout << "0. Vykhod\n";
        cout << "Vyberite zadachu: ";
        cin >> n;
        
        switch (n) {
            case 1: task_graf2(); break;
            case 2: task_graf7(); break;
            case 3: task_graf9(); break;
            case 0: cout << "Vykhod.\n"; break;
            default: cout << "Net takoy zadachi.\n"; break;
        }
        cout << "\n";
    }
    return 0;
}