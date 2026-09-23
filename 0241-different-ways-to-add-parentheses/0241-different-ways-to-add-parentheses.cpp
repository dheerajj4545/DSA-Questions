class Solution {
public:
    unordered_map<string, vector<int>> dp;

    vector<int> solve(string expression) {
        if (dp.find(expression) != dp.end()) {
            return dp[expression];
        }

        vector<int> ans;

        for (int i = 0; i < expression.size(); i++) {

            char ch = expression[i];

            if (ch == '+' || ch == '-' || ch == '*') {

                string leftStr = expression.substr(0, i);
                string rightStr = expression.substr(i + 1);

                vector<int> left = solve(leftStr);
                vector<int> right = solve(rightStr);

                for (int a : left) {
                    for (int b : right) {

                        if (ch == '+')
                            ans.push_back(a + b);

                        else if (ch == '-')
                            ans.push_back(a - b);

                        else
                            ans.push_back(a * b);
                    }
                }
            }
        }
        if (ans.empty()) {
            ans.push_back(stoi(expression));
        }
        dp[expression] = ans;

        return ans;
    }

    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};