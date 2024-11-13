#include <iostream>
#include <string>

using namespace std;

int count_words(string str);

int main(){
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    cout << "Letters: " << count_words(str);
}

int count_words(string str){
    int count = 0;
    for(int i = 0; i < str.length(); i++){
        isalpha(str[i]) ? count++ : count+=0;
    }
    return count;
}