class PrefixTree {
    std::array<std::unique_ptr<PrefixTree>, 26>chr{};    
    bool isLeaf = false;
public:
    PrefixTree() {
    }
    
    void insert(string word) {
        if(!chr[word[0] - 'a'])
            chr[word[0] - 'a'] = make_unique<PrefixTree>();
        if(word.size() == 1) isLeaf = true;
        else
            chr[word[0] - 'a']->insert(word.substr(1));
    }
    
    bool search(string word) {
       if(!isLeaf && word.size() <= 1) return false;
       if(!chr[word[0] - 'a']) return false;
       if(isLeaf && word.size() == 1) return true;
       return chr[word[0]-'a']->search(word.substr(1));
    }
    
    bool startsWith(string prefix) {
       if(!chr[prefix[0] - 'a']) return false;
       if(prefix.size() == 1) return true;
       return chr[prefix[0]-'a']->startsWith(prefix.substr(1));
    }
};
