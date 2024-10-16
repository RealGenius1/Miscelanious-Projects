#include <iostream>

using namespace std;

void selectionSort(int A[], int n) { // A=array pointer, n=A.length
	int minVal = A[0];
	int swaps = 0;
	int minIndex = 0;
	for(int i = 0; i < n; i++){
		minVal = A[i];
		minIndex = i;
for(int j = i + 1; j < n; j++){
		if(A[j] < minVal){
				swaps++;
				minVal = A[j];
				minIndex = j;
			}
}
int temp = A[i];
A[i] = A[minIndex];
A[minIndex] = temp;
}
cout << "Number of swaps: " << swaps << endl;
}
	
void insertionSort(int A[], int n) {
		for (int i = 1; i < n; i++) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }

}

void flaggedBubbleSort(int A[], int n) { // A=array pointer, n=A.length
	bool hasSwapped = false;
	int numSwaps = 0;
	int numInners = 0;
	do{
		hasSwapped = false;
		for(int i = 1; i < n; i++){
			numInners++;
			if(A[i-1] > A[i]){
				numSwaps++;
				int temp = A[i];
				A[i] = A[i-1];
				A[i-1] = temp;
				hasSwapped = true;
			}
			}
}while(hasSwapped);
cout << "Number of swaps: " << numSwaps << endl << "Number of times inner loop ran: " << numInners << endl;
}

int main() {
int n=20;
int A[20]={3, 4, 20, 16, 17, 13, 2, 14, 8, 7, 19, 10, 11, 12, 15, 18, 9, 5, 6, 1};
  			selectionSort(A, n);
  			for (int i=0; i<n; i++)
    				cout << A[i] << " ";
			cout << endl;
}
