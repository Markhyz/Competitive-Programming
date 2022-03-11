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
typedef vector<vi> v2i;
typedef vector<vi2> v2i2;
typedef vector<string> vs;
typedef vector<ll> vll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int a, b;

    while (cin >> a >> b && a | b) {
        set<int> as, bs;
        for (int i = 0; i < a; ++i) {
            int x; cin >> x;
            as.insert(x);
        }
        for (int i = 0; i < b; ++i) {
            int x; cin >> x;
            bs.insert(x);
        }
        int ax = 0;
        for (int x : bs) {
            if (!as.count(x)) ++ax;
        }
        int bx = 0;
        for (int x : as) {
            if (!bs.count(x)) ++bx;
        }
        cout << min(ax, bx) << endl;
    }

    return 0;
}