class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> graph(n);

        int low = INT_MAX, high = 0;

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];

            if (!online[u] || !online[v])
                continue;

            graph[u].push_back({v, w});
            low = min(low, w);
            high = max(high, w);
        }

        auto check = [&](int mn) {
            vector<long long> dist(n, LLONG_MAX);
            dist[0] = 0;

            priority_queue<pair<long long,int>,
                           vector<pair<long long,int>>,
                           greater<pair<long long,int>>> pq;

            pq.push({0, 0});

            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();

                if (d != dist[u]) continue;
                if (d > k) continue;
                if (u == n - 1) return true;

                for (auto &[v, w] : graph[u]) {
                    if (w < mn) continue;

                    long long nd = d + w;
                    if (nd < dist[v]) {
                        dist[v] = nd;
                        pq.push({nd, v});
                    }
                }
            }
            return false;
        };

        if (low == INT_MAX) return -1;

        while (low < high) {
            int mid = low + (high - low + 1) / 2;

            if (check(mid))
                low = mid;
            else
                high = mid - 1;
        }

        return check(low) ? low : -1;
    }
};