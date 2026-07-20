class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos=0;
        int neg=1;
        int n=nums.size();
        vector<int>ans(n);
        for(auto x:nums){
            if(x>0) {
            ans[pos]=x;
            pos+=2;
            }
            else{
                ans[neg]=x;
                neg+=2;
            }
        }
        return ans;
    }
};