class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int left = 0;
        int right = n - 1;
        
        for (int pos = n - 1; pos >= 0; pos--) {
            if (abs(nums[left]) > abs(nums[right])) {
                res[pos] = nums[left] * nums[left];
                left++;
            } else {
                res[pos] = nums[right] * nums[right];
                right--;
            }
        }
        
        return res;
    }
};
