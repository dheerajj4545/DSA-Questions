class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++) {
            int gain = 1;

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    gain++;
                }
            }

            v.push_back({items[i][1], gain});
        }

        sort(v.rbegin(), v.rend());

        vector<int> dp(budget + 1, 0);

        for (auto [price, gain] : v) {
            if (price > budget) continue;

            for (int b = budget; b >= price; b--) {
                dp[b] = max(dp[b], dp[b - price] + gain);
            }

            for (int b = price; b <= budget; b++) {
                dp[b] = max(dp[b], dp[b - price] + 1);
            }
        }

        return dp[budget];
    }
};