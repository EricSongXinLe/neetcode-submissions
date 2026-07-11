class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> exists;
        for(int& num :nums){
            exists.insert(num);
        }
        int longest = 0;
        for(const int& num :exists){
            if(exists.count(num - 1)){
                continue; //Not start
            }else{
                //this is the start
                int curr_len = 1;
                int curr_num = num;
                while(exists.count(curr_num + 1)){
                    curr_len++;
                    curr_num++;
                }
                longest = max(longest, curr_len);
            }
        }
        return longest;
    }
};
