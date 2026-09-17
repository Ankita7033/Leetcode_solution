class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        
        // best[i] = minimum length of a target-sum subarray
        // completely inside arr[0...i]
        vector<int> best(n, INT_MAX);
        
        int left = 0;
        int sum = 0;
        int ans = INT_MAX;
        
        for (int right = 0; right < n; right++) {
            sum += arr[right];
            
            // Shrink window if sum becomes >= target
            while (sum > target) {
                sum -= arr[left++];
            }
            
            if (sum == target) {
                int len = right - left + 1;
                
                // Check if there is a previous non-overlapping subarray
                if (left > 0 && best[left - 1] != INT_MAX) {
                    ans = min(ans, len + best[left - 1]);
                }
                
                // Store the shortest valid subarray up to right
                if (right == 0)
                    best[right] = len;
                else
                    best[right] = min(best[right - 1], len);
            }
            else {
                // No new valid subarray ending at right
                if (right > 0)
                    best[right] = best[right - 1];
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};