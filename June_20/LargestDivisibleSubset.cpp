/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        if(nums.size()==0)
            return {};
            
        sort(nums.begin(),nums.end());
        vector<vector<int>> sets;
        set<vector<int>> sets_his;
       
        for(int i=0;i<nums.size();++i){
            if(sets.size()==0){
                sets.push_back({nums[i]});
                sets_his.insert(sets[0]);
            }else{
                bool js = false;
                for(int j=0;j<sets.size();++j){
                    int tmp = sets[j][sets[j].size()-1];
                    if(nums[i]%tmp==0){
                        sets_his.insert(sets[j]);
                        sets[j].push_back(nums[i]);
                        js = true;
                    }
                }
                if(!js){
                    vector<int> cp;
                    int sz = 0;
                    for(const auto& x:sets_his){
                        int tmp = x[x.size()-1];
                        
                        if(nums[i]%tmp==0 && x.size()>sz){
                            sz = x.size();
                            cp = x;
                            //std::move(x.begin(),x.end(),cp.begin());
                        }
                    }
                    cp.push_back(nums[i]);
                    sets.push_back(cp);
                }
            }
        }
        
        int idx=0;
        int sz=0;
        for(int i=0;i<sets.size();++i){
            if(sets[i].size()>sz){
                sz=sets[i].size();
                idx=i;
            }
        }
        return sets[idx];
    }
};
