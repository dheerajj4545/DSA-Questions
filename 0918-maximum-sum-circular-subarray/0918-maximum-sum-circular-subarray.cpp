class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        int currMax = 0;
        int currMin = 0;

        for (int x : nums) {
            currMax = max(x, currMax + x);
            maxSum = max(maxSum, currMax);

            currMin = min(x, currMin + x);
            minSum = min(minSum, currMin);

            total += x;
        }

        if (maxSum < 0)
            return maxSum;

        return max(maxSum, total - minSum);
    }
};