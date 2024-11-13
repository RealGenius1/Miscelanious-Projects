#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int highest_score(int arr[], int n);
int lowest_score(int arr[], int n);
double average_score(int arr[], int n);

int main(){
    int num = 0;
    cout << "Number of students: ";
    cin >> num;
    int score[num];
    for(int i = 0; i < num; i++){
        cout << "Score #" << i + 1 << ": ";
        cin >> score[i];
    }
    sort(score,score+num);
    cout << "Highest Score: " << highest_score(score,num) << endl;
    cout << "Lowest Score: " << lowest_score(score,num) << endl;
    cout << "Average Score: " << average_score(score,num) << endl;
}

int highest_score(int arr[], int n){
    return arr[n-1];
}

int lowest_score(int arr[], int n){
    return arr[0];
}

double average_score(int arr[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    return (double) sum/n;
}