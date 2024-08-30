class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> qt;
        qt.push({beginWord,1});
        unordered_set<string> st (wordList.begin(),wordList.end());
        st.erase(beginWord);
        while(!qt.empty()){
            string word=qt.front().first;
            int steps=qt.front().second;
            qt.pop();
            if(word==endWord){
                return steps;
            }
            for(int i=0;i<word.size();i++){
                char orignal=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        qt.push({word,steps+1});
                    }
                }
                word[i]=orignal;
            }
        }
        return 0;
    }
};