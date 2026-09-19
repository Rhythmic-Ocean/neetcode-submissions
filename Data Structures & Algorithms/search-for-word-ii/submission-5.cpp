class Trie{
    std::array<std::unique_ptr<Trie>, 26> nodes {};
    bool isLeaf {false};
public:
    Trie() {}
    void addWord(string_view word){
        if(word.size() == 0) return;
        if(!nodes[word[0] - 'a']){
            nodes[word[0] - 'a'] = make_unique<Trie>();
        }
        if(word.size() == 1) nodes[word[0] - 'a']->isLeaf = true;
        else nodes[word[0] - 'a']->addWord(word.substr(1));
        return;
    }
    bool search(string_view word){
        if(word.size() == 0) return true;
        if(!nodes[word[0] - 'a']) return false;
        if(word.size() == 1){
            if(nodes[word[0] - 'a']->isLeaf) return true;
            return false;
        }
        return nodes[word[0] - 'a']->search(word.substr(1));
    }
    bool startsWith(string_view word){
        if(word.size() == 0) return true;
        if(!nodes[word[0] - 'a']) return false;
        if(word.size() == 1){
            return true;
        }
        return nodes[word[0] - 'a']->startsWith(word.substr(1));
    }
};

class PairHash{
public:
    size_t operator()(const pair<int,int>& p) const{
        return (std::hash<int>()(p.first) ^ std::hash<int>()(p.second) << 1);
    }
};

class Solution {
    Trie trie {};
    vector<string> finalAns {};
    std::string cur_str {};
    unordered_set<pair<int, int>, PairHash> str_indx {};
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
       for(auto& word: words){
        trie.addWord(word);
       }
       size_t row_end = board.size() - 1;
       size_t col_end = board[0].size() - 1;
       for(size_t row_ptr = 0; row_ptr <= row_end; ++row_ptr){
        for(size_t col_ptr = 0; col_ptr <= col_end; ++col_ptr){
            searchWord(board, row_ptr, col_ptr);
        }
       } 
       return finalAns;
    }
    void searchWord(vector<vector<char>>& board, size_t row_ptr, size_t col_ptr){
        cur_str.push_back(board[row_ptr][col_ptr]);
        if(!trie.startsWith(cur_str)){
            cur_str.pop_back();
            return;
        }
        str_indx.insert({row_ptr, col_ptr});
        if(trie.search(cur_str)){
           if(std::ranges::find(finalAns, cur_str) == finalAns.end())
                finalAns.push_back(cur_str); 
        }
        if(row_ptr != 0 && !str_indx.contains({row_ptr - 1, col_ptr})){
            searchWord(board, row_ptr - 1, col_ptr);
        }
        if(col_ptr != 0 && !str_indx.contains({row_ptr, col_ptr - 1})){
            searchWord(board, row_ptr, col_ptr - 1);
        }
        if(row_ptr != (board.size() - 1) && !str_indx.contains({row_ptr + 1, col_ptr})){
            searchWord(board, row_ptr + 1, col_ptr);
        }
        if(col_ptr != (board[0].size() - 1) && !str_indx.contains({row_ptr, col_ptr + 1})){
            searchWord(board, row_ptr, col_ptr + 1);
        }
        cur_str.pop_back();
        str_indx.erase({row_ptr, col_ptr});
        return;
    }
};
