class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> mpp;
        for(int i=0;i<wordList.size();i++){
            mpp[wordList[i]]++;
        }
        
        if(mpp.find(endWord)==mpp.end()){
            return 0;
        }
        
        int res = 0;
        int m = beginWord.length();
        
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        if(mpp.find(beginWord)!=mpp.end()){
            mpp.erase(beginWord);
        }
        
        while(!q.empty()){
            string word = q.front().first;
            int distance = q.front().second;
            q.pop();
            
            if(word == endWord){
                return distance;
            }
            
            for(int i=0;i<m;i++){
                char original = word[i];
                for(char x='a';x<='z';x++){
                    word[i] = x;
                    
                    if(mpp.find(word)!=mpp.end()){
                        q.push({word,distance+1});
                        mpp.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};