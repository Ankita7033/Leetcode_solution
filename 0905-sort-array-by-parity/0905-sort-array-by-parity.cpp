class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            // If left is odd and right is even, swap them
            if (nums[left] % 2 != 0 && nums[right] % 2 == 0) {
                swap(nums[left], nums[right]);
            }
            
            // Move left forward if it's already even
            if (nums[left] % 2 == 0) {
                left++;
            }
            
            // Move right backward if it's already odd
            if (nums[right] % 2 != 0) {
                right--;
            }
        }
        
        return nums;
    }
};
