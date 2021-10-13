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
    int t; cin >> t;
    
    while (t--) {
        ll n; cin >> n;

        int x = (-1 + sqrt(1 + 8 * n)) / 2;

        cout << x << endl;
    }

    return 0;
}