class Solution {
public:
    vector<int>generateRow(int rows){
        vector<int>res;
        int ans=1;
        res.push_back(ans);
        for(int i=1;i<rows;i++){
            ans=ans*(rows-i);
            ans=ans/i;
            res.push_back(ans);
        }
        return res;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};