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

vs g;
v2i vis;

int n;

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n && !vis[x][y];
}

int dfs(int cur_color, int new_color, int pos_x, int pos_y, bool change) {
    if (change) g[pos_x][pos_y] = new_color;
    vis[pos_x][pos_y] = 1;

    int total = 1;
    for (int i = 0; i < 4; ++i) {
        int new_x = pos_x + dx[i], new_y = pos_y + dy[i];

        if (isValid(new_x, new_y)) {
            if (g[new_x][new_y] == cur_color || g[new_x][new_y] == new_color) {
                total += dfs(g[new_x][new_y], new_color, new_x, new_y, change);
            }
        }
    }

    return total;
}

int solve(int cur_color, int new_color, int pos_x, int pos_y, bool change) {
    vis.assign(n, vi(n));
    return dfs(cur_color, new_color, pos_x, pos_y, change);
}

int main() {
    int t; cin >> t;
    
    while (t--) {
        cin >> n;
        vi res(6);
        g.clear();
        for (int i = 0; i < n; ++i) {
            string s; cin >> s;
            g.push_back(s);
        }

        int total = solve(g[0][0], g[0][0], 0, 0, false), moves = 0;
        while (total < n * n) {
            char best_color;
            for (char color = '1'; color <= '6'; ++color) {
                int cur_total = solve(g[0][0], color, 0, 0, false);
                if (cur_total > total) {
                    best_color = color;
                    total = cur_total;
                }
            }

            solve(g[0][0], best_color, 0, 0, true);
            ++res[best_color - '1'];
            ++moves;
        }

        cout << moves << endl;
        for (int color_total : res) {
            cout << color_total << " ";
        }
        cout << endl;
    }

    return 0;
}