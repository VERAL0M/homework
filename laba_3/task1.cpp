#include <iostream>
#include <fstream>
#include <string>

int main() {
    using namespace std;

    ifstream f1;
    f1.open("d.txt", ios::in);

    if (!f1.is_open()) {
        cerr << "Ошибка открытия файла." << endl;
        return 1;
    }

    int word;
    int max_el=-100000000, min_el=1000000, diffrent_el;


    while (f1 >> word) {
        if (max_el<=word){
            max_el=word;
        }
        if (min_el>=word){
            min_el=word;
        }
    }
    f1.close();
    diffrent_el=max_el-min_el;
    cout<<diffrent_el;

    
    return 0;
}