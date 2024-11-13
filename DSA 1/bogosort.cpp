#include <iostream>
#include <algorithm>
#include <random>

using namespace std;


bool isSorted(int A[], int n){
    for(int i = 1; i < n; i++){
        if(A[i-1] > A[i]){
            return false;
        }
    }
    return true;
}

void bogosort(int A[], int n, int& count){
    count++;
    random_shuffle(A, A+n);
    if(!isSorted(A,n)){
        bogosort(A,n,count);
    }
}

int main(){
    srand(time(0));
    int count = 0;
    int A[] = {1,2,3,4,5};
    bogosort(A,5, count);
    for(int i = 0; i < 5; i++){
        cout << A[i] << ", ";
    }
    cout << endl << "Count: " << count;
}