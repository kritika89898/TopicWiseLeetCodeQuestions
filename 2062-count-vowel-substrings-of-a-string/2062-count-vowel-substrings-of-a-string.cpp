class Solution {
public:
    bool isVowel(char c) {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }

    int countVowelSubstrings(string word) {
        int ans = 0;
        int n = word.size();

        for (int i = 0; i < n; i++) {
            unordered_map<char,int> mp;

            for (int j = i; j < n; j++) {

                if (!isVowel(word[j]))
                    break;

                mp[word[j]]++;

                if (mp.size() == 5)
                    ans++;
            }
        }

        return ans;
    }
};