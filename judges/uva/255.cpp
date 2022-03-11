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
    int k, q, nq;

    while (cin >> k >> q >> nq) {
        int kx = k / 8, ky = k % 8;
        int qx = q / 8, qy = q % 8;
        int nqx = nq / 8, nqy = nq % 8;

        if (kx == qx && ky == qy) cout << "Illegal state" << endl;
        else if ((qx == nqx && qy == nqy) || (qx != nqx && qy != nqy)) cout << "Illegal move" << endl;
        else if (kx == nqx && hasPassed(qy, nqy, ky)) cout << "Illegal move" << endl;
        else if (ky == nqy && hasPassed(qx, nqx, kx)) cout << "Illegal move" << endl;
        else if (isNeigh(nqx, nqy, kx, ky)) cout << "Move not allowed" << endl;
        else {
            bool end = true;
            for (int i = 0; i < 4; ++i) {
                int nkx = kx + dx[i], nky = ky + dy[i];
                if (isValid(nkx, nky, nqx, nqy)) {
                    end = false;
                    break;
                }
            }
            if (end) cout << "Stop" << endl;
            else cout << "Continue" << endl;
        }
    }

    return 0;
}