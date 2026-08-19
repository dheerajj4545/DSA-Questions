class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int n=nums.size();
        int m=nums[0].size();
        int low=0;
        int high=n*m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int row=mid/m;
            int col=mid%m;
            if(nums[row][col]==target) return true;
            else if(nums[row][col]<target) low=mid+1;
            else high=mid-1;
        }
        return false;
    }
};