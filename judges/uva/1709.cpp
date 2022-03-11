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
    double p, a, b, c, d;
    int n;
    
    while (scanf("%lf %lf %lf %lf %lf %d", &p, &a, &b, &c, &d, &n) != EOF) {
        double res = 0, mx = 0;
        for (int i = 1; i <= n; ++i) {
            double x = p * (sin(a * i + b) + cos(c * i + d) + 2);
            if (x > mx) mx = x;
            else res = max(res, mx - x);
        }
        printf("%f\n", res);
    }

    return 0;
}