class Solution {
public:
    bool canJump(vector<int>& arr) {
        int n = arr.size();
        int i = n-2;
        int temp_target = 0;
        int j= n-1;
    
        while(i>=0){
            if(arr[i]>=j-i){
                temp_target = arr[i];
                j = i;
                i--;
            }
            else {
                i--;
            }
        }
        return j == 0 ;
    }
};