class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>need;
        unordered_map<char,int>window;
        for(char c : t){
            need[c]++;
        }
        int have = 0;
        int needCount = need.size();

        int l = 0;

        int minSize = INT_MAX;
        int start = 0;

        for(int r = 0; r < s.size(); r++){
            char c = s[r];
            window[c]++;
            if(need.count(c) && need[c] == window[c]){
                have++;
            }
            while(have == needCount){ //remove left
                int windowSize = r - l + 1;
                if(windowSize < minSize){
                    start = l;
                    minSize = windowSize;
                }
                char remove = s[l];
                window[remove]--;
                if(need.count(remove) && need[remove] > window[remove]){
                    have--;
                }
                l++;
            }
        }
        if(minSize == INT_MAX) return "";
        return s.substr(start, minSize);
    }
};
