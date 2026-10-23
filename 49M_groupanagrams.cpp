class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hashTable;

        for (int i=0; i<strs.size(); i++) {
            string curWord = countLetters(strs[i]);
            hashTable[curWord].push_back(strs[i]);
        }

        for (const auto& [alpha, words]: hashTable) {
            ans.push_back(words);
        }

        return ans;
    }

    string countLetters(string word) {
        int letters[26]{0};
        string ans;

        for (char c: word) {
            letters[c - 'a']++;
        }

        for (int i=0; i<26; i++) {
            ans += "#" + to_string(letters[i]);
        }

        return ans;
    }
};