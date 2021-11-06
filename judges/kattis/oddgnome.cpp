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

int main() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        vi gnomes(n);
        for (int i = 0; i < n; ++i)
            cin >> gnomes[i];

        int res = n - 2;        
        for (int i = 1; i < n - 1; ++i) {
            if (gnomes[i] < gnomes[i - 1]) {
                if (gnomes[i + 1] > gnomes[i - 1]) {
                    res = i;
                } else res = i - 1;
                break;
            }
        }

        cout << res + 1 << endl;
    }

    return 0;
}
