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
    string s;
    int t = 0;
    while (cin >> s && s != "#") {
        cout << "Case " << ++t << ": ";
        if (s == "HELLO") cout << "ENGLISH" << endl;
        else if (s == "HOLA") cout << "SPANISH" << endl;
        else if (s == "HALLO") cout << "GERMAN" << endl;
        else if (s == "BONJOUR") cout << "FRENCH" << endl;
        else if (s == "CIAO") cout << "ITALIAN" << endl;
        else if (s == "ZDRAVSTVUJTE") cout << "RUSSIAN" << endl;
        else cout << "UNKNOWN" << endl;
    }
    return 0;
}