class Solution {
public:
    int longestPalindrome(string s) {
        int freq[128] = {0};

        for (char c : s) {
            freq[c]++;
        }

        int ans = 0;
        bool hasOdd = false;

        for (int count : freq) {
            ans += (count / 2) * 2;

            if (count % 2 == 1) {
                hasOdd = true;
            }
        }

        if (hasOdd) {
            ans++;
        }

        return ans;
    }
};