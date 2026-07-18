class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        int ans=1;
        int fin=1;
        for(int i=1;i<=maxi;i++){
            if(mini%i==0&&maxi%i==0){
                ans=i;
            }
            fin=max(fin,ans);
        }
        return fin;
    }
};