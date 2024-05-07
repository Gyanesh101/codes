#include<bits/stdc++.h>
class Solution {
   int fun(int n,vector<int>&v,vector<int>&dp)
   {
       // base case
       if(n==0) return v[n];
       if(n<0) return 0;
       if(dp[n]!=-1) return dp[n];
       int take=fun(n-2,v,dp)+v[n];
       int nontake=fun(n-1,v,dp)+0;
       return dp[n]= max(take,nontake);
   }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int>v1;
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0) v1.push_back(nums[i]);
        }
        int n=v1.size();
        vector<int>v2;
        for(int i=0;i<nums.size();i++)
        {
            if(i!=nums.size()-1)
             v2.push_back(nums[i]);
        }
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
    return max(fun(n-1,v1,dp),fun(n-1,v2,dp));
    }
};