#include <iostream>
using namespace std;
#define ll long long
// fib using recursion
ll fibonaci1(ll n) {
    if(n <= 1)return n;
    return fibonaci1(n-1) + fibonaci1(n-2);
}
//fib using dp
const ll N = 1e6 + 2;
ll dp[N];
ll fibonaci2(ll n) {
    if(n <= 1)return n;
    ll &ret = dp[n];
    if(ret != -1)return ret;
    ret = fibonaci2(n-1) + fibonaci2(n-2);
    return ret;
}
//fib using matrix maltiplication
ll arr[2][2] = {{1, 1}, {1, 0}};
ll dp1[N];
void fibonacci3(ll n) {
    if (n == 1) return;

    fibonacci3(n / 2);

    ll a = arr[0][0], b = arr[0][1];
    ll c = arr[1][0], d = arr[1][1];

    arr[0][0] = a * a + b * c;
    arr[0][1] = a * b + b * d;
    arr[1][0] = a * c + c * d;
    arr[1][1] = b * c + d * d;

    if (n % 2 == 1) {
        ll temp0 = arr[0][0] * 1 + arr[0][1] * 1;
        ll temp1 = arr[0][0] * 1 + arr[0][1] * 0;
        ll temp2 = arr[1][0] * 1 + arr[1][1] * 1;
        ll temp3 = arr[1][0] * 1 + arr[1][1] * 0;

        arr[0][0] = temp0;
        arr[0][1] = temp1;
        arr[1][0] = temp2;
        arr[1][1] = temp3;
    }
    dp1[n] = arr[0][0];
    dp1[n - 1] = arr[0][1];
    dp1[n - 2] = arr[1][1];
    // cout << arr[0][0] << " " << arr[0][1] << endl;
    // cout << arr[1][0] << " " << arr[1][1] << endl;
}

//iterative sequential
ll SequentialIterative(ll A[] ,ll n ,ll target ) {
    for(ll i = 0 ; i < n ; i++) {
        if(A[i] == target)return i;
    }
    return -1;
}

// iterative binary search
ll IterativeBinarySearch(ll A[] ,ll n ,ll target ) {
    ll left = 0,right = n-1;
    while(left <= right) {
        ll mid = (left + right) / 2;
        if(A[mid] == target)return mid;
        else if(A[mid] < target)left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
// recursive binary search
ll BinarySearch(ll A[] , ll left , ll right ,ll target ) {
    if(left > right) return -1;
    ll mid = (left + right) / 2;
   // cout << left << " " << mid << " " << right << endl;
    if(A[mid] == target) return mid;
    if(A[mid] < target) return BinarySearch(A,mid + 1,right,target);
    if(A[mid] > target) return BinarySearch(A,left,mid - 1,target);
}
//recursive sequential
ll recursiveSequential(ll A[] ,ll n ,ll target ) {
    if(n < 0)return -1;
    if(A[n] == target) return n;
    return recursiveSequential(A,n - 1,target);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i = 0 ; i < N ; i++) {
        dp[i] = -1;
       // dp1[i] = -1;
    }
    //cout << fibonaci1(5) << "\n";
    //cout << fibonaci2(5) << "\n";
    // ll n ;
    // cin >> n;
    // ll a[n];
    // for(ll i = 0 ; i < n ; i++) {
    //     cin >> a[i];
    // }
    // ll target;
    // cin >> target;
    // cout << BinarySearch(a,0,n - 1 ,target) << endl;
    // cout << SequentialIterative(a,n , target) << endl;
    // cout << recursiveSequential(a,n - 1, target) << endl;
    // cout << IterativeBinarySearch(a,n , target) << endl;
    ll q;
    cin >> q;
    fibonacci3(N);
    cout << dp1[q] << endl;
    return 0;
}
