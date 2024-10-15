#include <iostream>
using namespace std;

void SelectionSort(int A[] , int n){
    for(int i = 0 ; i < n - 1 ; ++i){
        int least = i;
        for(int j = i + 1 ; j < n ; ++j ){
            if(A[least] > A[j]){
                least = j;
            }
        }
        if(least != i){
            swap(A[i] , A[least]);
        }
    }
}

void print(int arr[] ,  int n){
   for(int i = 0 ; i < n ; ++i){
      cout << arr[i] << " " ;
   }
  cout << '\n';
}
  
int main() {
  int n ;
  cin >> n;
  int arr[n];
  for(int i = 0 ; i < n ; ++i){
      cin >> arr[i] ;
  }
  print(arr , n);
  SelectionSort(arr , n);
  print(arr , n);
}
