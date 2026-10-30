class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        vector<int> ans(128, 0);

        for (int i = 0; i < jewels.size(); i++) {
            ans[jewels[i]] = 1;
        }

        for (int i = 0; i < stones.size(); i++) {
            if (ans[stones[i]] == 1) {
                count++;
            }
        }
            return count;
        }
    };