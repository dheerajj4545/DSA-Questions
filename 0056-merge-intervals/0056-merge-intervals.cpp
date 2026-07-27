class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(auto it:nums){
            if(ans.empty()||ans.back()[1]<it[0]){
                ans.push_back(it);
            }
            else{
                ans.back()[1]=max(ans.back()[1],it[1]);
            }
        }
        return ans;
    }
};