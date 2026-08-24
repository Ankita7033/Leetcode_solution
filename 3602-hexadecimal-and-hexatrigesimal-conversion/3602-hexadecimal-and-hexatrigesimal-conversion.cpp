class Solution {
public:
    string convert(long long num, int base) {
        string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string res;

        while (num > 0) {
            res += chars[num % base];
            num /= base;
        }

        reverse(res.begin(), res.end());
        return res;
    }

    string concatHex36(int n) {
        long long n2 = 1LL * n * n;
        long long n3 = 1LL * n * n * n;

        string hex = convert(n2, 16);
        string hex36 = convert(n3, 36);

        return hex + hex36;
    }
};