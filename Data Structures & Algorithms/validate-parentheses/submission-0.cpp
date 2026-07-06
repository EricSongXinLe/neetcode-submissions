class Solution {
public:
    bool isValid(string s) {
                stack<char>stk;
        int size = s.size();
        for(int i = 0; i<size;++i){
            char curr = s[i];
            if(curr == '(' || curr == '[' || curr == '{'){
                stk.push(curr);
            }else{ // ) } ]
                if (stk.empty()) return false;
                char open = stk.top();
                if(open == '('){
                    if(curr == ')') {
                        stk.pop();
                    }else{
                        return false;
                    }
                } else if(open == '['){
                    if(curr == ']') {
                        stk.pop();
                    }else{
                        return false;
                    }
                } else if(open == '{'){
                    if(curr == '}') {
                        stk.pop();
                    }else{
                        return false;
                    }
                }
            }
        }
        return stk.empty();
    }
};
