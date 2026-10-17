class Solution {
public:
    string foreignDictionary(vector<string>& words) {
       if(words.empty()) return "";
        int n = words.size();
       vector<vector<int>> adj_list(26);
       vector<bool> visited(n, false); 
       vector<int> indegree (26, -1);
       int maxlen {};
       int appearing_letters {};
       //marking each letter that appears
       for(auto& word: words){
        if(maxlen < word.size()) maxlen = word.size();
        for(auto letter: word){
            if(indegree[letter - 'a'] < 0){
                indegree[letter - 'a'] = 0;
                appearing_letters++;
            }
        }
       }
        //looping thru ith letter of jth and j+1th words i.e jth pair of word in the seq
       for(int i {}; i < maxlen; ++i){
            for(int j {}; j < n-1; ++j){
                auto& word1 = words[j];
                auto& word2 = words[j+1];
                if(visited[j]) continue;
                if(i >= word1.size()){
                    visited[j] = true;
                    continue;
                }
                //it would mean j+1th word is the prefix of jth word
                if(i >= word2.size()) return "";

                char letter1 = word1[i];
                char letter2 = word2[i];
                
                if(letter1 != letter2){
                    indegree[letter2 - 'a']++;
                    //making letter1 directed to letter2
                    adj_list[letter1 - 'a'].push_back(letter2 - 'a');
                    //mark pair visited
                    visited[j] = true;
                }
            }
       }
       /*
       * Loop thru indegree and look for the following cases:
       * */

       queue<int> q {};
       int visited_count {};
       for(int i{}; i < indegree.size(); ++i){
            if(indegree[i] == 0){
                q.push(i);
            }
       }
       if(q.empty()) return "";
       string finalAns {};
       int processed {};

       while(!q.empty()){
            int letter = q.front();
            finalAns.push_back(letter + 'a');
            q.pop();
            for(auto a: adj_list[letter]){
                indegree[a]--;
                if(indegree[a] == 0)
                    q.push(a);
            }
            ++processed;
       }
       if(processed != appearing_letters) return "";
       return finalAns;

    }
};
