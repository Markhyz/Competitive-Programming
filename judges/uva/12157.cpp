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
    int t, tt = 0; cin >> t;

    while (t--) {
        int n; cin >> n;
        int mile = 0, juice = 0;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            mile +=  (x / 30 + 1) * 10;
            juice +=  (x / 60 + 1) * 15;
        }
        
        cout << "Case " << ++tt << ": ";
        if (mile < juice) cout << "Mile " << mile << endl;
        else if (juice < mile) cout << "Juice " << juice << endl;
        else cout << "Mile Juice " << juice << endl;
    }

    return 0;
}
