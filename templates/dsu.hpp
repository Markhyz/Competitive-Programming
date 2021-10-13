int n;
int parent[], rankk[];

int getParent(int x) {
    return parent[x] = parent[x] == x ? x : getParent(parent[x]);
}

    bool dsu(int x, int y) {
    int p_x = getParent(x), p_y = getParent(y);

    if (p_x == p_y) return false;

    if (rankk[p_x] > rankk[p_y]) parent[p_y] = p_x;
    else if (rankk[p_y] > rankk[p_x]) parent[p_x] = p_y;
    else {
        parent[p_y] = p_x;
        ++rankk[p_x];
    }

    return true;
}

void initDSU() {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        rankk[i] = 1;
    }
}