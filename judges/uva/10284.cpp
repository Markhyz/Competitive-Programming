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

char board[8][8];
int marked[8][8];

vi2 moves[200];

bool isValid(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

void rookAttack(int x, int y) {
    for (int a = -1; a <= 1; ++a) {
        for (int b = -1; b <= 1; ++b) {
            if ((a && b) || (!a && !b)) continue;
            for (int i = 1; i < 8; ++i) {
                int kx = x + i * a, ky = y + i * b;
                if (isValid(kx, ky)) {
                    marked[kx][ky] = 1;
                    if (board[kx][ky] != '.') break;
                }
            }
        }
    }
}

void bishopAttack(int x, int y) {
    for (int a = -1; a <= 1; ++a) {
        for (int b = -1; b <= 1; ++b) {
            if (!a || !b) continue;
            for (int i = 1; i < 8; ++i) {
                int kx = x + i * a, ky = y + i * b;
                if (isValid(kx, ky)) {
                    marked[kx][ky] = 1;
                    if (board[kx][ky] != '.') break;
                }
            }
        }
    }
}

void attack(int x, int y) {
    marked[x][y] = 1;
    char piece = board[x][y];
    if (tolower(piece) == 'p' || tolower(piece) == 'n') {
        for (i2 move : moves[piece]) {
            int kx = x + get<0>(move), ky = y + get<1>(move);
            if (isValid(kx, ky)) marked[kx][ky] = 1;
        }
    } else if (tolower(piece) == 'k') {
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int kx = x + i, ky = y + j;
                if (isValid(kx, ky)) marked[kx][ky] = 1;
            }
        }
    } 
    else if (tolower(piece) == 'r') rookAttack(x, y);
    else if (tolower(piece) == 'b') bishopAttack(x, y);
    else if (tolower(piece) == 'q') rookAttack(x, y), bishopAttack(x, y);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string s;

    moves['p'] = {{1, -1}, {1, 1}};
    moves['P'] = {{-1, -1}, {-1, 1}};
    moves['n'] = moves['N'] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

    while (cin >> s) {
        memset(board, '.', sizeof board);
        memset(marked, 0, sizeof marked);
        int row = 0, column = 0;
        for (char c : s) {
            if (c == '/') ++row, column = 0;
            else if (c >= '1' && c <= '8') column += c - '0';
            else board[row][column] = c, ++column;
        }
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] != '.') attack(i, j);
            }
        }
        int res = 0;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (!marked[i][j]) ++res;
            }
        }
        cout << res << endl;
    }

    return 0;
}