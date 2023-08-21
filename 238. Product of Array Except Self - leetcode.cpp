class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);

        //calculating the product of all the number before nums[i] and storing them to the nums[i] output {ans[i]} - traverse left to right
        int prefix_p = 1;
        for(int i = 0; i < n; i++){
            ans[i] *= prefix_p;
            prefix_p *= nums[i];
        }

        //calculating the product of all the number after nums[i] and storing them to the nums[i] output {ans[i]} - traverse right to left
        int suffix_p = 1;
        for(int i = n-1; i >= 0; i--){
            ans[i] *= suffix_p;
            suffix_p *= nums[i];
        }
        return ans;
    }
};
