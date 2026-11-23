
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();

        vector<int> ugly(n);
        vector<int> idx(k, 0);

        ugly[0] = 1;

        for(int i = 1; i < n; i++) {
            long long mini = LLONG_MAX;

            for(int j = 0; j < k; j++) {
                mini = min(mini, 1LL * ugly[idx[j]] * primes[j]);
            }

            ugly[i] = mini;

            for(int j = 0; j < k; j++) {
                if(1LL * ugly[idx[j]] * primes[j] == mini) {
                    idx[j]++;
                }
            }
        }

        return ugly[n - 1];
    }
};
