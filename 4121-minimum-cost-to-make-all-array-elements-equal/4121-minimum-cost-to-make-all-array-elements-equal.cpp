class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size();
        vector<int> curr = nums;

        long long ans = LLONG_MAX;

        int i = 1;

        while(i < n-1) {
            int l = i;
            int r = i;

            while(l > 0 && curr[l-1] == curr[i]) {
                l--;
            }

            while(r < n-1 && curr[r+1] == curr[i]) {
                r++;
            }

            long long cost = 1LL * (l + n - 1 - r) * curr[i];

            ans = min(ans, cost);

            i = r + 1;
        }

        return ans;
    }
};