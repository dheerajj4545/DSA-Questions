class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pre(n),suff(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++)
            {
                pre[i]=max(pre[i-1],nums[i]);
            }
        suff[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
            {
                suff[i]=min(suff[i+1],nums[i]);
            }
        if(nums[0]-suff[0]<=k) return 0;
        for(int i=1;i<n;i++)
            {
                if(pre[i]-suff[i]<=k) return i;
            }
        return -1;
    }
};