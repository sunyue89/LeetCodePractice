/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/

class Solution {
public:
    //[1 4]
    //6
    //2
    //lo = 0, hi = 1, mid = 0
    //lo = 1, hi = 1, mid = 1
    /*
    int bS(vector<int>& sq, int n){
        int lo = 0;
        int hi = sq.size()-1;
        int idx = -1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(sq[mid]==n)
                return mid;
            if(sq[mid]<n){
                lo = mid+1;
                idx = mid;
            }else{
                hi = mid-1;
            }
        }
        return idx;
    }*/
    int getChange(vector<int>& sq, int n){
        
        vector<int> minCoins(n+1);
        int NumCoins = 0;
        
        for(int i=1;i<=n;++i){
            minCoins[i] = INT_MAX;
            for(const auto& x:sq){
                if(i>=x){
                    NumCoins = minCoins[i-x]+1;
                    minCoins[i] = min(minCoins[i],NumCoins);
                }
            }
        }
        return minCoins[n];
    }
    int numSquares(int n) {
        
        vector<int> sq;
        for(int i=1;i<=n;++i){
            int tmp = i*i;
            if(tmp>n)
                break;
            sq.push_back(tmp);
        }
        return getChange(sq,n);
        
        /* greedy algo w/ BS does not work, deploy DP instead
        int ct_min = INT_MAX;
        for(auto itr=sq.end();itr>sq.begin();--itr){
            int ct = 0;
            int tg = n;
            vector<int> sq_tmp(sq.begin(),itr);
            
            for(auto& x:sq_tmp){
                cout<<x<<" ";
            }
            cout<<endl;
            
            while(tg > 0){
                int tmp = sq_tmp[bS(sq_tmp,tg)];
                cout<<tg<<" "<<tmp<<endl;
                tg-=tmp;
                ct++;
                if(ct>=ct_min)
                    break;
            }
            cout<<ct_min<<" "<<ct<<endl;
            ct_min = min(ct_min,ct);
        }
        return ct_min;*/
    }
};
