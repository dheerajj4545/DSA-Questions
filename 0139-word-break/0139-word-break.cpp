class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        int n = s.size();

        vector<bool> dp(n + 1, false);

        dp[n] = true;

        for (int i = n - 1; i >= 0; i--) {
            string temp = "";

            for (int j = i; j < n; j++) {
                temp += s[j];

                if (st.count(temp) && dp[j + 1]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};