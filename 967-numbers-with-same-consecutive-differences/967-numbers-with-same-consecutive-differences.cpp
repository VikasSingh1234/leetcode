class Solution {
public:
    
    void helper(int n,int k,int digit,int l,int num,vector<int> &res){
        if(l==n){
            res.push_back(num);
            return ;
        }
        // else if(k==0){
        //     num = num*10 + digit;
        //     helper(n,k,digit,l+1,num,res);
        // }
        else{
            int num2 = num;
            if((digit-k)>=0){
                num = num*10 + (digit-k);
                helper(n,k,(digit-k),l+1,num,res);
            }
            if(k){
                if((digit+k)<=9){
                    num2 = num2*10 + (digit+k);
                    helper(n,k,(digit+k),l+1,num2,res);
                }
            }
        }
        
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        for(int i = 1;i<=9;i++){
            helper(n,k,i,1,i,res);
        }
        return res;
    }
};