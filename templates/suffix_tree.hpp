struct TrieNode {
    TrieNode() {}
    TrieNode(int l, int r, int parent, int link, int length) 
        : l(l), r(r), parent(parent), link(link), length(length) {}
    int l, r, parent, link;
    int length;
    map<int, int> children;
};

vector<TrieNode> nodes;

// extend returns true if a leaf is created or false otherwise

bool extend(vector<int>& str, int& cur_node, int& i, int j) {
    if (!nodes[cur_node].children[str[i]]) {
        nodes[cur_node].children[str[i]] = nodes.size();
        nodes.emplace_back(i, -1, cur_node, -1, -1);
        
        return true;
    } else {
        int next_node = nodes[cur_node].children[str[i]];
        int x = j - i + 1;
        int y = (nodes[next_node].r == -1 ? j : nodes[next_node].r) - nodes[next_node].l + 1;
        if (x > y) {
            cur_node = next_node;
            i += y;

            return extend(str, cur_node, i, j);
        } else {
            int k = nodes[next_node].l + x - 1;
            if (str[k] == str[j]) return false;
            else {
                int new_node = nodes.size();
                int new_node_len = nodes[cur_node].length + (k - nodes[next_node].l); 
                
                nodes.emplace_back(nodes[next_node].l, k - 1, cur_node, -1, new_node_len);
                nodes[new_node].children[str[k]] = next_node;
                nodes[next_node].l = k;
                nodes[next_node].parent = new_node;
                nodes[cur_node].children[str[i]] = new_node;
                
                cur_node = new_node;
                i = j;

                return extend(str, cur_node, i, j);
            }
        }
    }
}

void build(vector<int>& str) {
    nodes.clear(); 
    nodes.emplace_back(0, -1, 0, 0, 0);
    bool clear = false;
    int cur_ext = 0, cur_node = 0, cur_char = 0;
    for (int cur_suff = 0; cur_suff < str.size(); ++cur_suff) {
        int last_leaf = -1;
        while (cur_ext <= cur_suff) {
            if (clear) {
                int parent_node = nodes[cur_node].parent;
                int link_node = nodes[parent_node].link;
                if (link_node == -1) {
                    link_node = nodes[nodes[parent_node].parent].link;
                }
                cur_node = link_node;
                cur_char = cur_ext + nodes[cur_node].length;
            }
            if (extend(str, cur_node, cur_char, cur_suff)) {
                ++cur_ext;
                if (last_leaf != -1) {
                    int parent_1 = nodes[last_leaf].parent;
                    int parent_2 = nodes.back().parent;
                    nodes[parent_1].link = parent_2;
                }
                cur_node = last_leaf = nodes.size() - 1;
                clear = true;
            } else {
                clear = false;
                break;
            }
        }
        if (last_leaf != -1)
            nodes[nodes[last_leaf].parent].link = 0;
    }
    for (int i = 1; i < nodes.size(); ++i)
        if (nodes[i].r == -1) {
            nodes[i].r = str.size() - 1;
            nodes[i].length = nodes[nodes[i].parent].length + nodes[i].r - nodes[i].l + 1;
        }
}