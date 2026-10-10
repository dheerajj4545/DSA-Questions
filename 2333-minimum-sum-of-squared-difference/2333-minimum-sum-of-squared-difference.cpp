class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(n);

        long long K = 1LL * k1 + k2;
        long long sum = 0;
        int mx = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            sum += diff[i];
            mx = max(mx, diff[i]);
        }

        if (sum <= K) return 0;

        int low = 0, high = mx;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long required = 0;

            for (int d : diff) {
                if (d > mid) {
                    required += d - mid;
                }
            }

            if (required <= K) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        int target = low;
        long long used = 0;

        for (int i = 0; i < n; i++) {
            if (diff[i] > target) {
                used += diff[i] - target;
                diff[i] = target;
            }
        }

        long long remaining = K - used;

        for (int i = 0; i < n && remaining > 0; i++) {
            if (diff[i] == target) {
                diff[i]--;
                remaining--;
            }
        }

        long long ans = 0;

        for (int d : diff) {
            ans += 1LL * d * d;
        }

        return ans;
    }
};