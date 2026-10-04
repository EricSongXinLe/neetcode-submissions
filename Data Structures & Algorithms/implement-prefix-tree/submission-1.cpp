class TrieNode{
public:
    TrieNode(){
        children.resize(26);
        isEnd= false;
    }
    vector<TrieNode*>children;
    bool isEnd;
};
class PrefixTree {
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(int i = 0; i < word.size(); i++){
            char c = word[i];
            if(curr->children[c-'a'] == nullptr){
                curr->children[c-'a'] = new TrieNode();
            }
            curr = curr->children[c-'a'];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(char c : word){
            if(curr->children[c-'a'] == nullptr){
                return false;
            }
            curr = curr->children[c-'a'];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char c : prefix){
            if(curr->children[c-'a'] == nullptr){
                return false;
            }
            curr = curr->children[c-'a'];
        }
        return true;
    }
private:
    TrieNode* root;
};
