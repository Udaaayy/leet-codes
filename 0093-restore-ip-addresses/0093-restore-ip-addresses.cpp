class Solution {
public:
    void backtrack(string &s, int index, int parts, string current, vector<string> &result) {
        // Base case: if we have 4 segments and reached the end of s, it's a valid IP
        if (parts == 4) {
            if (index == s.length()) {
                result.push_back(current);
            }
            return;
        }

        // Try extracting sub-segments of length 1, 2, and 3
        for (int len = 1; len <= 3; ++len) {
            if (index + len > s.length()) break; // Beyond string boundary

            string segment = s.substr(index, len);

            // Leading zeroes are invalid unless the segment is just "0"
            if (segment.length() > 1 && segment[0] == '0') continue;

            // Segment value must be <= 255
            int val = stoi(segment);
            if (val > 255) continue;

            // Recurse to find the next part
            backtrack(s, index + len, parts + 1, current + (parts == 0 ? "" : ".") + segment, result);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> result;

        // Quick check: An IP address must have 4 to 12 digits
        if (s.length() < 4 || s.length() > 12) {
            return result;
        }

        backtrack(s, 0, 0, "", result);
        return result;
    }
};