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
    vi v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());

    int k1 = v[1] - v[0], k2 = v[2] - v[1];
    if (k1 == k2) cout << v[2] + k1 << endl;
    else if (k1 > k2) cout << v[0] + k1 / 2 << endl;
    else cout << v[1] + k2 / 2 << endl;

    return 0;
}
