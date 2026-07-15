class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        if(n==1){
            return n;
        }
        int sumodd= n*n ;
        int sumEven= n*(n+1) ;
        
        int maxi = 0;
        int m = min(sumodd,sumEven);
        cout<<m;
        for(int j=1;j<m;j++){
            if(sumEven%j==0 && sumodd%j==0){
                maxi = max(maxi,j);
                cout<<maxi;
            }
        }

        return maxi;
         

    }
};