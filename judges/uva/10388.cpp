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
        string s, r; cin >> s >> r;
        
        int winner = -1;
        string s_t, r_t;
        int s_i = 0, r_i = 0;
        for (int i = 0; i < 1000; ++i) {
            s_t += s[s_i];
            r_t += r[r_i];
            if (s[s_i] == r[r_i]) {
                int k = random() / 141 % 2;
                if (k) {
                    r_t += s_t;
                    s_t = "";
                    cout << "Snap! for John: " << string(r_t.rbegin(), r_t.rend()) << endl;
                } else {
                    s_t += r_t;
                    r_t = "";
                    cout << "Snap! for Jane: " << string(s_t.rbegin(), s_t.rend()) << endl;
                }
            }
            ++s_i; ++r_i;
            if (s_i == s.length()) {
                if (s_t == "") {
                    winner = 1;
                    break;
                }
                s = s_t;
                s_i = 0;
                s_t = "";
            }
            if (r_i == r.length()) {
                if (r_t == "") {
                    winner = 0;
                    break;
                }
                r = r_t;
                r_i = 0;
                r_t = "";
            }
        }

        if (winner == -1) cout << "Keeps going and going ..." << endl;
        else {
            if (winner) cout << "John wins." << endl;
            else cout << "Jane wins." << endl;
        }
        if (t) cout << endl;
    }

    return 0;
}
