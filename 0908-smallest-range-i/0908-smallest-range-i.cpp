class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mini = nums[0] + k;
        for (int i = 0; i < nums.size(); i++){
            if(nums[i]>mini){
                int diff=nums[i]-mini ;
                if(diff>=k) nums[i]-=k ;
                else nums[i]=mini ;
            }
            if(nums[i]<mini){
                int diff= mini-nums[i] ;
                if(diff>=k) nums[i]+=k ;
                else nums[i]=mini ;
            }
        }
        sort(nums.begin(),nums.end());
        return nums[nums.size()-1] - nums[0];
    }
};