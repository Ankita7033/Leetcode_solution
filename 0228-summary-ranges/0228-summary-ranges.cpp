class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;

        int n = nums.size();

        for (int i = 0; i < n; ) {
            int start = nums[i];

            // Find the end of the consecutive range
            while (i + 1 < n && nums[i + 1] == nums[i] + 1) {
                i++;
            }

            int end = nums[i];

            // Single number
            if (start == end) {
                ans.push_back(to_string(start));
            }
            // Range
            else {
                ans.push_back(to_string(start) + "->" + to_string(end));
            }

            i++;
        }

        return ans;
    }
};