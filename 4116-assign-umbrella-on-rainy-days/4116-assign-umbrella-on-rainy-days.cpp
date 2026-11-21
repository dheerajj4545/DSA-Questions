class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        int n = rain.size();

        vector<string> ans(n);
        int alice = 0, bob = 0;

        for (int i = 0; i < n; i++) {

            if (rain[i] == 0) {
                ans[i] = "None";
            }
            else {
                bool a = (i < n - 1 && rain[i + 1] == 1);

                if (a && rain[i] == 1) {
                    if (alice <= bob) {
                        ans[i] = "Alice";
                        alice++;
                    }
                    else {
                        ans[i] = "Bob";
                        bob++;
                    }
                }
                else {
                    ans[i] = "Bob";
                    bob++;
                }
            }
        }

        return ans;
    }
};