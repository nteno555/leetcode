class Solution {
public:
    bool isPalindrome(string s) {
        int i=0, j=s.size()-1;

        while (i<j) {
            while (!isalnum(s[i]) && i<j) {
                i++;
            }
            while (!isalnum(s[j]) && j>i) {
                j--;
            }

            if (tolower(s[i]) != tolower(s[j])) return false;
            i++;
            j--;
        }

        return true;
    }
};

// class Solution {
// public:
//     bool isPalindrome(string s) {
//         string filteredS;
//         for (char c: s) {
//             if (!c.isalnum()) continue;
//             filteredS += c.lower();
//         }
//
//         s = filteredS;
//
//         stack<char> backwards;
//         stack<char> forwards;
//
//         for (int i=0; i<s.size()/2 + 1; i++) {
//             forwards.push(s[i]);
//             backwards.push(s[s.size()-1-i]);
//         }
//
//         while (!backwards.empty()) {
//             if (forwards.top() != backwards.top()) return false;
//
//             forwards.pop();
//             backwards.pop();
//         }
//
//         return true;
//     }
// };