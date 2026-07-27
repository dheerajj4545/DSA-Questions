class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        int smaxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                smaxi=maxi;
                maxi=nums[i];
            }
            else if(nums[i]>smaxi){
                smaxi=nums[i];
            }
        }
        return (smaxi-1)*(maxi-1);
    }
};