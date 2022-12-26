class Solution {
public:
    bool jump(vector<int>& arr, int pos,vector<int> &visited,int n){
        if(arr[pos]==0){
            return true;
        }
        
        int forward = false;
        if((pos+arr[pos])<n && !visited[pos+arr[pos]]){
            visited[pos+arr[pos]] = 1;
            forward = jump(arr,pos+arr[pos],visited,n);
        }
        
        int backward = false;
        if((pos-arr[pos])>=0 && !visited[pos-arr[pos]]){
            visited[pos-arr[pos]] = 1;
            backward = jump(arr,pos-arr[pos],visited,n);
        }
        
        return forward||backward;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> visited(n,0);
        return jump(arr,start,visited,n);
    }
};