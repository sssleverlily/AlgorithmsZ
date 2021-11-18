class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        if(size <=1) return true;
        int road = 0;
        for(int i =0;i<size;i++){
            if(i <= road){//i>road证明达不到最远了
                road = max(road, i + nums[i]);//每次就走最大
                if(road >= size-1){
                return true;
                }
            }
        }
        return false;
    }
};