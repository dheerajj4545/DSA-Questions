class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();

        long long total = 0;

        for (int x : nums) {
            total += x;
        }

        int half = n / 2;

        long long windowSum = 0;

        for (int i = 0; i < half; i++) {
            windowSum += nums[i];
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (2 * windowSum > total) {
                ans++;
            }
            windowSum -= nums[i];
            windowSum += nums[(i + half) % n];
        }

        return ans;
    }
};