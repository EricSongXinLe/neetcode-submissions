class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i1 = 0;
        int i2 = 0;
        int l1 = word1.size();
        int l2 = word2.size();
        string res;
        while(i1 < l1 && i2 < l2){
            res += word1[i1];
            i1++;
            res += word2[i2];
            i2++;
        }
        if(i1 == l1){
            res += word2.substr(i2, l2 - i2);
        }else{
            res += word1.substr(i1, l1 - i1);
        }
        return res;
    }
};