class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<int, string>>q;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(dict.find(endWord) == dict.end()) return 0;
        q.push({1,beginWord});
        dict.erase(beginWord);
        while(!q.empty()){
            auto [step, word] = q.front();
            q.pop();
            if(word == endWord) return step;
            for(int l = 0; l < word.size();l++){
                string curr = word;
                for(char c = 'a'; c <= 'z'; c++){
                    curr[l] = c;
                    if(dict.find(curr) != dict.end()){
                        dict.erase(curr);
                        q.push({step+1,curr});
                    }
                }
            }
        }
        return 0;
    }
};
