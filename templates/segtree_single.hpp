#define SHIFTL(x, y) ((x) << (y))
#define SHIFTR(x, y) ((x) >> (y))

int segtree[], values[];

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

int query(int cur, int l, int r, int i, int j) {
    if (j < l || i > r) return 0;
    if (l >= i && r <= j) return segtree[cur];

    int mid = (l + r) / 2;
    int node_left = SHIFTL(cur, 1), node_right = SHIFTL(cur, 1) + 1;
    int res_left = query(node_left, l, mid, i, j);
    int res_right = query(node_right, mid + 1, r, i, j);

    return max(res_left, res_right);
}

void update(int cur, int l, int r, int i, int x) {
    if (l == r) {
        segtree[cur] = x;

        return;
    }

    int mid = (l + r) / 2;
    int node_left = SHIFTL(cur, 1), node_right = SHIFTL(cur, 1) + 1;
    if (i <= mid) update(node_left, l, mid, i, x);
    else update(node_right, mid + 1, r, i, x);
    segtree[cur] = max(segtree[node_left], segtree[node_right]);
}