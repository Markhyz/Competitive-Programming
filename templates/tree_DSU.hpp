vector<int> g[];
int subtree_size[];
int cnt[], start_t[], end_t[], node_t[], t = 0;
int color[];

int prep(int cur, int p) {
    start_t[cur] = t;
    node_t[t++] = cur;
    subtree_size[cur] = 1;
    for (int neigh : g[cur]) {
        if (neigh != p)
            subtree_size[cur] += prep(neigh, cur);
    }

    end_t[cur] = t;
    
    return subtree_size[cur];
}

// For each node, get the color count of its subtree

void treeDSU(int cur, int p, bool keep) {
    int max_size = -1, big_child = -1;
    for (int neigh : g[cur]) {
        if (neigh != p && subtree_size[neigh] > max_size) {
            max_size = subtree_size[neigh];
            big_child = neigh;
        }
    }

    for (int neigh : g[cur])
        if (neigh != p && neigh != big_child)
            treeDSU(neigh, cur, false);
    
    if (big_child != -1)
        treeDSU(big_child, cur, true);

    for (int neigh : g[cur])
        if (neigh != p && neigh != big_child)
            for (int i = start_t[neigh]; i < end_t[neigh]; ++i)
                ++cnt[color[node_t[i]]];

    if (!keep)
        for (int i = start_t[cur]; i < end_t[cur]; ++i)
            --cnt[color[node_t[i]]];
}