class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int d : digits) {
            freq[d]++;
        }

        int ans = 0;

        for (int num = 100; num <= 999; num++) {
            // Must be even
            if (num % 2 != 0) continue;

            int x = num;
            int d3 = x % 10; x /= 10;
            int d2 = x % 10; x /= 10;
            int d1 = x % 10;

            // Check whether required copies are available
            vector<int> need(10, 0);
            need[d1]++;
            need[d2]++;
            need[d3]++;

            bool possible = true;
            for (int d = 0; d <= 9; d++) {
                if (need[d] > freq[d]) {
                    possible = false;
                    break;
                }
            }

            if (possible) ans++;
        }

        return ans;
    }
};