class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==0) return "";
        sort(strs.begin(),strs.end());
        string first=strs[0];
        string last=strs[n-1];
        string ans="";
        for(int i=0;i<last.length();i++){
            if(first[i]!=last[i]) break;
            ans+=first[i];
        }
        return ans;
    }
};