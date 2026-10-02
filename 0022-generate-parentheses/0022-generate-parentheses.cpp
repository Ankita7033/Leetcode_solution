class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        function<void(string, int, int)> backtrack =
            [&](string current, int open, int close) {

                // Complete valid combination
                if (current.length() == 2 * n) {
                    result.push_back(current);
                    return;
                }

                // We can add '(' if we haven't used all n
                if (open < n) {
                    backtrack(current + "(", open + 1, close);
                }

                // We can add ')' only if it won't make the string invalid
                if (close < open) {
                    backtrack(current + ")", open, close + 1);
                }
            };

        backtrack("", 0, 0);

        return result;
    }
};