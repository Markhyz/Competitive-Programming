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

vector<tuple<int, int>> g[];
vector<tuple<int, int>> mst[];

long long setMST() {
    vector<tuple<int, int, int>> edges;
    for (int u = 1; u <= n; ++u) {
        for (auto p : g[u]) {
            int w, v; tie(w, v) = p;
            edges.emplace_back(w, u, v);
        }
    }
    sort(edges.begin(), edges.end());

    initDSU();
    int total = 0;
    long long total_w = 0;
    for (auto edge : edges) {
        int u, v, w; tie(w, u, v) = edge;
        if (dsu(u, v)) {
            mst[u].emplace_back(w, v);
            mst[v].emplace_back(w, u);
            total_w += w;
        }
    }

    return total_w;
}

void initMST() {
    for (int i = 1; i <= n; ++i) {
        mst[i].clear();
    }
}