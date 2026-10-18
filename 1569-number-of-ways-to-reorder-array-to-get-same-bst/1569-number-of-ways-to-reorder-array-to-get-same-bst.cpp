class Solution {
public:
    int numOfWays(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        vector<vector<long long>> C(n + 1, vector<long long>(n + 1, 1));

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }

        function<long long(vector<int>&)> solve = [&](vector<int>& arr) -> long long {
            int sz = arr.size();

            if (sz <= 2) return 1;

            vector<int> left, right;

            for (int i = 1; i < sz; i++) {
                if (arr[i] < arr[0])
                    left.push_back(arr[i]);
                else
                    right.push_back(arr[i]);
            }

            long long l = solve(left);
            long long r = solve(right);

            return C[sz - 1][left.size()] * l % MOD * r % MOD;
        };

        return (solve(nums) - 1 + MOD) % MOD;
    }
};