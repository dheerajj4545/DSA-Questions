class Solution {
public:
    struct Node {
        long long score;
        vector<int> indices;
    };

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(a.begin(), a.end(), [](auto &x, auto &y) {
            return x[1] < y[1];
        });

        vector<long long> ends(n);

        for (int i = 0; i < n; i++)
            ends[i] = a[i][1];

        vector<int> p(n);

        for (int i = 0; i < n; i++) {
            p[i] = lower_bound(
                ends.begin(),
                ends.begin() + i,
                a[i][0]
            ) - ends.begin() - 1;
        }

        vector<vector<Node>> dp(n + 1, vector<Node>(5));

        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= 4; k++) {

                Node notTake = dp[i - 1][k];

                Node take;

                int prev = p[i - 1] + 1;

                take = dp[prev][k - 1];

                take.score += a[i - 1][2];
                take.indices.push_back(a[i - 1][3]);

                sort(take.indices.begin(), take.indices.end());

                if (take.score > notTake.score ||
                    (take.score == notTake.score &&
                     take.indices < notTake.indices)) {
                    dp[i][k] = take;
                } else {
                    dp[i][k] = notTake;
                }
            }
        }

        return dp[n][4].indices;
    }
};