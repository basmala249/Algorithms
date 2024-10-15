#include <iostream>
using namespace std;

void bubbleSort(int A[] , int n){
    for (int  i = 0 ; i < n - 1 ; ++i){
        bool sawp = false;
        for(int j = n - 1 ; j > i ; --j){
            if(A[j] < A[j - 1] ){
                swap(A[j] , A[j - 1]);
                sawp = true;
            }
        }
        if(!sawp)break;
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
  bubbleSort(arr , n);
  print(arr , n);
}
