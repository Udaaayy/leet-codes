#include <string>
#include <unordered_map>

class Solution {
    std::unordered_map<std::string, bool> memo;

public:
    bool isScramble(std::string s1, std::string s2) {
        // Base Cases
        if (s1 == s2) return true;
        if (s1.length() != s2.length()) return false;
        
        // Memoization Key
        std::string key = s1 + "_" + s2;
        if (memo.count(key)) return memo[key];

        // Pruning: Check if both strings are anagrams
        int count[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return memo[key] = false;
        }

        int n = s1.length();
        for (int i = 1; i < n; i++) {
            // Case 1: Substrings are NOT swapped
            // s1 split: [0...i-1] and [i...n-1]
            // s2 split: [0...i-1] and [i...n-1]
            bool without_swap = isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                               isScramble(s1.substr(i), s2.substr(i));

            if (without_swap) return memo[key] = true;

            // Case 2: Substrings ARE swapped
            // s1 split: [0...i-1] and [i...n-1]
            // s2 split: [n-i...n-1] and [0...n-i-1]
            bool with_swap = isScramble(s1.substr(0, i), s2.substr(n - i)) &&
                             isScramble(s1.substr(i), s2.substr(0, n - i));

            if (with_swap) return memo[key] = true;
        }

        return memo[key] = false;
    }
};