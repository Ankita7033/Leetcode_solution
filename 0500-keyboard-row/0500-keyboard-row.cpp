class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        // Map each letter 'a'-'z' to its row index (0, 1, or 2)
        // a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z
        vector<int> rowMap = {1, 2, 2, 1, 0, 1, 1, 1, 0, 1, 1, 1, 2, 2, 0, 0, 0, 0, 1, 0, 0, 2, 0, 2, 0, 2};
        vector<string> result;
        
        for (const string& word : words) {
            if (word.empty()) continue;
            
            // Find the keyboard row of the first character (case-insensitive)
            int targetRow = rowMap[tolower(word[0]) - 'a'];
            bool isValid = true;
            
            // Verify if all remaining characters belong to the same row
            for (char ch : word) {
                if (rowMap[tolower(ch) - 'a'] != targetRow) {
                    isValid = false;
                    break;
                }
            }
            
            if (isValid) {
                result.push_back(word);
            }
        }
        
        return result;
    }
};
