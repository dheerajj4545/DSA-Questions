class Solution {
public:
    bool bloom(vector<int>& nums, int day, int m, int k) {
        int flowers = 0;
        int bouqets = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= day) {
                flowers++;
                if (flowers == k) {
                    bouqets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        return bouqets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total = 1LL * m * k;
        if (total > bloomDay.size())
            return -1;
        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());
        int low = mini;
        int high = maxi;
        int res = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (bloom(bloomDay, mid, m, k)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
};