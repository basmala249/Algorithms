#include <iostream>
using namespace std;

void ShellSort(int obj[] , int size){
    int temp;
    for(int i = size / 2 ; i >= 1 ; i/= 2) {
        for (int j = i, m; j < size; ++j) {
            temp = ob[j];
            for (m = j; m - i >= 0 and temp > ob[m - i]; m -= i) {
                ob[m] = ob[m - i];
            }
            ob[m] = temp;
        }
    }
}

void print(int arr[] , int n){
    for(int j = 0 ; j < n ; ++j){
            cout <<  arr[j] << " ";
        }
        cout << endl;
}
int main() {
    int n ;
    cin >> n;
    int arr[n];
    for(int j = 0 ; j < n ; ++j){
            cin >> arr[j];
    }
    print(arr , n);
    ShellSort(arr,n);
    print(arr,n);
    return 0;
}
