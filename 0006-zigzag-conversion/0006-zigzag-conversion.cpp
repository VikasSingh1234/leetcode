class Solution {
public:
    string convert(string s, int numRows) {
        vector<char> v[numRows];
        int counter=0;
        if(numRows==1)
            return s;
        string res;
        
        int dir = 1;
        for(int i=0;i<s.length();i++){
            if(dir==1){
                v[counter++].push_back(s[i]);
                if(counter==numRows){
                    dir=-1;
                    counter-=2;
                }
            }
            else{
                v[counter--].push_back(s[i]);
                if(counter<0){
                    dir =1;
                    counter  = 1;
                }
                if(counter==0){
                    dir=1;
                }
            }
        }
        for(int i=0;i<numRows;i++){
            for(auto x:v[i]){
                res.push_back(x);
            }
        }
        return res;
    }
};