class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;
        //how many possible '(' 's are unmatched?
        for(char c : s){
            if(c == '('){
                low++;
                high++;
            }else if(c == ')'){
                low--;
                high--;
                if(high < 0) return false;
            }else{ //c is *
                high++;
                low--;
                //could be (, or ).
            }
            low = max(0, low);
        }
        return low == 0;
    }
};
