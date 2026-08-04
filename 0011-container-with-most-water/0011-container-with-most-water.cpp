class Solution {
public:
    int maxArea(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int maxArea=0;
        while(i<j){
            int width=j-i;
            int height=min(nums[i],nums[j]);
            int area=width*height;
            maxArea=max(area,maxArea);
            if(nums[i]<nums[j]) i++;
            else j--;
        }
        return maxArea;
    }
};