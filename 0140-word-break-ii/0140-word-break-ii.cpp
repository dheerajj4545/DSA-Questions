class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> st(wordDict.begin(), wordDict.end());

        int n = s.size();

        vector<vector<string>> dp(n + 1);

        dp[n].push_back("");

        for (int i = n - 1; i >= 0; i--) {

            string temp = "";

            for (int j = i; j < n; j++) {

                temp += s[j];

                if (!st.count(temp))
                    continue;

                for (string suffix : dp[j + 1]) {

                    if (suffix == "")
                        dp[i].push_back(temp);
                    else
                        dp[i].push_back(temp + " " + suffix);
                }
            }
        }

        return dp[0];
    }
};