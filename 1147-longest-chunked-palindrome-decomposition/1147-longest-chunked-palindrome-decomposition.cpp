class Solution {
public:
    int longestDecomposition(string text) {
       int n = text.length();
        int count = 0;
        
        // Two-pointer/indices tracking the left and right chunks
        int left_start = 0;
        int right_end = n - 1;
        
        std::string left_chunk = "";
        std::string right_chunk = "";
        
        while (left_start <= right_end) {
            // Append characters from the outside in
            left_chunk += text[left_start];
            right_chunk = text[right_end] + right_chunk;
            
            // Move pointers inward
            left_start++;
            right_end--;
            
            // If the current left chunk matches the current right chunk
            if (left_chunk == right_chunk) {
                // If they met or crossed at the exact same middle character, 
                // it counts as 1 chunk. Otherwise, we found a pair (left + right).
                if (left_start - 1 == right_end + 1) {
                    count += 1;
                } else {
                    count += 2;
                }
                // Reset chunks to find the next inner matching layers
                left_chunk = "";
                right_chunk = "";
            }
        }
        
        // If there are remaining leftover characters that didn't form a matching pair,
        // they form a single central unmatched chunk.
        if (!left_chunk.empty()) {
            count += 1;
        }
        
        return count; 
    }
};