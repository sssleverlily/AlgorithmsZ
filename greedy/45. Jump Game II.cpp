class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        int curroad = 0;
        int nextroad = 0;
        int times = 0;
        for(int i = 0;i<size;i++){  
            //当前终点的下标还不足以达到重点时，就启用next的下标 
            nextroad = max(i+nums[i],nextroad);
            if(i == curroad){
                if(curroad != size-1){
                    times++;
                    curroad = nextroad;
                    if(nextroad >=size-1) break;
                }else break;
            }      
        }
        return times;
    }
};