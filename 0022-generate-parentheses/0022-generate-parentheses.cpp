class Solution {
public:
     
        void backtrack(int n, int openCount, int closeCount, string current, vector<string>& result) {
        // Base case: if the current string length reaches 2 * n, it's a valid combination
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // We can add an open parenthesis if we haven't used all 'n' open brackets
        if (openCount < n) {
            backtrack(n, openCount + 1, closeCount, current + "(", result);
        }

        // We can add a close parenthesis only if it won't exceed the number of open brackets
        if (closeCount < openCount) {
            backtrack(n, openCount, closeCount + 1, current + ")", result);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(n, 0, 0, "", result);
        return result;
    }
};