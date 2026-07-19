class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
      if (n == 0) return 1;
        
        int totalCount = 10; // For n = 1 (numbers 0-9)
        int currentLengthUniqueChoices = 9;
        int availableDigits = 9;
        
        // Calculate for lengths from 2 up to n
        for (int i = 2; i <= n; ++i) {
            currentLengthUniqueChoices *= availableDigits;
            totalCount += currentLengthUniqueChoices;
            availableDigits--;
        }
        
        return totalCount;  
    }
};