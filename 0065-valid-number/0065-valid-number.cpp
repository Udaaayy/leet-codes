class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false;
        bool seenDot = false;
        bool seenExponent = false;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (isdigit(ch)) {
                seenDigit = true;
            } 
            else if (ch == '+' || ch == '-') {
                // Sign is valid only at the start or directly after 'e' / 'E'
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } 
            else if (ch == '.') {
                // Dot is invalid if we already saw a dot or an exponent
                if (seenDot || seenExponent) {
                    return false;
                }
                seenDot = true;
            } 
            else if (ch == 'e' || ch == 'E') {
                // Exponent is invalid if we already saw an exponent or haven't seen a digit yet
                if (seenExponent || !seenDigit) {
                    return false;
                }
                seenExponent = true;
                seenDigit = false; // Must be followed by digits
            } 
            else {
                // Invalid character
                return false;
            }
        }

        return seenDigit;
    }
};