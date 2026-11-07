class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string result = "";
        int count = 0;
        
        // Iterate through the string backwards
        for (int i = s.length() - 1; i >= 0; i--) {
            // Ignore existing dashes
            if (s[i] != '-') {
                // Insert a dash every k characters
                if (count > 0 && count % k == 0) {
                    result += '-';
                }
                // Convert to uppercase and add to the result
                result += toupper(s[i]);
                count++;
            }
        }
        
        // Reverse the string back to its original order
        reverse(result.begin(), result.end());
        return result;
    }
};
