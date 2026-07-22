#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int ones = 0;
        for (char c : s) if (c == '1') ones++;

        vector<int> groupStart, groupLen;
        vector<int> zgi(n, -1);
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (i > 0 && s[i - 1] == '0') {
                    groupLen.back()++;
                } else {
                    groupStart.push_back(i);
                    groupLen.push_back(1);
                }
            }
            zgi[i] = (int)groupStart.size() - 1;
        }

        if (groupStart.empty()) {
            return vector<int>(queries.size(), ones);
        }

        int m = groupStart.size();
        int sz = max(0, m - 1);
        vector<int> adjSum(sz);
        for (int i = 0; i + 1 < m; i++) adjSum[i] = groupLen[i] + groupLen[i + 1];

        vector<int> logTable(sz + 1, 0);
        for (int i = 2; i <= sz; i++) logTable[i] = logTable[i / 2] + 1;

        vector<vector<int>> st;
        if (sz > 0) {
            int K = logTable[sz] + 1;
            st.assign(K, vector<int>(sz));
            st[0] = adjSum;
            for (int k = 1; k < K; k++) {
                for (int i = 0; i + (1 << k) <= sz; i++) {
                    st[k][i] = max(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
                }
            }
        }

        auto queryMax = [&](int l, int r) -> int {
            int k = logTable[r - l + 1];
            return max(st[k][l], st[k][r - (1 << k) + 1]);
        };

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            int gl = zgi[l];
            int gr = zgi[r];

            int leftPart = (gl == -1) ? -1 : (groupLen[gl] - (l - groupStart[gl]));
            int rightPart = (gr == -1) ? -1 : (r - groupStart[gr] + 1);

            int startAdj = gl + 1;
            int endGroupForAdj = (s[r] == '1') ? gr : gr - 1;
            int endAdj = endGroupForAdj - 1;

            int activeSections = ones;

            if (s[l] == '0' && s[r] == '0' && gl + 1 == gr) {
                activeSections = max(activeSections, ones + leftPart + rightPart);
            } else if (startAdj <= endAdj) {
                activeSections = max(activeSections, ones + queryMax(startAdj, endAdj));
            }

            if (s[l] == '0' && gl + 1 <= endGroupForAdj) {
                activeSections = max(activeSections, ones + leftPart + groupLen[gl + 1]);
            }
            if (s[r] == '0' && gl < gr - 1) {
                activeSections = max(activeSections, ones + rightPart + groupLen[gr - 1]);
            }

            ans.push_back(activeSections);
        }

        return ans;
    }
};