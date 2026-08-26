#include <string>
#include <algorithm>

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string ans = "";
        int min_len = n + 1;
        
        int count1 = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            if (s[right] == '1') {
                count1++;
            }

            // Shrink the window while maintaining exactly k '1's 
            // and trimming leading zeros
            while (count1 == k) {
                // Remove leading zeros from the left side of the window
                while (s[left] == '0') {
                    left++;
                }

                int current_len = right - left + 1;
                string current_sub = s.substr(left, current_len);

                if (current_len < min_len) {
                    min_len = current_len;
                    ans = current_sub;
                } else if (current_len == min_len) {
                    ans = min(ans, current_sub);
                }

                // Move left past the first '1' to search for the next valid substring
                count1--;
                left++;
            }
        }

        return ans;
    }
};