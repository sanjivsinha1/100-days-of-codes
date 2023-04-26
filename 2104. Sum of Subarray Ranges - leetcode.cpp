class Solution {
public:
    long long subArrayRanges(vector<int>& nums) 
	{
		  long long ans =0;
          for(int i=0;i<nums.size();i++)
		  {
		       long long max = INT_MIN;
			   long long min = INT_MAX;
			   
			   for(int j=i;j<nums.size();j++)
			   {
			   	    if(nums[j] > max)
			   	    {
			   	       max = nums[j];	
			        }
			        if(nums[j] < min)
			        {
			        	min = nums[j];
					}
					ans = ans + (max - min);
			   }	
		  }    
		  return ans;
    }
};
