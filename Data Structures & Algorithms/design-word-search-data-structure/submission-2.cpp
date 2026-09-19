class TrieNode{
    std::array<std::unique_ptr<TrieNode>, 26> node {};
    bool isLeaf {};
public:
    TrieNode() {};

    void addWord(string_view word){
        if(word.size() == 0) return;
        if(!node[word[0] - 'a'])
            node[word[0] - 'a'] = std::make_unique<TrieNode>();
        if(word.size() == 1) node[word[0] - 'a']->isLeaf = true;
        else node[word[0] - 'a']->addWord(word.substr(1));
    }

    bool search(string_view word){
        if(word.size() == 0) return true;
        if(word[0] == '.'){
            if(word.size() == 1){
                for(auto& n: node){
                    if(n && n->isLeaf) return true;
                }
                return false;
            }
            for(auto& n: node){
                if(n && n->search(word.substr(1))) return true;
            }
            return false;
        }
        if(!node[word[0] - 'a']) return false;
        if(word.size() == 1){
            if(node[word[0] - 'a']->isLeaf) return true;
            return false;
        }
        return node[word[0] - 'a']->search(word.substr(1));
    }
};

class WordDictionary {
    std::unique_ptr<TrieNode> rootNode {};
public:
    WordDictionary() {
        rootNode = std::make_unique<TrieNode>();
    }
    
    void addWord(string word) {
       rootNode->addWord(word); 
    }
    
    bool search(string word) {
       return rootNode->search(word); 
    }
};
