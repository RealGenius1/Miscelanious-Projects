#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

const int SIZE = 26;

int main() {
    string datafile;
    cout << "Enter filename: ";
    getline(cin, datafile);
    ifstream file(datafile);
    if(!file) {
        cout << "Unable to open file.";
        return 1;
    }
    cout << endl;

    string word;
    int charCount = 0;
    int vars[SIZE] = { 0 };

    while(file >> word) {
        for(char& c : word) {
            charCount++;
            if(!isalpha(c)){
                charCount--;
            } else {
                c = tolower(c);
                vars[c - 'a']++;
            }
        }
    }

    cout << "Total number of letters: " << charCount << endl;
    cout << "Frequency:\n";

    for(int i = 0; i < SIZE; i++) {
        cout << "'" << static_cast<char>('A' + i) << "': " << fixed << setprecision(3) << (vars[i] / double(charCount)) * 100 << endl;
    }
    return 0;
}