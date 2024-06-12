class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mpp;
        sort(hand.begin(),hand.end());
        
        for(int i=0;i<hand.size();i++){
            mpp[hand[i]]++;
        }
        
        if(hand.size()%groupSize!=0){
            return false;
        }
        
        for(int i=0;i<hand.size();i++){
            if(mpp[hand[i]]==0){
                continue;
            }
            else{
                int search = hand[i];
                for(int j=0;j<groupSize;j++){

                        if(mpp[search]!=0){
                            mpp[search]--;
                            search++;
                        }
                        else{
                            return false;
                        }
                }
            }
        }
        return true;
        
    }
};