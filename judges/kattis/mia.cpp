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

int score(int x, int y) {
    if (x < y) swap(x, y);
    if (x == 2 && y == 1) return 1000;
    if (x == y) return x * 100;
    return x * 10 + y;
}

int main() {
    int s0, s1, r0, r1; 

    while (cin >> s0 >> s1 >> r0 >> r1 && s0 | s1 | r0 | r1) {
        int x = score(s0, s1);
        int y = score(r0, r1);

        if (x > y) cout << "Player 1 wins." << endl;
        else if (x < y) cout << "Player 2 wins." << endl;
        else cout << "Tie." << endl;
    }

    return 0;
}
