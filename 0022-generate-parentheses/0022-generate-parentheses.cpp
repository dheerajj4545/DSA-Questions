class Solution {
public:
    void generate(int start,int end,string curr,vector<string>&ans){
        if(start==0&&end==0) {
            ans.push_back(curr);
            return;
        }
        if(start>0){
            generate(start-1,end,curr+"(",ans);
        }
        if(end>start){
            generate(start,end-1,curr+")",ans);
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        generate(n,n,"",ans);
        return ans;
    }
};