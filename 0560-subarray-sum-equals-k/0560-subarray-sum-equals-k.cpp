class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>prefixSum;
        int cnt=0;
        int prefix=0;
        prefixSum[0]=1;
        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            int remove=prefix-k;
            if(prefixSum.find(remove)!=prefixSum.end()){
                cnt+=prefixSum[remove];
            }
            prefixSum[prefix]++;
        }
        return cnt;
    }
};