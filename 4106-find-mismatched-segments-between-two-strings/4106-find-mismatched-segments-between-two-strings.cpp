class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        int i = 0;
        int n = s1.length();

        vector<vector<string>> ans;

        while (i < n) {
            if (s1[i] != s2[i]) {
                int start = i;

                while (i < n && s1[i] != s2[i]) {
                    i++;
                }

                ans.push_back({
                    s1.substr(start, i - start),
                    s2.substr(start, i - start)
                });
            }
            else {
                i++;
            }
        }

        return ans;
    }
};