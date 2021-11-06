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
    int x, y, n; cin >> x >> y >> n;

    for (int i = 1; i <= n; ++i) {
        if (i % x == 0 && i % y == 0) {
            cout << "FizzBuzz" << endl;
        } else if (i % x == 0) {
            cout << "Fizz" << endl;
        } else if (i % y == 0) {
            cout << "Buzz" << endl;
        } else {
            cout << i << endl;
        }
    }
}
