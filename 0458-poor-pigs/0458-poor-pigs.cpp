#include <cmath>

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int states = (minutesToTest / minutesToDie) + 1;
        int pigs = 0;
        
        long long current_buckets = 1;
        while (current_buckets < buckets) {
            current_buckets *= states;
            pigs++;
        }
        
        return pigs;
    }
};