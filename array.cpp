#include <iostream>

using namespace std;

void mystery (int A[], int n) {
int temp, i, j;
for (i = 0; i < n; i++) {
if (A[i]%2 == 0) {
temp = A[i];
for (j = i; j > 0; j--){
A[j] = A[j-1];
}
A[0] = temp;
} // end if
for(int c = 0; c < n; c++){
cout << A[c] << " ";
}
cout <<endl;
} // end for
} // end function

int main() {
    int n = 6;
    int arr[] = {1,2,3,4,5,6};
    mystery(arr, n);

}