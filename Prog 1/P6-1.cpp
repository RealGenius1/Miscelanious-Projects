#include <iostream>

using namespace std;

int main() {
    int input = 0;
    cout << "Please input side length: ";
    cin >> input;
    //funny loop for top edge
    for(int j = 0; j < 2; j++){
        for(int i = 0; i < input; i++){
            cout<<"*";
        }
        cout<<" ";
    }
    cout<<endl;
    //funny loop for sides
    for(int j = 0; j < ((input / 2) + 1); j++){
        for(int i = 0; i < input; i++){
            cout<<"*";
        }
        cout <<" *";
        //loop for spaces
        for(int i = 0; i < ((input/2) + 1); i++){
            cout<<" ";
        }
        cout<<"*"<<endl;
    }
    //loop for end
        for(int j = 0; j < 2; j++){
        for(int i = 0; i < input; i++){
            cout<<"*";
        }
        cout<<" ";
    }
}