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
    int t; cin >> t;

    int res = 0;
    while (t--) {
        double l, w, d, weight; cin >> l >> w >> d >> weight;
        int l2 = l * 100, w2 = w * 100, d2 = d * 100, weight2 = weight * 100;
        bool good = false;
        if (weight2 <= 700) {
            if ((l2 <= 5600 && w2 <= 4500 && d2 <= 2500) || l2 + w2 + d2 <= 12500) {
                cout << 1 << endl;
                ++res;
                good = true;
            }
        }
        if (!good) cout << 0 << endl;
    }

    cout << res << endl;

    return 0;
}