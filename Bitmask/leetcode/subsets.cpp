class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>>ans;
        int size=nums.size();
        int subsetNum=1<<size;
        for(int mask=0;mask<subsetNum;mask++){
             vector<int>subset;
            for(int i=0;i<size;i++){
                if(mask&(1<<i)){
                    subset.push_back(nums[i]);
                }
            }
            ans.push_back(subset);
        }
        return ans;
    }
};
