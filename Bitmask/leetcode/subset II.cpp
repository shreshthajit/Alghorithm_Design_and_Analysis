# https://leetcode.com/problems/subsets-ii/


class Solution {
public:
    vector<vector<int>>          subsetsWithDup(vector<int>& nums) {
        set<vector<int>>ans;
        int size=nums.size();
        int subsetNum=1<<size;
        for(int mask=0;mask<subsetNum;mask++){
             vector<int>subset;
            for(int i=0;i<size;i++){
                if(mask&(1<<i)){
                    subset.push_back(nums[i]);
                }
            }
            sort(subset.begin(),subset.end());
            ans.insert(subset);
        }
        vector<vector<int>>v;
        for(auto it:ans){
            vector<int>val;
            for(auto i:it){
                val.push_back(i);
            }
            
            v.push_back(val);
        }
        return v;
        
    }
};
