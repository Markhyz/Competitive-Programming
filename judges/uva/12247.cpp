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

vi v;

int getNext(int x) {
    for (int i = x + 1; i <= 52; ++i) {
        if (!v[i]) return i;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int a, b, c, x, y;

    while (cin >> a >> b >> c >> x >> y && a) {
        v.assign(60, 0);
        v[a] = 1; v[b] = 1; v[c] = 1;
        v[x] = 1; v[y] = 1;
        if (a > b) swap(a, b);
        if (b > c) swap(b, c);
        if (a > b) swap(a, b);
        if (x > y) swap(x, y);
        if (x < b) {
            if (y < c) cout << "-1" << endl;
            else cout << getNext(c) << endl;
        } else if (x < c) {
            cout << getNext(b) << endl;
        } else cout << getNext(0) << endl;
    }

    return 0;
}