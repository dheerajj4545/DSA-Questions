class Solution {
public:
    bool wordPattern(string pattern, string s) {

        int n = s.length();
        vector<string> a;
        string curr = "";
        int i = 0;

        while (i < n) {
            if (s[i] == ' ') {
                a.push_back(curr);
                curr = "";
            }
            else {
                curr += s[i];
            }
            i++;
        }
        a.push_back(curr);

        if (pattern.length() != a.size())
            return false;

        unordered_map<char, string> mpp;
        unordered_map<string, char> rev;

        int m = pattern.length();

        for (int i = 0; i < m; i++) {
            mpp[pattern[i]] = a[i];
        }

        for (int i = 0; i < m; i++) {
            if (mpp[pattern[i]] != a[i])
                return false;

            if (rev.count(a[i]) && rev[a[i]] != pattern[i])
                return false;

            rev[a[i]] = pattern[i];
        }

        return true;
    }
};