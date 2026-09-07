class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> dp(m + 1, 0);

        int maxSide = 0;

        for (int i = 1; i <= n; i++) {

            int prev = 0;

            for (int j = 1; j <= m; j++) {

                int temp = dp[j];

                if (matrix[i-1][j-1] == '1') {

                    dp[j] = 1 + min({
                        dp[j],       
                        dp[j-1],    
                        prev        
                    });

                    maxSide = max(maxSide, dp[j]);
                }
                else {
                    dp[j] = 0;
                }

                prev = temp;
            }
        }

        return maxSide * maxSide;
    }
};