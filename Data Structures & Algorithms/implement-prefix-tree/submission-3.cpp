class TrieNode{
    std::array<std::unique_ptr<TrieNode>, 26> node {};
    bool isLeaf = false;
public:

    TrieNode(){}

    void insert(string_view word){
        if(!node[word[0] - 'a']) 
            node[word[0] - 'a'] = make_unique<TrieNode>();
        if(word.size() == 1)
            node[word[0] - 'a']->isLeaf = true;
        else
            node[word[0] - 'a']->insert(word.substr(1));
            
        }

    bool search(string_view word) {
        if(node[word[0] - 'a'] == nullptr) return false;
        if(word.size() == 1){
            if(!node[word[0] - 'a']->isLeaf) return false;
            return true;
        }
        return node[word[0] - 'a']->search(word.substr(1));
    }

    bool startsWith(string_view prefix){
        if(!node[prefix[0] - 'a']) return false;
        if(prefix.size() == 1) return true; 
        return node[prefix[0] - 'a']->startsWith(prefix.substr(1));
    }
};

class PrefixTree {
    std::unique_ptr<TrieNode> root {};
public:
    PrefixTree() {
        root = std::make_unique<TrieNode>();
    }
    
    void insert(string word) {
       root->insert(word); 
    }
    
    bool search(string word) {
       return root->search(word); 
    }
    
    bool startsWith(string prefix) {
       return root->startsWith(prefix); 
    }
};
