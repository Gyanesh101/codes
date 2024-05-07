class Solution {
    int fun(int ind,vector<int>&nums,vector<int>&dp)
    {
       // base case
       if(ind==0) return nums[ind];
       if(ind<0)  return 0;
       if(dp[ind]!=-1) return dp[ind];
       int take=fun(ind-2,nums,dp)+nums[ind];
       int nontake=fun(ind-1,nums,dp)+0;
       return dp[ind]= max(take,nontake); 
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            int take=nums[i]; if(i>1) take+=dp[i-2];
       int nontake=dp[i-1]+0;
        dp[i]= max(take,nontake); 
        }
      return dp[n-1];
    }
};