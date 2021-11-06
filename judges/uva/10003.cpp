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

#define MAXN 55

int v[MAXN], dp[MAXN][MAXN];

int main() {
    int l; 
    
    while (cin >> l && l) {
        int n; cin >> n;
        for (int i = 1; i <= n; ++i) cin >> v[i];
        v[n + 1] = l;

        memset(dp, 0, sizeof dp);
        for (int k = 2; k <= n + 1; ++k) {
            for (int i = 0; i <= n + 1 - k; ++i) {
                dp[i][i + k] = 1e9;
                for (int j = i + 1; j < i + k; ++j) {
                    dp[i][i + k] = min(dp[i][i + k], dp[i][j] + dp[j][i + k] + v[i + k] - v[i]);
                }
            }
        }

        cout << "The minimum cutting is " << dp[0][n + 1] << "." << endl;
    }

    return 0;
}
