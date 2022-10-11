class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int> st;
        long long int res;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                if(tokens[i]=="+"){
                    res =second;
                    res = res+first;
                    st.push(res);
                }
                else if(tokens[i]=="-"){
                    res =second;
                    res = res-first;
                    st.push(res);
                }
                else if(tokens[i]=="*"){
                    res =second;
                    res = res*first;
                    st.push(res);
                }
                else{
                    res =second;
                    res = res/first;
                    st.push(res);
                }
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};