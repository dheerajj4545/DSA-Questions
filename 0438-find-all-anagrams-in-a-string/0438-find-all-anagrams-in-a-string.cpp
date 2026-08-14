class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        unordered_map<char, int> mp;
        for (auto it : p)
            mp[it]++;

        int left = 0;
        unordered_map<char, int> mpp;

        for (int right = 0; right < s.length(); right++) {
            mpp[s[right]]++;

            if (right - left + 1 > p.length()) {
                mpp[s[left]]--;

                if (mpp[s[left]] == 0)
                    mpp.erase(s[left]);

                left++;
            }

            if (right - left + 1 == p.length() && mpp == mp) {
                ans.push_back(left);
            }
        }

        return ans;
    }
};