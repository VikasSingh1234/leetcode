class Solution {
public:
    bool check(vector<int>& matchsticks,int sides[],int index){
        if(index==matchsticks.size()){
            if(sides[0]==0 && sides[1]==0 && sides[2]==0 && sides[3]==0){
                return true;
            }
        }
        
        for(int i=0;i<4;i++){
            if(sides[i]>=matchsticks[index]){
                sides[i]-= matchsticks[index];
                if(check(matchsticks,sides,index+1))
                    return true;
                sides[i]+= matchsticks[index];
            }
        }
        return false;
        
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        
        for(int i=0;i<matchsticks.size();i++){
            sum+=matchsticks[i];
        }
        
        if(sum%4==0){
            int sides[4];
            for(int i=0;i<4;i++){
                sides[i]=sum/4;
            }
            
            sort(matchsticks.begin(),matchsticks.end(),greater<int>());
            return check(matchsticks,sides,0);
        }
        else{
            return false;
        }
    }
};