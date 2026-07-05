class Solution {
public:
    string intToRoman(int num) {
     // Map of integer values to Roman symbols in descending order
        const vector<pair<int, string>> romanMapping = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
            {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
            {1, "I"}
        };
        
        string result = "";
        
        // Loop through the mapping
        for (const auto& [value, symbol] : romanMapping) {
            // Keep appending the symbol while num is greater than or equal to the value
            while (num >= value) {
                result += symbol;
                num -= value;
            }
            // Early exit if the number becomes 0
            if (num == 0) break;
        }
        
        return result;   
    }
};