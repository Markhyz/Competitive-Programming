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
    int n; cin >> n;

    vs v;
    for (int i = 0; i < 5; ++i) {
        string s; cin >> s;
        v.push_back(s);
    }

    string res;
    for (int i = 0; i < n; ++i) {
        int k = 0;
        for (int j = 0; j < 5; ++j) {
            if (v[j][i * 4] == '*') ++k;    
        }
        if (k == 0) res += "1";
        if (k == 4) res += "2";
        if (k == 3) res += "3";
    }

    cout << res << endl;

    return 0;
}