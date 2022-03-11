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
    int t; cin >> t;
    while (t--) {
        string name; cin >> name;
        int y1, m1, d1; scanf("%d/%d/%d", &y1, &m1, &d1);
        int y2, m2, d2; scanf("%d/%d/%d", &y2, &m2, &d2);
        int courses; cin >> courses;

        cout << name << " ";

        if (y1 >= 2010) cout << "eligible" << endl;
        else if (y2 >= 1991) cout << "eligible" << endl;
        else if (courses > 40) cout << "ineligible" << endl;
        else cout << "coach petitions" << endl;
    }
    return 0;
}