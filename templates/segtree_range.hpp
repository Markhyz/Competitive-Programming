#define SHIFTL(x, y) ((x) << (y))
#define SHIFTR(x, y) ((x) >> (y))

int segtree[], values[], lazy[];

void build(int cur, int l, int r) {
    if (l == r) {
        segtree[cur] = values[l];
    
        return;
    }
    
    int mid = (l + r) / 2;
    int node_left = SHIFTL(cur, 1), node_right = SHIFTL(cur, 1) + 1;
    build(node_left, l, mid);
    build(node_right, mid + 1, r);
    segtree[cur] = max(segtree[node_left], segtree[node_right]);
}

void push(int cur) {
    if (lazy[cur]) {
        int node_left = SHIFTL(cur, 1);
        lazy[node_left] = max(lazy[node_left], lazy[cur]);
        segtree[node_left] = max(segtree[node_left], lazy[cur]);

        int node_right = SHIFTL(cur, 1) + 1;
        lazy[node_right] = max(lazy[node_right], lazy[cur]);
        segtree[node_right] = max(segtree[node_right], lazy[cur]);

        lazy[cur] = 0;
    }
}

int query(int cur, int l, int r, int i, int j) {
    if (j < l || i > r) return 0;
    if (l >= i && r <= j) return segtree[cur];

    push(cur);

    int mid = (l + r) / 2;
    int node_left = SHIFTL(cur, 1), node_right = SHIFTL(cur, 1) + 1;
    int res_left = query(node_left, l, mid, i, j);
    int res_right = query(node_right, mid + 1, r, i, j);

    return max(res_left, res_right);
}

void update(int cur, int l, int r, int i, int j, int x) {
    if (j < l || i > r) return;
    if (l >= i && r <= j) {
        segtree[cur] = max(segtree[cur], x);
        lazy[cur] = max(lazy[cur], x);

        return;
    }

    push(cur);

    int mid = (l + r) / 2;
    int node_left = SHIFTL(cur, 1), node_right = SHIFTL(cur, 1) + 1;
    update(node_left, l, mid, i, j, x);
    update(node_right, mid + 1, r, i, j, x);
    segtree[cur] = max(segtree[node_left], segtree[node_right]);
}