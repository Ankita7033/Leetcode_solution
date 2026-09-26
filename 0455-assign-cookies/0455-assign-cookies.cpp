class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0;  // child
        int j = 0;  // cookie
        int count = 0;

        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                // Cookie can satisfy this child
                count++;
                i++;
            }

            // Whether used or too small, move to next cookie
            j++;
        }

        return count;
    }
};