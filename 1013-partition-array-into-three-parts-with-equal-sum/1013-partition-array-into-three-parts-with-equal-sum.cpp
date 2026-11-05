class Solution {
public:

    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum=0;
        for(int num:arr){
            sum+=num;
        }
        if(sum%3!=0) return false;
        sum=sum/3;
        int curr=0,ans=0;
        for (int num :arr){
            curr+=num;
            if (curr==sum){
                curr=0;
                ans+=1;
            }
            if(ans==3){
                return true;
            }

        }
        return false;
    }
};