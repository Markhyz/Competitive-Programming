#include <bits/stdc++.h>

using namespace std;

#define SHIFTL(x, y) ((x) << (y))
#define SHIFTR(x, y) ((x) >> (y))

#define BIT(x) (1LL << (x))

typedef long long ll;
typedef unsigned long long ull;
typedef tuple<int, int> i2;
typedef tuple<int, int, int> i3;
typedef tuple<int, int, int, int> i4;
typedef vector<int> vi;
typedef vector<i2> vi2;
typedef vector<i3> vi3;
typedef vector<vi2> v2i2;
typedef vector<string> vs;
typedef vector<ll> vll;

int main() {
    int n, m; cin >> n >> m;

    if (n < m) {
        if (m - n == 1) cout << "Dr. Chaz will have 1 piece of chicken left over!" << endl;
        else cout << "Dr. Chaz will have " << m - n << " pieces of chicken left over!" << endl;
    } else {
        if (n - m == 1) cout << "Dr. Chaz needs 1 more piece of chicken!" << endl;
        else cout << "Dr. Chaz needs " << n - m <<  " more pieces of chicken!" << endl;
    } 

    return 0;
}