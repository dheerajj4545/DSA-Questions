class Solution {
public:
    long long maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> freq(n + 1, 0);
        for (auto& item : items) {
            freq[item[0]]++;
        }

        vector<int> multiples(n + 1, 0);
        for (int f = 1; f <= n; f++) {
            if (freq[f] == 0) continue;
            for (int m = f; m <= n; m += f) {
                multiples[f] += freq[m];
            }
        }

        vector<pair<long long, long long>> sorted_items;
        long long min_price = LLONG_MAX;
        for (auto& item : items) {
            long long f = item[0];
            long long p = item[1];
            min_price = min(min_price, p);
            sorted_items.push_back({p, multiples[f] - 1});
        }

        sort(sorted_items.begin(), sorted_items.end());

        long long rem_budget = budget;
        long long ans = 0;

        for (auto& [price, cap] : sorted_items) {
            if (price >= 2 * min_price) break;
            if (cap <= 0 || rem_budget < price) continue;
            long long buy = min(cap, rem_budget / price);
            ans += buy * 2;
            rem_budget -= buy * price;
        }

        ans += rem_budget / min_price;
        return ans;
    }
};