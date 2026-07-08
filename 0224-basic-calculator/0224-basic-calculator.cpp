class Solution {
public: 
    int calculate(string s) {
        std::stack<int> st;
        int result = 0;
        long long current_number = 0;
        int sign = 1; // 1 means '+', -1 means '-'

        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];

            if (std::isdigit(ch)) {
                // Form the multi-digit number
               current_number = current_number*10 + (ch - '0');
            } 
            else if (ch == '+') {
                // Add the evaluated number to result before updating the sign
                result += sign * current_number;
                current_number = 0;
                sign = 1;
            } 
            else if (ch == '-') {
                result += sign * current_number;
                current_number = 0;
                sign = -1;
            } 
            else if (ch == '(') {
                // Push the current result and sign onto the stack
                st.push(result);
                st.push(sign);
                
                // Reset result and sign for the new sub-expression
                result = 0;
                sign = 1;
            } 
            else if (ch == ')') {
                // Add the last number inside the parenthesis to the sub-expression result
                result += sign * current_number;
                current_number = 0;

                // Pop the sign before the parenthesis and multiply it
                result *= st.top(); 
                st.pop();

                // Pop the result before the parenthesis and add it
                result += st.top(); 
                st.pop();
            }
        }

        // Add the final remaining number if any
        if (current_number != 0) {
            result += sign * current_number;
        }

        return result;
    }
};