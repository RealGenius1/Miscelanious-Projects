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
    int count = 1;
    for(int i = 1; i < str.length(); i++){
        count += (str[i] == ' ' && str[i-1] != ' ');
    }
    return count;
}