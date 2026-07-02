class Solution {
public:
// MAX Water with o(n) time  complexity//
    int maxArea(vector<int>& height) {
        int maxwater=0;
        int lp=0 ,rp=height.size()-1;
    while(lp < rp){
       int w= rp-lp;
       int ht=min(height[lp],height[rp]);
       int currwater = ht*w;
       maxwater = max(maxwater,currwater);

       height[lp] < height[rp] ? lp++ :rp--;
    }
    return maxwater;
    }
    
};