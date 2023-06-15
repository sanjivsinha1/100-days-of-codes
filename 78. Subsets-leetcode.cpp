class Solution {
public:
    void subelement(int n,vector<int> nums,int index,vector<int>output, vector<vector<int>>&ans){
        if(index>=n){
            ans.push_back(output);
            return;
        }
        //exclude
        subelement(n,nums,index+1,output,ans);
        //include
        output.push_back(nums[index]);
        subelement(n,nums,index+1,output,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int index=0;
        vector<vector<int>> ans;
        vector<int> output;
        int n=nums.size();
        subelement(n,nums,index,output,ans);
        return ans;
    }
};
