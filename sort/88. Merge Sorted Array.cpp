/**
 * 从后往前比较，如果遇到nums2小于nums1的就把nums1放到最后去
 **/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) { 
        int temp = nums1.size() - 1;
        int i = n-1;
        int j = m-1;
        while(i>=0){
           while(j>=0 && nums1[j]>nums2[i]){
               swap(nums1[j--],nums1[temp--]);        
           }
               swap(nums1[temp--],nums2[i--]);
           }
        }
};