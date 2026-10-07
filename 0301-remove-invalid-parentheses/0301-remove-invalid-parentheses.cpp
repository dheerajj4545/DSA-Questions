class Solution {
public:
    vector<string> ans;

    void solve(string &s, int idx, string curr, int open, int close) {
        if (idx == s.size()) {
            if (open == close)
                ans.push_back(curr);
            return;
        }

        char ch = s[idx];

        if (ch == '(') {
            solve(s, idx + 1, curr + ch, open + 1, close);

            solve(s, idx + 1, curr, open, close);
        }
        else if (ch == ')') {
            if (open > close)
                solve(s, idx + 1, curr + ch, open, close + 1);
            solve(s, idx + 1, curr, open, close);
        }
        else {
            solve(s, idx + 1, curr + ch, open, close);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        ans.clear();

        int left = 0, right = 0;
        for (char ch : s) {
            if (ch == '(') {
                left++;
            }
            else if (ch == ')') {
                if (left > 0)
                    left--;
                else
                    right++;
            }
        }
        function<void(int, string, int, int, int, int)> dfs =
            [&](int idx, string curr, int open, int close,
                int removeLeft, int removeRight) {

            if (idx == s.size()) {
                if (open == close && removeLeft == 0 && removeRight == 0)
                    ans.push_back(curr);
                return;
            }

            char ch = s[idx];

            if (ch == '(') {
                if (removeLeft > 0)
                    dfs(idx + 1, curr, open, close,
                        removeLeft - 1, removeRight);

                dfs(idx + 1, curr + ch, open + 1, close,
                    removeLeft, removeRight);
            }
            else if (ch == ')') {
                if (removeRight > 0)
                    dfs(idx + 1, curr, open, close,
                        removeLeft, removeRight - 1);
                if (open > close)
                    dfs(idx + 1, curr + ch, open, close + 1,
                        removeLeft, removeRight);
            }
            else {
                dfs(idx + 1, curr + ch, open, close,
                    removeLeft, removeRight);
            }
        };

        dfs(0, "", 0, 0, left, right);

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};