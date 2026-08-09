class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(string& str : strs){
            int sz = str.size();
            res = res + '#' + to_string(sz) + '#';
            res = res + str;
        }
        return res;
    }

    vector<string> decode(string s) {
        //#x#str1#xx#str2
        vector<string>res;
        int i = 0;
        while( i < s.size()){
            char c = s[i];
            int len = -1;
            if( c == '#'){
                //start of length
                i++;
                string str_len;
                while(s[i] != '#'){
                    str_len += s[i];
                    i++;
                }
                //now s[i] is on second '#'.
                len = stoi(str_len);
                i++;
                res.push_back(s.substr(i, len));
                i+=len;
            }
        }
        return res;
    }
};
