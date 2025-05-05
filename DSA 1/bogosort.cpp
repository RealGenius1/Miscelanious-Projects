#include <random>
#include <iostream>

using namespace std;

void shuffle(int A[], int n){
    for(int i = 0; i < n; i++){
        int j = rand() % (n - i) + i;
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}

bool isSorted(int A[], int n){
    for(int i = 0; i < n - 1; i++){
        if(A[i] > A[i+1]){
            return false;
        }
    }
    return true;
}

void bogosort(int A[], int n){
    while(!isSorted(A,n)){
        shuffle(A,n);
    }
}

int main() {
    srand(time(0));
    int A[] = {1,4,5,9,7};
    int n = 5;
    bogosort(A,5);
    for(int i = 0; i < n - 1; i++){
        cout << A[i] << ", ";
    }
    cout << A[n-1];
}