class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        
        int i=0,j=people.size()-1;
        int ans = 0;
        if(j==0){
            return 1;
        }
        while(i<=j){
            ans++;
            if(people[i]+people[j]<=limit)
                i++;
            j--;
        }
        return ans;
    }
};