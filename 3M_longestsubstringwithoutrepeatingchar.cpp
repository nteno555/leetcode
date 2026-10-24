class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 2) return s.size();
        vector<bool> arr(1000, false);

        int i=0, j=1, ans=1;
        arr[s[i] - ' '] = true;

        while (i<=j && j<s.size()) {
            // cout << "SUBSTR: " << s.substr(i, j) << endl;
            // cout << "CHAR SUBSTRACTION: " << s[j] << "  " << s[j] - ' ' << endl;

            if (arr[s[j] - ' ']) {
                // cout << "DUPLICATE FOUND!" << endl;
                arr[s[i] - ' '] = false;
                i++;
            }
            else {
                arr[s[j] - ' '] = true;
                // cout << "CONTINUE ADDING" << endl;
                j++;
                ans = max(ans, j-i);
            }
        }

        return ans;
    }
};