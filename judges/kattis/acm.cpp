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

int times[200], ac[200];

int main() {
    int t;
    while (cin >> t && t != -1) {
        string problem, verdict; cin >> problem >> verdict;
        if (verdict == "right") ac[problem[0]] = 1, times[problem[0]] += t;
        else times[problem[0]] += 20;
    }
    int acs = 0, total_time = 0;
    for (int problem = 'A'; problem <= 'Z'; ++problem) {
        if (ac[problem]) {
            ++acs;
            total_time += times[problem];
        }
    }
    
    cout << acs << " " << total_time << endl;
    
    return 0;
}
