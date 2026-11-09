class Solution {
    //Question: Is substring s[0]...s[i] valid for some i < s.size()
    //Valid means it forms a group of one or more valid words
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty()) return true;
       std::vector<bool> valid_starts (s.size(), false);
       valid_starts[0] = true;
       for(int j {}; j < s.size(); ++j){
        //when we find a new word we can either continue creating the word or reset the start a new word BUT the validity of that end should be memoized
        //Then on we test the current letter with each valid_ends, and every valid end will be memoized
        //Original Question: is s.size() -1 in valid_end vector
        //we only want to stop if we know the j to s.size()-1 will create valid word/s
        
        //Now we test for valid_ends[i] to j for 0 <= i < valid_ends.size()
        for(int i {}; i < valid_starts.size(); ++i){
            if(valid_starts[i] == false) continue;
            int end = i;
            //If an end to j substring forms a new word it's another valid end to push
            if(std::ranges::find(wordDict, s.substr(end, j-end + 1)) != wordDict.end()){
                if(j+1 < s.size())
                    valid_starts[j+1] = true;
                else return true;
            }
        }
       }
       return false;
    }
};
