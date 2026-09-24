class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n);
        dp[0]=1;
        int i2=0,i3=0,i5=0;
        for(int i=1;i<n;i++){
            long long a=1LL*dp[i2]*2;
            long long b=1LL*dp[i3]*3;
            long long c=1LL*dp[i5]*5;
            long long mini=min({a,b,c});
            dp[i]=mini;
            if(mini==a) i2++;
            if(mini==b) i3++;
            if(mini==c) i5++;
        }
        return dp[n-1];
    }
};