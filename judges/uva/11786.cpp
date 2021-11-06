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
    int t; cin >> t;

    while (t--) {
        string s; cin >> s;
        vi v(s.length());
        int h = 0, mn = 1e9;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '/') ++h;
            else if (s[i] == '\\') --h;
            mn = min(mn, h);
            v[i] = h;
        }
        for (int i = 0; i < v.size(); ++i) {
            v[i] -= mn;
        }
        
        vi hs(s.length());
        int res = 0;
        for (int i = 1; i <= s.length(); ++i) {
            char c = s[i - 1];
            int h = v[i - 1];
            if (c == '/') {
                if (hs[h - 1]) {
                    res += i - hs[h - 1];
                    hs[h - 1] = 0;
                }
            } else if (c == '\\') {
                hs[h] = i;
            }
        }

        cout << res << endl;
    }

    return 0;
}
