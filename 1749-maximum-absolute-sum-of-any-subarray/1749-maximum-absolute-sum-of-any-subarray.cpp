class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0;
        int minSum = 0;
        int currMax = 0;
        int currMin = 0;

        for (int x : nums) {
            currMax = max(x, currMax + x);
            maxSum = max(maxSum, currMax);

            currMin = min(x, currMin + x);
            minSum = min(minSum, currMin);
        }

        return max(maxSum, abs(minSum));
    }
};