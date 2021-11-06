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
    int n, a, b; 
    
    while (cin >> n >> a >> b) {
        if (a > b) swap(a, b);
        int res = 1;
        while (b - a != 1 || a % 2 == 0) {
            a = (a + a % 2) / 2;
            b = (b + b % 2) / 2;
            ++res;
        }

        cout << res << endl;
    }

    return 0;
}
