class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int left = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            mpp[nums[right]]++;

            while (mpp[nums[right]] > k) {
                mpp[nums[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};