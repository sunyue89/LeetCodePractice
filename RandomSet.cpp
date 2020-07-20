/*Given an array of integers with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.

Note:
The array size can be very large. Solution that uses too much extra space will not pass the judge.

Example:

int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
solution.pick(3);

// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(1);
Last Submission
Last Saved Code*/


class Solution {
public:
    Solution(vector<int>& nums) {
        data = nums;
        //sort(data.begin(),data.end());
    }
    
    int pick(int target) {
        vector<int> Idx = tarIdx(target);
        /*
        for(auto x:Idx)
            cout<<x<<" ";
        cout<<endl;*/
        //srand ( time(NULL) );
        int idx = rand()%Idx.size(); //0 -> Idx.size()-1
        //cout<<idx<<endl;
        return Idx[idx];
        //return -1;
    }
private:
    vector<int> data;
    vector<int> tarIdx(int target){
        vector<int> out;
        for(int i=0;i<data.size();++i){
            if(data[i]==target)
                out.push_back(i);
        }
        return out;
    }
    
    /*
    vector<int> tarIdx(int target){
        vector<int> out;
        int lo = 0;
        int mid = 0;
        int hi = data.size()-1;
        
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(data[mid]==target){
                break;
            }
            if(data[mid]<target){
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        
        out.push_back(mid);
        lo = mid-1;
        hi = mid+1;
        while(lo>=0 && data[lo]==target){
            out.push_back(lo);
            lo--;
        }
        while(hi<=data.size()-1 && data[hi]==target){
            out.push_back(hi);
            hi++;
        }
        return out;
    }*/
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
