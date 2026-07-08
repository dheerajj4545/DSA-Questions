class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        int n = s.size();

        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<int> prefCnt(n + 1, 0);
        vector<long long> prefSum(n + 1, 0);
        vector<long long> prefHash(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefCnt[i + 1] = prefCnt[i];
            prefSum[i + 1] = prefSum[i];
            prefHash[i + 1] = prefHash[i];

            if (s[i] != '0') {
                prefCnt[i + 1]++;
                prefSum[i + 1] += s[i] - '0';
                prefHash[i + 1] = (prefHash[i] * 10 + (s[i] - '0')) % MOD;
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            long long sum = prefSum[r + 1] - prefSum[l];

            int cnt = prefCnt[r + 1] - prefCnt[l];

            long long leftHash = prefHash[l];
            long long rightHash = prefHash[r + 1];

            long long num =
                (rightHash - leftHash * pow10[cnt] % MOD + MOD) % MOD;

            ans.push_back(num * (sum % MOD) % MOD);
        }

        return ans;
    }
};