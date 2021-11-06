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
    int n, b, h, w; 
    
    while (cin >> n >> b >> h >> w) {
        int res = 1e9;
        for (int i = 0; i < h; ++i) {
            int p; cin >> p;
            for (int j = 0; j < w; ++j) {
                int a; cin >> a;
                if (a >= n && n * p <= b) res = min(res, n * p);
            }
        }

        if (res == 1e9) cout << "stay home" << endl;
        else cout << res << endl;
    }

    return 0;
}
