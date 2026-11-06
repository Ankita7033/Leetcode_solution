class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        
        for (int i = 0; i < size; i++) {
            // Early exit if we have already placed all required flowers
            if (n <= 0) return true;
            
            // Check if the current plot is empty
            if (flowerbed[i] == 0) {
                // Check if left plot is empty or out of bounds
                bool left_empty = (i == 0 || flowerbed[i - 1] == 0);
                
                // Check if right plot is empty or out of bounds
                bool right_empty = (i == size - 1 || flowerbed[i + 1] == 0);
                
                // If both sides are clear, plant a flower here
                if (left_empty && right_empty) {
                    flowerbed[i] = 1; // Mark as planted
                    n--;              // Reduce required flowers count
                    i++;              // Skip the next plot since we just planted next to it
                }
            }
        }
        
        return n <= 0;
    }
};
