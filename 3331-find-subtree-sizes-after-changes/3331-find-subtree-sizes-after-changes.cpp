class Solution {
public:
    vector<vector<int>> adj, newAdj;
    vector<int> last, newParent, ans;
    string s;
    void dfs1(int node, vector<int>& parent) {
        int ch = s[node] - 'a';
        int old = last[ch];

        if (node != 0 && old != -1)
            newParent[node] = old;
        else
            newParent[node] = parent[node];

        last[ch] = node;

        for (int child : adj[node]) {
            dfs1(child, parent);
        }

        last[ch] = old;
    }
    int dfs2(int node) {
        int size = 1;

        for (int child : newAdj[node]) {
            size += dfs2(child);
        }

        ans[node] = size;
        return size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string str) {
        int n = parent.size();
        s = str;

        adj.resize(n);
        newAdj.resize(n);
        last.assign(26, -1);
        newParent.resize(n);
        ans.resize(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        dfs1(0, parent);
        for (int i = 1; i < n; i++) {
            newAdj[newParent[i]].push_back(i);
        }

        dfs2(0);

        return ans;
    }
};