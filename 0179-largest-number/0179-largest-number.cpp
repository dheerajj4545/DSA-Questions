class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;

        for(int x : nums)
            arr.push_back(to_string(x));

        sort(arr.begin(), arr.end(), [](string a, string b) {
            return a + b > b + a;
        });

        string ans = "";

        for(string x : arr)
            ans += x;

        if(ans[0] == '0')
            return "0";

        return ans;
    }
};