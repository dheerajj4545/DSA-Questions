class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        
        vector<int> first(26, -1), last(26, -1);
        
        for (int i = 0; i < n; i++) {
            if (first[s[i] - 'a'] == -1)
                first[s[i] - 'a'] = i;
            last[s[i] - 'a'] = i;
        }
        
        vector<pair<int,int>> intervals;
        
        for (int i = 0; i < n; i++) {
            if (i != first[s[i] - 'a']) continue;
            
            int l = i;
            int r = last[s[i] - 'a'];
            bool valid = true;
            
            for (int j = l; j <= r; j++) {
                if (first[s[j] - 'a'] < l) {
                    valid = false;
                    break;
                }
                r = max(r, last[s[j] - 'a']);
            }
            
            if (valid)
                intervals.push_back({l, r});
        }
        
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a.second < b.second;
             });
        
        vector<string> ans;
        int prevEnd = -1;
        
        for (auto &it : intervals) {
            if (it.first > prevEnd) {
                ans.push_back(s.substr(it.first, it.second - it.first + 1));
                prevEnd = it.second;
            }
        }
        
        return ans;
    }
};