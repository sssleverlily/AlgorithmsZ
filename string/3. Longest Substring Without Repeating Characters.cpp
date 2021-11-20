class Solution {
public:
    /**
     * 滑动窗口
     * */
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if(size == 0) return 0;
        unordered_set<char> slide;
        int result = 0;
        int left = 0;
        for(int i = 0; i < size; i++){
            while (slide.find(s[i]) != slide.end()){
                slide.erase(s[left]);
                left ++;
            }
            result = max(result,i-left+1);
            slide.insert(s[i]);
    }
        return result;
        
    }
};
