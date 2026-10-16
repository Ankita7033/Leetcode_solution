class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> answer(n);
        int prev = -n;

        // Left to right: distance to the previous occurrence of c
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                prev = i;
            }
            answer[i] = i - prev;
        }

        // Right to left: minimize using the next occurrence of c
        prev = 2 * n;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c) {
                prev = i;
            }
            answer[i] = min(answer[i], prev - i);
        }

        return answer;
    }
};