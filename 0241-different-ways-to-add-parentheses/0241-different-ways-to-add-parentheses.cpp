class Solution {
public:
    unordered_map<string, vector<int>> memo;

    vector<int> diffWaysToCompute(string expression) {
        if (memo.count(expression))
            return memo[expression];

        vector<int> ans;

        // Base case: expression is just a number
        bool isNumber = true;

        for (int i = 0; i < expression.size(); i++) {
            char op = expression[i];

            if (op == '+' || op == '-' || op == '*') {
                isNumber = false;

                // Split around this operator
                string leftExp = expression.substr(0, i);
                string rightExp = expression.substr(i + 1);

                vector<int> left = diffWaysToCompute(leftExp);
                vector<int> right = diffWaysToCompute(rightExp);

                // Combine every possible left result
                // with every possible right result
                for (int a : left) {
                    for (int b : right) {
                        if (op == '+')
                            ans.push_back(a + b);
                        else if (op == '-')
                            ans.push_back(a - b);
                        else
                            ans.push_back(a * b);
                    }
                }
            }
        }

        // No operator => just a number
        if (isNumber)
            ans.push_back(stoi(expression));

        return memo[expression] = ans;
    }
};