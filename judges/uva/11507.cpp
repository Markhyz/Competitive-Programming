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
    int l;

    while (cin >> l && l) {
        string res = "+x";
        for (int i = 0; i < l - 1; ++i) {
            string s; cin >> s;
            if (s == "No") continue;
            if (res == "+x") {
                if (s == "-x") res = "-x";
                else if (s == "+y") res = "+y";
                else if (s == "-y") res = "-y";
                else if (s == "+z") res = "+z";
                else if (s == "-z") res = "-z";
            } else if (res == "-x") {
                if (s == "-x") res = "+x";
                else if (s == "+y") res = "-y";
                else if (s == "-y") res = "+y";
                else if (s == "+z") res = "-z";
                else if (s == "-z") res = "+z";
            } else if (res == "+y") {
                if (s == "+y") res = "-x";
                else if (s == "-y") res = "+x";
                else if (s == "-x") res = "-y";
            } else if (res == "-y") {
                if (s == "-y") res = "-x";
                else if (s == "+y") res = "+x";
                else if (s == "-x") res = "+y";
            } else if (res == "+z") {
                if (s == "+z") res = "-x";
                else if (s == "-z") res = "+x";
                else if (s == "-x") res = "-z";
            } else if (res == "-z") {
                if (s == "+z") res = "+x";
                else if (s == "-z") res = "-x";
                else if (s == "-x") res = "+z";
            }
        }

        cout << res << endl;
    }

    return 0;
}
