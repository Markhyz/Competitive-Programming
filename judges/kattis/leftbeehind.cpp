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
    int a, b;
    while (cin >> a >> b && a | b) {
        if (a + b == 13) cout << "Never speak again." << endl;
        else if (a > b) cout << "To the convention." << endl;
        else if (a < b) cout << "Left beehind." << endl;
        else cout << "Undecided." << endl;
    }
    return 0;
}