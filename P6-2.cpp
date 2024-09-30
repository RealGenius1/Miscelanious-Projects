#include <iostream>

using namespace std;

int main() {
    int input = 0;
    cout << "Please input number of rows: ";
    cin >> input;
    int totSpace = input - 1;
    //the leading up ones
    for(int i = 0; i < input; i++){
        int numSpace = totSpace - i;
        //These 2 give the leading characters
        for(int j = 0; j < numSpace; j++){
            cout<<" ";
        }
        for(int k = 0; k < i; k++){
            cout<<"*";
        }
        //I am now at the pivot point
        cout<<"*";
        //now for the trailing characters
        for(int k = 0; k < i; k++){
            cout<<"*";
        }
        for(int j = 0; j < numSpace; j++){
            cout<<" ";
        }
        cout<<endl;
    }
    //I now need to run down the list
    for(int i = totSpace - 1; i > -1; i--){
        // cout <<i<<endl;
        int numSpace = totSpace - i;
        //The leading characters
        for(int j = 0; j < numSpace; j++){
            cout<<" ";
        }
        for(int k = 0; k < i; k++){
            cout<<"*";
        }
        //now I am at the pivot again
        cout<<"*";
        //now the trailing
        for(int k = 0; k < i; k++){
            cout<<"*";
        }
        for(int j = 0; j < numSpace; j++){
            cout<<" ";
        }
        cout<<endl;
    }
}