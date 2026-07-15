class TrieNode{
public:
    vector<TrieNode*>children;
    bool isEnd;
    TrieNode(){
        children.resize(26,nullptr);
        isEnd = false;
    }
};
class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char c : word){
            if((*curr).children[c - 'a'] == nullptr){
                (*curr).children[c - 'a'] = new TrieNode();
            }
            curr = (*curr).children[c - 'a'];
        }
        (*curr).isEnd = true;
    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }
    TrieNode* root;
private:
bool dfs(TrieNode* curr, string& word, int idx){
    if(!curr){
        return false;
    }

    if(idx == word.size()){
        return curr->isEnd;
    }

    char curr_char = word[idx];

    if(curr_char == '.'){
        for(TrieNode* child : curr->children){
            if(dfs(child, word, idx + 1)){
                return true;
            }
        }
        return false;
    }
    else{
        TrieNode* child = curr->children[curr_char - 'a'];
        return dfs(child, word, idx + 1);
    }
}
};
