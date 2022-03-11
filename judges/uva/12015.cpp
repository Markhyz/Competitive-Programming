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
    int t, tt = 0; cin >> t;

    while (t--) {
        vs websites(10);
        vi scores(10);
        int mx = 0;
        for (int i = 0; i < 10; ++i) {
            cin >> websites[i] >> scores[i];
            mx = max(mx, scores[i]);
        }
        cout << "Case #" << ++tt << ":" << endl;
        for (int i = 0; i < 10; ++i) {
            if (scores[i] == mx) cout << websites[i] << endl;
        }
    }

    return 0;
}