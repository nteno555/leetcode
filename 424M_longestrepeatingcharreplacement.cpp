class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0, j=0, len, ans=1, maxFreq=1;
        vector<int> freq(26, 0);

        while (j<s.size()) {
            char curChar = s[j];
            len = j-i + 1;
            freq[curChar-'A']++;
            maxFreq = max(freq[curChar-'A'], maxFreq);

            if (len - maxFreq > k) {
                // too many reuses exceeded, you need to move I
                while (i<j) {
                    freq[s[i]-'A']--;
                    i++;
                    if ((j-i+1) - maxFreq <= k) break;
                }
                j++;
            }
            else {
                j++;
                ans = max(ans, len);
            }
        }

        return ans;
    }
};