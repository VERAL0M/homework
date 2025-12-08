#include <iostream>
#include <ctime>

using namespace std;

string random_string(string russian_letters){
    int len_word;
    string word="";
    cout<<"Введите длину слова";
    cin>>len_word;
    srand(time(0));
    int index;

    for (int i=0; i<len_word; i++){
        index = rand()%33;
        word+=russian_letters[index];


    }

    return word;

}
int main(){
    string word;
    word = random_string("ЙЦУКЕНГШЩЗХЪФЫВАПРО ЛДЖЭЯЧСМИТЬБЮЁ");
    cout<<word;

}