class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastIndex(26, 0);
        for (int i = 0; i < s.length(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }
        
        vector<bool> seen(26, false);
        string result = "";
        
        for (int i = 0; i < s.length(); i++) {
            if (seen[s[i] - 'a']) {
                continue;
            }
            
            while (!result.empty() && result.back() > s[i] && lastIndex[result.back() - 'a'] > i) {
                seen[result.back() - 'a'] = false;
                result.pop_back();
            }
            
            result.push_back(s[i]);
            seen[s[i] - 'a'] = true;
        }
        
        return result;
    }
};