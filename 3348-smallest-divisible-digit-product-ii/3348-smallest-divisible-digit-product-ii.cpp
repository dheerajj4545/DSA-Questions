class Solution {
public:
    vector<int> getFactors(long long t) {
        vector<int> cnt(4, 0);
        int primes[4] = {2, 3, 5, 7};

        for (int i = 0; i < 4; i++) {
            while (t % primes[i] == 0) {
                t /= primes[i];
                cnt[i]++;
            }
        }

        if (t != 1) return {};

        return cnt;
    }

    vector<int> digitFactors(int d) {
        vector<int> f(4, 0);

        if (d == 2) f[0] = 1;
        else if (d == 3) f[1] = 1;
        else if (d == 4) f[0] = 2;
        else if (d == 5) f[2] = 1;
        else if (d == 6) f[0] = 1, f[1] = 1;
        else if (d == 7) f[3] = 1;
        else if (d == 8) f[0] = 3;
        else if (d == 9) f[1] = 2;

        return f;
    }

    vector<int> subtract(vector<int> a, vector<int> b) {
        for (int i = 0; i < 4; i++)
            a[i] = max(0, a[i] - b[i]);
        return a;
    }

    bool contains(vector<int> a, vector<int> b) {
        for (int i = 0; i < 4; i++)
            if (b[i] < a[i])
                return false;
        return true;
    }

    vector<int> getDigitCount(vector<int> cnt) {
        vector<int> res(10, 0);

        res[8] = cnt[0] / 3;
        cnt[0] %= 3;

        res[9] = cnt[1] / 2;
        cnt[1] %= 2;

        res[4] = cnt[0] / 2;
        cnt[0] %= 2;

        if (cnt[0] && cnt[1]) {
            res[6] = 1;
            cnt[0] = 0;
            cnt[1] = 0;
        }

        if (cnt[1] && res[4]) {
            res[6] = 1;
            res[2] = 1;
            res[4] = 0;
            cnt[1] = 0;
        }

        res[2] += cnt[0];
        res[3] += cnt[1];
        res[5] = cnt[2];
        res[7] = cnt[3];

        return res;
    }

    int digitCountSum(const vector<int>& cnt) {
        int sum = 0;
        for (int i = 2; i <= 9; i++)
            sum += cnt[i];
        return sum;
    }

    string construct(const vector<int>& cnt) {
        string res;

        for (int d = 2; d <= 9; d++)
            res.append(cnt[d], char('0' + d));

        return res;
    }

    vector<int> getPrefixFactors(const string& s) {
        vector<int> cnt(4, 0);

        for (char c : s) {
            vector<int> f = digitFactors(c - '0');

            for (int i = 0; i < 4; i++)
                cnt[i] += f[i];
        }

        return cnt;
    }

    string smallestNumber(string num, long long t) {
        vector<int> need = getFactors(t);

        if (need.empty())
            return "-1";

        vector<int> minDigits = getDigitCount(need);

        if (digitCountSum(minDigits) > (int)num.size()) {
            return construct(minDigits);
        }

        vector<int> total = getPrefixFactors(num);

        int firstZero = num.find('0');

        if (firstZero == string::npos) {
            firstZero = num.size();

            if (contains(need, total))
                return num;
        }

        vector<int> suffixFactors = total;

        for (int i = (int)num.size() - 1; i >= 0; i--) {
            int d = num[i] - '0';

            vector<int> df = digitFactors(d);
            suffixFactors = subtract(suffixFactors, df);

            if (i > firstZero)
                continue;

            int remaining = num.size() - 1 - i;

            for (int bigger = d + 1; bigger <= 9; bigger++) {
                vector<int> biggerFactors = digitFactors(bigger);

                vector<int> required = subtract(need, suffixFactors);
                required = subtract(required, biggerFactors);

                vector<int> digits = getDigitCount(required);

                if (digitCountSum(digits) <= remaining) {
                    string ans = num.substr(0, i);
                    ans += char('0' + bigger);

                    int ones = remaining - digitCountSum(digits);
                    ans.append(ones, '1');

                    ans += construct(digits);

                    return ans;
                }
            }
        }

        vector<int> digits = getDigitCount(need);
        int len = num.size() + 1;
        int used = digitCountSum(digits);

        return string(len - used, '1') + construct(digits);
    }
};