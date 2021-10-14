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
    int g, s, c; cin >> g >> s >> c;
    int t = g * 3 + s * 2 + c;

    if (t >= 8) cout << "Province or ";
    else if (t >= 5) cout << "Duchy or ";
    else if (t >= 2) cout << "Estate or ";

    if (t >= 6) cout << "Gold" << endl;
    else if (t >= 3) cout << "Silver" << endl;
    else cout << "Copper" << endl;

    return 0;
}