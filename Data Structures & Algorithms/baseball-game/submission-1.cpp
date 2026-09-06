class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>vals;
        for(string& s : operations){
            if(s == "+"){
                int o1 = vals.top();
                vals.pop();
                int o2 = vals.top();
                vals.push(o1);
                vals.push(o1+o2);
            }else if(s == "D"){
                int o = vals.top();
                vals.push(o*2);
            }else if(s == "C"){
                vals.pop();
            }else{
                vals.push(stoi(s));
            }
        }
        int sum = 0;
        while(!vals.empty()){
            sum+=vals.top();
            vals.pop();
        }
        return sum;
    }
};