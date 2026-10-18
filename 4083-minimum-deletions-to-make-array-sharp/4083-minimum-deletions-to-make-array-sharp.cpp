class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                cnt++;
            }
        }
        return cnt;
    }
};