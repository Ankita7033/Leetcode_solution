class Solution {
public:
    int digitFrequencyScore(int n) {

        vector<int> freq(10, 0);

        while (n > 0) {
            freq[n % 10]++;
            n /= 10;
        }

        int score = 0;

        for (int digit = 0; digit <= 9; digit++) {
            score += digit * freq[digit];
        }

        return score;
    }
};