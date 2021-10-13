int n;
vector<int> g[];
int anc[][], start_t[], end_t[], depth[];
int cnt;

vector<int> path;
void dfs(int cur, int p) {
    depth[cur] = path.size();
    path.push_back(cur);
    start_t[cur] = cnt++; 
    
    int k = ceil(log2(n));
    for (int i = 0; i <= k; ++i) {
        int jmp = 1 << i;
        anc[cur][jmp] = jmp < path.size() ? path[path.size() - 1 - jmp] : path[0];
    }
    
    for (int neigh : g[cur])
        if (neigh != p)
            dfs(neigh, cur);

    end_t[cur] = cnt++;

    path.pop_back();
}

bool isAnc(int x, int y) {
    return start_t[x] < start_t[y] && end_t[y] < end_t[x];
}

int lca(int x, int y) {
    if (isAnc(x, y)) return x;
    if (isAnc(y, x)) return y;

    int k = ceil(log2(n));
    int cur = x;
    while (k >= 0) {
        if (!isAnc(anc[cur][k], y)) {
            cur = anc[cur][k];
        }
        --k;
    }

    return anc[cur][0];
}

void initLCA() {
    dfs(1, -1);
}