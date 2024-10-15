#include <bits/stdc++.h>
using namespace std;
#define tests int t; cin >> t; while (t--)
#define ll long long
#define ln '\n'

ll n = 1;
vector<ll> v(n);

void mergeSort(ll left, ll mid, ll right) {
    ll n1 = mid - left + 1;
    ll n2 = right - mid;

    ll* L = new ll[n1];
    ll* R = new ll[n2];

    for (ll i = 0; i < n1; i++) {
        L[i] = v[left + i];
    }
    for (ll j = 0; j < n2; j++) {
        R[j] = v[mid + 1 + j];
    }

    ll i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k++] = L[i++];
        } else {
            v[k++] = R[j++];
        }
    }

    while (i < n1) {
        v[k++] = L[i++];
    }
    while (j < n2) {
        v[k++] = R[j++];
    }

    delete[] L;
    delete[] R;
}

void merge(ll left, ll right) {
    if (left >= right) return;

    ll mid = (left + (right)) / 2;

    merge(left, mid);
    merge(mid + 1, right);
    mergeSort(left, mid, right);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    v.resize(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }

    merge(0, n - 1);

    for (ll i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << ln;

    return 0;
}
