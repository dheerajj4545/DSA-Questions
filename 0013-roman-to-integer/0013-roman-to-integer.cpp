class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mpp={
           {'I',1},
           {'V',5},
           {'X',10},
           {'L',50},
           {'C',100},
           {'D',500},
           {'M',1000},
        };
        int res=0;
        for(int i=0;i<s.length()-1;i++){
            if(mpp[s[i]]<mpp[s[i+1]]){
                res-=mpp[s[i]];
            }else{
                res+=mpp[s[i]];
            }
        }
        return res+mpp[s.back()];
    }
};