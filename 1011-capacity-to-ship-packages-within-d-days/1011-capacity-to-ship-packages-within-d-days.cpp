class Solution {
public:
    int need(vector<int>&nums,int capacity){
        int currentLoad=0;
        int days=1;
        for(int i=0;i<nums.size();i++){
            if(currentLoad+nums[i]>capacity){
                days++;
                currentLoad=nums[i];
            }else{
                currentLoad+=nums[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<high){
            int mid=low+(high-low)/2;
            int needed=need(weights,mid);
            if(needed<=days){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};