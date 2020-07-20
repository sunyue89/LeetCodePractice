/*
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        string in,out;
        k = k-1;
        vector<int> idx;
        for(int i=1;i<=n;++i){
            in.append(to_string(i));
        }
        for(int i=1;i<=n;++i){
            idx.push_back(k%i);
            k=k/i;
        }
        for(int i=idx.size()-1;i>=0;--i){
            //cout<<i<<" "<<idx[i]<<" "<<in[idx[i]]<<endl;
            out+=in[idx[i]];
            in.erase(in.begin()+idx[i]);
        }
        return out;
    }

    
    #if 0
    void reorder(int l, int n, string& p){
        string t = p.substr(n-1,1);
        p.erase(n-1,1);
        p.insert(l-1,t);
    }
    bool Perm(int l, int n, int k, string& p, string& o, int& ct){
        if(l==n){
            ct++;
            //cout<<p<<endl;
            if(ct==k){
                o = p;
                return true;
            }
        }else{
            for(int i=l;i<=n;++i){
                reorder(l,i,p);
                if(Perm(l+1,n,k,p,o,ct))
                    return true;
                reorder(i,l,p);
            }
        }
        return false;
    }
    string getPermutation(int n, int k) {
        string in,out;
        int ct=0;
        for(int i=1;i<=n;++i){
            in.append(to_string(i));
        }
        //cout<<in<<endl;
        Perm(1,n,k,in,out,ct);
        return out;
    }
    #endif
   
};
