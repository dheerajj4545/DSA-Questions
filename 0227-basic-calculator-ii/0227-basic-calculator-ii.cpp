class Solution {
public:
    int calculate(string s) {
        int num = 0;
        char sign = '+';
        stack<int> st;
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }
            if ((!isdigit(s[i]) && s[i] !=' ') || i == s.length() - 1) {
                if (sign == '+') {
                    st.push(num);
                } else if (sign == '-') {
                    st.push(-num);
                } else if (sign == '*') {
                    int x = st.top();
                    st.pop();
                    st.push(x * num);
                } else if (sign == '/') {
                    int x = st.top();
                    st.pop();
                    st.push(x / num);
                }
                sign = s[i];
                num = 0;
            }
            
        }
        int ans = 0;
            while (!st.empty()) {
                ans += st.top();
                st.pop();
            }
        return ans;
    }
};