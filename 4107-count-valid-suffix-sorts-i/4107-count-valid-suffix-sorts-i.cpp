class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n = nums.size();

        int firstMismatch = n;

        for (int i = 0; i < n; i++) {
            if (nums[i] != target[i]) {
                firstMismatch = i;
                break;
            }
        }

        unordered_map<int, int> freq;
        int active = 0;
        int cnt = 0;
        bool sorted = true;

        for (int i = n - 1; i >= 0; i--) {

            int x = nums[i];
            int y = target[i];

            if (freq[x] == 0) active++;
            freq[x]++;

            freq[y]--;
            if (freq[y] == 0) active--;

            if (i < n - 1 && target[i] < target[i + 1]) {
                sorted = false;
            }

            if (i <= firstMismatch && sorted && active == 0) {
                cnt++;
            }
        }

        return cnt;
    }
};