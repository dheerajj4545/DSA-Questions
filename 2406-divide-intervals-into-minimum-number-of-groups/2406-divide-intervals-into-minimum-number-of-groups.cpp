class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int>start;
        vector<int>end;
        for(auto it:intervals){
            start.push_back(it[0]);
            end.push_back(it[1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int i=0;
        int j=0;
        int cnt=0;
        int ans=0;
        while(i<start.size()){
            if(start[i]<=end[j]){
                cnt++;
                ans=max(ans,cnt);
                i++;
            }else{
                cnt--;
                j++;
            }
        }
        return ans;
    }
};