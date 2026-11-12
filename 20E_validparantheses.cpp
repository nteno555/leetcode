class Solution {
public:
    bool isValid(string s) {
        stack<char> q;

        for (char c: s) {
            if (c == '(' || c == '{' || c == '[') {
                q.push(c);
            } else {
                if (q.empty()) return false;
                if (c==')' && q.top() != '(') return false;
                if (c==']' && q.top() != '[') return false;
                if (c=='}' && q.top() != '{') return false;
                q.pop();
            }
        }

        return q.empty();
    }
};