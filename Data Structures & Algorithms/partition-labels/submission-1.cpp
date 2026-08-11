class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>idx(26);
        for(int i = 0; i < s.size(); i++){
            idx[s[i] - 'a'] = i; //index of last seen.
        }
        vector<int>res;
        int start = 0;
        int end = 0;
        for(int i = 0; i < s.size(); i++){
            end = max(end, idx[s[i] - 'a']); //must include last instance of curr.
            if(i == end){ //partition close
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};
