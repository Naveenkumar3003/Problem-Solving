class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        q.push({beginWord,1});
        while(!q.empty()){
            string top=q.front().first;
            int level=q.front().second;
            q.pop();
            if(top==endWord) return level;
            for(int i=0;i<top.length();i++){
                for(char c='a';c<='z';c++){
                    string word=top;
                    word[i]=c;
                    if(st.find(word)!=st.end()){
                        q.push({word,level+1});
                        st.erase(word);
                    }
                }
            }
        }
        return 0;
    }
};
