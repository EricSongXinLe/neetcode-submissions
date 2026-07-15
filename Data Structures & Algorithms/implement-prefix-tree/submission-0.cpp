class TrieNode{
public:
    vector<TrieNode*> children;
    bool isEnd;
    TrieNode(){
        children.resize(26,nullptr);
        isEnd = false;
    }
};

class PrefixTree {
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
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
        TrieNode* curr = root;
        for(char c : word){
            if((*curr).children[c - 'a'] == nullptr){
                return false; // does not exist.
            }
            curr = (*curr).children[c - 'a'];
        }
        return (*curr).isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char c : prefix){
            if((*curr).children[c - 'a'] == nullptr){
                return false; // does not exist.
            }
            curr = (*curr).children[c - 'a'];
        }
        return true;
    }
    TrieNode* root;
};


