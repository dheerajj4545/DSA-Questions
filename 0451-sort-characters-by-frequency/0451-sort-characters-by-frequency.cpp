class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mpp;

        for(auto it : s) {
            mpp[it]++;
        }

        vector<pair<char,int>> v(mpp.begin(),mpp.end());

        sort(v.begin(),v.end(),[](auto &a, auto &b) {
            return a.second > b.second;
        });

        string ans;

        for(auto &p : v) {
            ans += string(p.second,p.first);
        }

        return ans;
    }
};