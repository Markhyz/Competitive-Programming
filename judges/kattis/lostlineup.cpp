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
typedef vector<double> vd;

int main() {
    int n; cin >> n;
    vi v(n + 1);

    v[1] = 1;
    for (int i = 2; i <= n; ++i) {
        int x; cin >> x;
        v[x + 2] = i;
    }
    
    for (int i = 1; i <= n; ++i)
        cout << v[i] << " ";
    cout << endl;

    return 0;
}
