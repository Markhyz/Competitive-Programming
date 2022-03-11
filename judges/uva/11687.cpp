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

int score(string& s) {
    if (s == "1") return 1;
    string s2 = to_string(s.length());
    return 1 + score(s2);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string s;

    while (cin >> s && s != "END") {
        cout << score(s) << endl;
    }

    return 0;
}