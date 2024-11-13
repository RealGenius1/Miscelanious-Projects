#include <iostream>
#include <climits>

using namespace std;

void Merge(int A[], int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;
    int* L = new int[n1+1];
    int* R = new int[n2+1];
    for(int i = 0; i < n1; i++){
        L[i] = A[p+i];
    }
    for(int i =0; i < n2; i++){
        R[i] = A[q+i+1];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    int i = 0;
    int j = 0;
    for(int k = p; k <= r; k++){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
    delete [] L;
    delete [] R;
}



/*
@param p is the beggining of the array (default 0)
@param r is the size of array
*/
void MergeSort(int A[], int p, int r){
    if(p<r){
        int q = ((p+r) / 2);
        cout <<"p: " << p << "    q: " << q << endl;
        MergeSort(A,p,q);
        cout << "q+1: " << q+1 << "      r: " << r << endl;
        MergeSort(A,q+1,r);
        cout << "Merging:   p: " << p << "     q: " << q << "     r: " << r << endl;
        Merge(A,p,q,r);
    }
}




int main() {
    int A[] = {5,8,2,1,7};
    MergeSort(A,0,4);
    for(int i = 0; i < 5; i++){
        cout << A[i] << ", ";
    }
}