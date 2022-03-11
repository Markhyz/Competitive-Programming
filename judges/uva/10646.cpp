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
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t, tt = 0; cin >> t;

    while (t--) {
        vs cards(52);
        for (int i = 0; i < 52; ++i) {
            cin >> cards[i];
        }
        reverse(cards.begin(), cards.end());
        
        int y = 0;
        for (int i = 0; i < 3; ++i) {
            vs new_cards(cards.begin(), cards.begin() + 25);
            string card = cards[25];
            int x = card[0] >= '2' && card[0] <= '9' ? card[0] - '0' : 10;
            y += x;
            for (int j = 25 + 10 - x + 1; j < cards.size(); ++j)
                new_cards.push_back(cards[j]);
            cards = new_cards;
        }

        reverse(cards.begin(), cards.end());

        cout << "Case " << ++tt << ": " << cards[y - 1] << endl;
    }

    return 0;
}