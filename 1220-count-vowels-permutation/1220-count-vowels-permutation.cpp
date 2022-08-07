class Solution {
public:
    
    int countVowelPermutation(int n) {
        long long int dp[n+1][5];
        long long int ans=0;
        if(n==1){
            return 5;
        }
        if(n==2){
            return 10;
        }
        for(int k=0;k<5;k++){
            dp[0][k]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<5;j++){
                if(j==0){
                    dp[i][j]=dp[i-1][1];
                    if(dp[i][j]>(1000000007)){
                        dp[i][j] = dp[i][j]%(1000000007);
                    }
                }
                else if(j==1){
                    dp[i][j]=dp[i-1][0] + dp[i-1][2];
                    if(dp[i][j]>(1000000007)){
                        dp[i][j] = dp[i][j]%(1000000007);
                    }
                }
                else if(j==2){
                    dp[i][j]=dp[i-1][0] + dp[i-1][1]+dp[i-1][3] + dp[i-1][4];
                    if(dp[i][j]>(1000000007)){
                        dp[i][j] = dp[i][j]%(1000000007);
                    }
                }
                else if(j==3){
                    dp[i][j]=dp[i-1][2] + dp[i-1][4];
                    if(dp[i][j]>(1000000007)){
                        dp[i][j] = dp[i][j]%(1000000007);
                    }
                }
                else if(j==4){
                    dp[i][j]=dp[i-1][0];
                    if(dp[i][j]>(1000000007)){
                        dp[i][j] = dp[i][j]%(1000000007);
                    }
                }
            }
        }
        
        for(int i=0;i<5;i++){
            if(ans>(pow(10,9)+7)){
                ans = ans%(1000000000+7);
            }
            ans+=dp[n-1][i];
        }
        
        if(ans>(1000000000+7)){
                ans = ans%(1000000000+7);
        }
        return ans;
    }
};