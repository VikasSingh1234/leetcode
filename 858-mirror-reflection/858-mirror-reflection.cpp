class Solution {
public:
    int mirrorReflection(int p, int q) {
        int dir = 1;
        int turn = 0;
        int val=q;
        if(val==p){
            return 1;
        }
        while(true){
            if(turn==0){
                if(dir==1){
                    val = val+q;
                    if(val==p){
                        return 2;
                    }
                    else if(val>p){
                        val = p - val%p;
                        dir = -dir;
                    }
                    turn = 1;
                }
                else{
                    val = val - q;
                    if(val<0){
                        val = -val;
                        dir = -dir;
                    }
                    turn = 1;
                }
                
            }
            else{
                if(dir==1){
                    val = val+q;
                    if(val==p){
                        return 1;
                    }
                    else if(val>p){
                        val = p - val%p;
                        dir = -dir;
                    }
                    turn = 0;
                }
                else{
                    val = val - q;
                    if(val==0){
                        return 0;
                    }
                    if(val<0){
                        val = -val;
                        dir = -dir;
                    }
                    turn = 0;
                }
                
            }
        }
    }
};