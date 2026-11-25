class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // Step 1: Sort in ascending order
        sort(nums.begin(), nums.end());
        
        // Step 2: Flip negative numbers as long as k > 0
        for (int i = 0; i < nums.size() && k > 0; i++) {
            if (nums[i] < 0) {
                nums[i] = -nums[i];
                k--;
            }
        }
        
        // Step 3: If remaining k is odd, flip the smallest element
        if (k % 2 == 1) {
            sort(nums.begin(), nums.end());
            nums[0] = -nums[0];
        }
        
        // Step 4: Return the total sum
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        return totalSum;
    }
};
