#include <iostream>
#include <fstream>

int main(){
    using namespace std;

    ifstream f1;
    f1.open("c.txt", ios::in);
    string  first_line,  word;
    int max_length =0;
    
    f1>>first_line;

    bool sravny=true;
 
    


    while (f1>>word)
    {
 
        max_length += (((word.size()> max_length) & sravny) * (word.size() - max_length));
  
        cout<<word<<" ";
    }
    cout<<"answer: "<<max_length;
    
}