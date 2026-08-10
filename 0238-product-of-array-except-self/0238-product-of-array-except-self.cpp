class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix=1;
        vector<int>res(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            res[i]=prefix;
            prefix*=nums[i];
        }
        int suffix=1;
        for(int i=nums.size()-1;i>=0;i--){
            res[i]*=suffix;
            suffix*=nums[i];
        }
        return res;
    }
};