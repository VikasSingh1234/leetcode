class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            indegree[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int> topoOrder;
        queue<int> q;
        
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int course = q.front();
            q.pop();
            topoOrder.push_back(course);
            
            for(auto x:adj[course]){
                indegree[x]--;
                if(indegree[x]==0)
                    q.push(x);
            }
        }
        
        if(topoOrder.size()==numCourses)
            return topoOrder;
        else{
            topoOrder.clear();
            return topoOrder;
        }
    }
};