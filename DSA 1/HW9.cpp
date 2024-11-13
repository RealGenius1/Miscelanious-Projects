#include <iostream>

using namespace std;


int partition(int A[], int p, int r){
    int pivot = A[r];
    int i = p-1;
    for(int j = p; j < r; j++){
        if(A[j] <= pivot){
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    int temp = A[i+1];
    A[i+1] = A[r];
    A[r] = temp;
    return i+1;
}

void quicksort(int A[], int p, int r){
    if(p<r){
        int q = partition(A,p,r);
        cout << "q: " << q <<"       A[q]: " << A[q] << endl;
        cout << "p: " << p << "      q-1: " << q-1 << endl;
        quicksort(A,p,q-1);
        cout << "q+1: " << q+1 << "       r: " << r << endl;
        quicksort(A,q+1,r);
    }
}

int main() {
    int arr[] = {12,4,5,6,7,3,1,15};
    quicksort(arr, 0, 7);
    for(int i = 0; i < 8; i++){
        cout << arr[i] <<", ";
    }
}