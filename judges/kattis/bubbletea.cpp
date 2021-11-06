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

int cards[200];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vi tea(n);
    for (int i = 0; i < n; ++i)
        cin >> tea[i];
    int m; cin >> m;
    vi topping(m);
    for (int i = 0; i < m; ++i)
        cin >> topping[i];
    int mn = 1e9;
    for (int i = 0; i < n; ++i) {
        int k; cin >> k;
        for (int j = 0; j < k; ++j) {
            int x; cin >> x; --x;
            mn = min(mn, tea[i] + topping[x]);
        }
    }
    int total; cin >> total;

    cout << max(0, total / mn - 1) << endl;

    return 0;
}
