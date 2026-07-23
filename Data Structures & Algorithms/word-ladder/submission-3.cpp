class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        dict.erase(beginWord);

        while(!q.empty()){
            auto [s, step] = q.front();
            q.pop();
            if(s == endWord){
                return step;
            }
            for(int i = 0; i < s.size(); i++){
                string next = s;
                for(char c = 'a'; c <= 'z'; c++){
                    next[i] = c;
                    if(dict.find(next) != dict.end()){
                        dict.erase(next);
                        q.push({next,step+1});
                    }
                }
            }
        }
        return 0;
    
    }
};
