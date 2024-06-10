class Solution {
public:
    string clearDigits(string str) {
        stack<int> s;

        for (auto it : str) {
            if (it >= 'a' && it <= 'z') {
                s.push(it);
            } else {
                if (!s.empty()) {
                    s.pop();
                }
            }
        }

        str = "";
        while (!s.empty()) {
            str.push_back(s.top());
            s.pop();
        }

        reverse(begin(str), end(str));
        return str;
    }
};