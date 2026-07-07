class Solution {
public:
    unordered_map<string, int> level;
    vector<vector<string>> ans;
    vector<string> path;

    void dfs(string word, string &beginWord) {
        path.push_back(word);

        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            path.pop_back();
            return;
        }

        int currLevel = level[word];

        for (int i = 0; i < word.size(); i++) {
            char original = word[i];

            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;

                if (level.count(word) && level[word] == currLevel - 1) {
                    dfs(word, beginWord);
                }
            }

            word[i] = original;
        }

        path.pop_back();
    }

    vector<vector<string>> findLadders(string beginWord,
                                       string endWord,
                                       vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        if (!st.count(endWord))
            return {};

        queue<string> q;
        q.push(beginWord);

        level[beginWord] = 0;

        while (!q.empty()) {

            string word = q.front();
            q.pop();

            int currLevel = level[word];

            for (int i = 0; i < word.size(); i++) {

                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {

                    word[i] = ch;

                    if (st.count(word) && !level.count(word)) {

                        level[word] = currLevel + 1;
                        q.push(word);
                    }
                }

                word[i] = original;
            }
        }

        if (!level.count(endWord))
            return {};

        dfs(endWord, beginWord);

        return ans;
    }
};