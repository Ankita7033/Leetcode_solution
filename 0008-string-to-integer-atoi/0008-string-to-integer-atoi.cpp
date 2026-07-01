class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int n = s.length();

        // Skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        // Determine sign
        int sign = 1;

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        long long result = 0;

        while (i < n && isdigit(s[i])) {

            int digit = s[i] - '0';

            // Overflow check
            if (result > INT_MAX / 10 ||
                (result == INT_MAX / 10 &&
                 digit > (sign == 1 ? 7 : 8))) {

                return sign == 1 ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;

            i++;
        }

        return sign * result;
    }
};