
class Solution {
public:
    long long maxDifference(vector<int>& nums) {
        int n = nums.size();

        vector<vector<long long>> dp(n + 2, vector<long long>(2, 0));

        for(int i = n - 1; i >= 0; i--) {
            for(int a = 0; a < 2; a++) {

                long long turnSum = nums[i];

                int next = (turnSum % 3 == 0) ? !a : a;
                long long gain = a ? turnSum : -turnSum;

                long long takeOne = gain + dp[i + 1][next];

                if(a) {
                    dp[i][a] = takeOne;
                } else {
                    dp[i][a] = takeOne;
                }

                if(i + 1 < n) {
                    turnSum = nums[i] + nums[i + 1];

                    next = (turnSum % 3 == 0) ? !a : a;
                    gain = a ? turnSum : -turnSum;

                    long long takeTwo = gain + dp[i + 2][next];

                    if(a) {
                        dp[i][a] = max(dp[i][a], takeTwo);
                    } else {
                        dp[i][a] = min(dp[i][a], takeTwo);
                    }
                }
            }
        }

        return dp[0][1];
    }
};
