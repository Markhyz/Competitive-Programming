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
    int a, c;

    while (cin >> a >> c && a | c) {
        int last = a;
        int res = 0;
        for (int i = 0; i < c; ++i) {
            int x; cin >> x;
            if (x < last) res += last - x;
            last = x;
        }

        cout << res << endl;
    }

    return 0;
}
