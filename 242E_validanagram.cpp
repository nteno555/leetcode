class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hashS, hashT;

        if (s.size() != t.size()) return false;

        for (char c: s) {
            if (hashS.find(c) != hashS.end()) hashS[c]++;
            else hashS[c] = 1;
        }

        for (char c: t) {
            if (hashT.find(c) != hashT.end()) hashT[c]++;
            else hashT[c] = 1;
        }

        for (char c: s) {
            if (hashT.find(c) == hashT.end()) return false;
            if (hashT[c] != hashS[c]) return false;
        }

        return true;
    }
};