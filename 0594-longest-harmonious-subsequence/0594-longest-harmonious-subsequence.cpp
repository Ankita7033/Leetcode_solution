class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;

        // Count frequency of each number
        for (int num : nums) {
            freq[num]++;
        }

        int ans = 0;

        // Check pairs x and x + 1
        for (auto& [x, count] : freq) {
            if (freq.find(x + 1) != freq.end()) {
                ans = max(ans, count + freq[x + 1]);
            }
        }

        return ans;
    }
};