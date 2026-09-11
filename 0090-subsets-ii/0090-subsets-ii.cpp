class Solution {
public:

void func(int index,vector<int>& nums,vector<int>&dup,vector<vector<int>>&ans)
{
   ans.push_back(dup);
   for(int i=index;i<nums.size();i++)
   {
    if(i!=index&&nums[i]==nums[i-1]) continue;
    dup.push_back(nums[i]);
    func(i+1,nums,dup,ans);
    dup.pop_back();
   }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>dup;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        func(0,nums,dup,ans);
        return ans;
    }
};