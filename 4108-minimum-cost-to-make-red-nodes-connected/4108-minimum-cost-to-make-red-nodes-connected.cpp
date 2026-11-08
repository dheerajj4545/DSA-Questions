class Solution {
public:
    long long minCost(int n, string colors, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> parent(n, -1), order;
        parent[0] = 0;
        order.push_back(0);

        for (int i = 0; i < order.size(); i++) {
            int u = order[i];

            for (int v : adj[u]) {
                if (v == parent[u]) continue;

                parent[v] = u;
                order.push_back(v);
            }
        }

        vector<long long> sz(n, 1);
        vector<long long> empty(n), connected(n), one(n);

        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];

            long long makeRed = (colors[u] == 'B' ? 0 : 0);
            long long makeBlue = (colors[u] == 'R' ? 0 : 0);

            for (int v : adj[u]) {
                if (parent[v] != u) continue;
                sz[u] += sz[v];
            }

            if (colors[u] == 'B') makeRed = sz[u];
            else makeBlue = sz[u];

            long long sumEmpty = 0;
            long long bestDelta = LLONG_MAX;

            connected[u] = makeRed;

            for (int v : adj[u]) {
                if (parent[v] != u) continue;

                sumEmpty += empty[v];

                connected[u] += min(empty[v], connected[v]);

                bestDelta = min(bestDelta, one[v] - empty[v]);
            }

            empty[u] = makeBlue + sumEmpty;

            one[u] = connected[u];

            if (bestDelta != LLONG_MAX) {
                one[u] = min(one[u], makeBlue + sumEmpty + bestDelta);
            }
        }

        return min(empty[0], one[0]);
    }
};