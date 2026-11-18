class Solution {
public:
    string sortString(string s) {
        int freq[26] = {0};
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        string result = "";
        int n = s.length();
        
        while (result.length() < n) {
            // Steps 1-3: Pick characters in strictly increasing order
            for (int i = 0; i < 26; i++) {
                if (freq[i] > 0) {
                    result += (char)('a' + i);
                    freq[i]--;
                }
            }
            
            // Steps 4-6: Pick characters in strictly decreasing order
            for (int i = 25; i >= 0; i--) {
                if (freq[i] > 0) {
                    result += (char)('a' + i);
                    freq[i]--;
                }
            }
        }
        
        return result;
    }
};
