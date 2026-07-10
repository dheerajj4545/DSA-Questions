class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        auto bitLength = [](int x) {
            return (x ? __lg(x) : -1) + 1;
        };

        auto ceilLog2 = [&](int x) {
            return bitLength(x - 1);
        };

        vector<int> order(n);
        iota(order.begin(), order.end(), 0);

        sort(order.begin(), order.end(), [&](int i, int j) {
            return nums[i] < nums[j];
        });

        vector<int> pos(n);
        for (int i = 0; i < n; i++)
            pos[order[i]] = i;

        vector<int> comp(n);
        for (int i = 0; i < n - 1; i++)
            comp[i + 1] = comp[i] + (nums[order[i + 1]] - nums[order[i]] > maxDiff);

        int LOG = ceilLog2(n - 1) + 1;
        vector<vector<int>> up(LOG, vector<int>(n, n - 1));

        int left = 0;
        for (int right = 0; right < n; right++) {
            while (nums[order[right]] - nums[order[left]] > maxDiff) {
                up[0][left] = right - 1;
                left++;
            }
        }

        for (int k = 0; k + 1 < LOG; k++)
            for (int i = 0; i < n; i++)
                up[k + 1][i] = up[k][up[k][i]];

        vector<int> ans;

        for (auto &q : queries) {
            int u = q[0], v = q[1];

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            if (comp[pos[u]] != comp[pos[v]]) {
                ans.push_back(-1);
                continue;
            }

            if (pos[u] > pos[v])
                swap(u, v);

            int cur = pos[u];
            int res = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < pos[v]) {
                    cur = up[k][cur];
                    res += 1 << k;
                }
            }

            ans.push_back(res + 1);
        }

        return ans;
    }
};