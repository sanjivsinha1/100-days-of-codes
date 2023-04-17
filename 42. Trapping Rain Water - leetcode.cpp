class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n<2) return 0;
        vector<int> left(n);
        vector<int> right(n);

        //creating left vector which store all the leftmost greatest element 
        left[0]=height[0];
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],height[i]);
        }
        //creating right vector which store all the rightmost greatest element
        right[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],height[i]);
        }
        //finding the water stored between two blocks
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(min(right[i],left[i])-height[i]);
        }

        return ans;
    }
};
