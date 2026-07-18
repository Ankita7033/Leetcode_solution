class Solution {
public:
    int findGCD(vector<int>& nums) {
       int mini =1001;
       int maxi= 0;
       for(int i=0;i<nums.size();i++){
        mini = min(mini,nums[i]);
        maxi = max(maxi,nums[i]);
       }

        int max_gcd = -1;
        for(int i=1;i<=maxi;i++){
            if(mini%i==0 && maxi%i ==0){
                max_gcd= max(max_gcd,i);
            }
        }

        return max_gcd;
    }
};