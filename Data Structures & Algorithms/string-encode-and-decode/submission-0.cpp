class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(string& str : strs){
            int len = str.size();
            res += to_string(len);
            res += '#';
            res += str;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        if (s.size() < 2)return res; 
        int ptr = 0;
        while(ptr <= s.size() - 1){
            int len = 0;
            //we see a num
            string num;
            while(s[ptr] != '#'){
                num += s[ptr];
                ptr++;
            }
            ptr++; //skip the #
            len = stoi(num);
            
            res.push_back(s.substr(ptr,len));
            ptr += len;
        }
        return res;
    }
};
