/*
Given a string S, consider all duplicated substrings: (contiguous) substrings of S that occur 2 or more times.  (The occurrences may overlap.)

Return any duplicated substring that has the longest possible length.  (If S does not have a duplicated substring, the answer is "".)

 

Example 1:

Input: "banana"
Output: "ana"
Example 2:

Input: "abcd"
Output: ""
 

Note:

2 <= S.length <= 10^5
S consists of lowercase English letters.
*/

class Solution {
public:
    string longestDupSubstring(string S) {
        int lo = 0;
        int hi = S.length()-1;
        int k = 0;
        size_t idx=0;
        
        while(lo<=hi){
            int mid=lo + (hi-lo)/2;
            
            if(k_com_str(S,mid,idx)){
                lo = mid+1;
                k = mid;
            }else{
                hi = mid-1;
            }
        }
        return S.substr(idx,k);
    }
    
private:
    
  size_t P1 = 1000000007;
	size_t mul = 5;
	long long h_roll = 0;
	unsigned long long h_mul = 1;
	unordered_map <long long, size_t> s1_map;
    
	unsigned long long mulmod(int a, int b, int c){
		long long x =1, y = a%c;
		while(b>0){
			if(b%2==1){
			       	x = (x*y)%c;
			}
			y=(y*y)%c;
			b /= 2;
		}
		return x;
	}
	
    bool k_com_str(const string& s, const size_t& k, size_t& idx){
        // Function Mapping 
        h_mul = mulmod(mul,k,P1);

        //initiliaze the hash
        h_roll = 0;

        for (size_t i = 0; i < s.size(); ++i){
            h_roll = (( mul*h_roll + s[i] )%P1 + P1)%P1;

            //rolling hashing
            if (i >= k){
                h_roll = (h_roll - (h_mul*s[i-k])%P1 + P1)%P1;
            }
            if (i+1 >= k){
                if(s1_map.find(h_roll) == s1_map.end()){
                    s1_map[h_roll] = i+1-k;
                }else{
                    int tmp = s1_map[h_roll];
                    int j = 0;
                    
                    for(j=0; j<k; ++j){
                        if(s[tmp+j]!=s[i+1-k+j])
                            break;
                    }
                    
                    if (j==k){
                        idx = tmp;
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
