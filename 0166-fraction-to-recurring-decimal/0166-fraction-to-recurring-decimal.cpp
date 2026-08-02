class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string ans;

        long long n = numerator;
        long long d = denominator;

        if ((n < 0) ^ (d < 0))
            ans += '-';

        n = abs(n);
        d = abs(d);

        ans += to_string(n / d);

        long long rem = n % d;
        if (rem == 0) return ans;

        ans += '.';

        unordered_map<long long, int> mp;

        while (rem) {
            if (mp.count(rem)) {
                ans.insert(mp[rem], "(");
                ans += ")";
                break;
            }

            mp[rem] = ans.size();
            rem *= 10;
            ans += to_string(rem / d);
            rem %= d;
        }

        return ans;
    }
};