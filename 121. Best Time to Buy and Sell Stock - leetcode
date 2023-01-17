class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int maxi=0;
        for(int x:prices){
            mini=min(mini,x);
            maxi=max(maxi,x-mini);
        }
        return maxi;
    }
};
