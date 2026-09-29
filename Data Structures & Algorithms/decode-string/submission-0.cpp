class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decode(s,i);
    }
    string decode(string& s, int& i){
        int n = s.size();
        string res;
        while(i < n && s[i] != ']'){
            if(isalpha(s[i])){
                res += s[i];
                i++;
            }else if(isdigit(s[i])){
                int num = 0;
                while(i < n && isdigit(s[i])){
                    num *= 10;
                    num += (s[i] - '0');
                    i++;
                }
                i++; //skip the [
                string part = decode(s, i);
                i++; //skip the ]
                for(int i = 0; i < num; i++){
                    res += part;
                }
            }
        }
        return res;
    }
};