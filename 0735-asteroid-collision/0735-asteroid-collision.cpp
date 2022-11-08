class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;
        
        st.push(asteroids[0]);
        int i = 1;
        int n = asteroids.size();
        
        while(i<n){
            if(!st.empty()){
                if(st.top()>0){
                    if(asteroids[i]<0){
                        int replace =asteroids[i]; 
                        int top;
                        while(true && !st.empty()){
                            top = st.top();
                            if(top<0 || replace>0)
                                break;
                            st.pop();
                            if(top!=(-replace)){
                                if(top>(-replace)){
                                    st.push(top);
                                    replace = top;
                                }    
                            }
                            else{
                                break;
                            }
                        }
                        if(top<-replace){
                            st.push(replace);
                        } 
                    }
                    else{
                        st.push(asteroids[i]);
                    }
                }
                else{
                    st.push(asteroids[i]);
                }
            }
            else{
                st.push(asteroids[i]);
            }
            i++;
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};