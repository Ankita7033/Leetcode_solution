class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sumB = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        int delta = (sumB - sumA) / 2;
        
        // Sort Bob's array to perform Binary Search
        sort(bobSizes.begin(), bobSizes.end());
        
        for (int x : aliceSizes) {
            int targetY = x + delta;
            
            // O(log M) binary search verification
            if (binary_search(bobSizes.begin(), bobSizes.end(), targetY)) {
                return {x, targetY};
            }
        }
        
        return {};
    }
};
