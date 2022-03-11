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

int stuff(string s) {
    int res = 0;
    for (char c : s) {
        if (isalpha(c)) res += tolower(c) - 'a' + 1;
    }
    while (res > 9) {
        int tmp = 0;
        while (res > 0) {
            tmp += res % 10;
            res /= 10;
        }
        res = tmp;
    }

    return res;
}

int main() {
    string a, b;
    
    while (getline(cin, a)) {
        getline(cin, b);
        int x1 = stuff(a), x2 = stuff(b);
        if (x1 > x2) swap(x1, x2);
        double res = (double) x1 / x2 * 100;
        printf("%.2f %%\n", res);
    }

    return 0;
}