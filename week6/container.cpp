class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater = 0 ;
        int lp = 0; 
        int n= height.size();
        int rp = n-1;
       while (lp< rp){
        
        int currentwater= min(height[lp],height[rp])*(rp - lp);
        maxwater = max(maxwater,currentwater);

        if(height[lp]>height[rp])
        rp--;

        else 
        lp++;
       }

       
        return maxwater;
    }
};