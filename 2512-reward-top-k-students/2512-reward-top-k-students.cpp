
class Solution {  
public:
    
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
    unordered_set<string> pos(begin(positive_feedback), end(positive_feedback)),   neg(begin(negative_feedback), end(negative_feedback));
    unordered_map<int, int> mp;
    int n = report.size();
    for(int i = 0;i < n; ++i){
        int sz = report[i].size(), id = student_id[i];
		
        for(int j = 0; j < sz; j++){
            string p;
            while(j < sz && report[i][j] != ' ') p+= report[i][j], j++;
            if(pos.count(p)) mp[id]+=3;
            if(neg.count(p)) mp[id]--;
        }
    }
    
    sort(begin(student_id), end(student_id), [&](auto a, auto b){ 
        return mp[a] == mp[b]? a < b : mp[b] < mp[a];
    });
    
    student_id.resize(k);
    return student_id;
}            
                            
};






