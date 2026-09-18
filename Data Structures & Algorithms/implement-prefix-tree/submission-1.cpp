class PrefixTree {
    std::array<std::unique_ptr<PrefixTree>, 26>chr{};    
    bool isLeaf = false;
public:
    PrefixTree() {
    }
    
    void insert(string word) {
        if(!chr[word[0] - 'a'])
            chr[word[0] - 'a'] = make_unique<PrefixTree>();
        if(word.size() == 1) chr[word[0]-'a']->isLeaf = true;
        else
            chr[word[0] - 'a']->insert(word.substr(1));
    }
    
    bool search(string word) {
        if(!word.size()) return true;
        else if(!chr[word[0] - 'a']) return false;
        else if(word.size() == 1){
            if(!chr[word[0] - 'a']->isLeaf) return false;
            return true;
        }else 
            return chr[word[0] - 'a']->search(word.substr(1));
    }
    
    bool startsWith(string word) {
        if(!word.size()) return true;
        else if(!chr[word[0] - 'a']) return false;
        else if(word.size() == 1){
            return true;
        }else 
            return chr[word[0] - 'a']->startsWith(word.substr(1));
    }
};
