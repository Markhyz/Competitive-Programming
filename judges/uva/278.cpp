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

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool isNeigh(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2) <= 1;
}

bool hasPassed(int origin, int dest, int obstacle) {
    if (dest > origin && dest >= obstacle && obstacle > origin) return true;
    if (dest < origin && dest <= obstacle && obstacle < origin) return true;
    return false;
}

bool isValid(int x1, int y1, int x2, int y2) {
    return x1 >= 0 && x1 < 8 && y1 >= 0 && y1 < 8 && !isNeigh(x1, y1, x2, y2);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;

    while (t--) {
        string piece; cin >> piece;
        int n, m; cin >> n >> m;
        if (piece == "Q" || piece == "r") cout << min(n, m) << endl;
        if (piece == "K") {
            int x = ceil(n / 2.0), y = ceil(m / 2.0);
            cout << x * y << endl;
        }
        if (piece == "k") cout << (int) ceil(n * m / 2.0) << endl;
    }

    return 0;
}