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
        string s, t; cin >> s >> t;
        
        int res = 0;
        int zeros = 0, ones = 0, w_zeros = 0, w_ones = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == t[i]) continue;
            if (s[i] == '0') {
                ++zeros;
            }
            if (s[i] == '1') {
                ++ones;
            }
            if (s[i] == '?') {
                if (t[i] == '0') {
                    ++w_zeros;
                } else {
                    ++w_ones;
                }
            }
        }

        int mn = min(ones, zeros);
        res += mn;
        zeros -= mn;
        ones -= mn;

        if (zeros > 0) {
            res += zeros;
        } else if (ones > 0) {
            int mn2 = min(ones, w_ones);
            ones -= mn2;
            w_ones -= mn2;
            if (ones > 0) res = -1;
            else res += mn2 * 2;
        }

        if (res != -1) res += w_ones + w_zeros;

        cout << "Case " << ++tt << ": " << res << endl;
    }

    return 0;
}
