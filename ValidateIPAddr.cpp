/*
Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.

IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;

Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.

IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).

However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.

Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.

 

Example 1:

Input: IP = "172.16.254.1"
Output: "IPv4"
Explanation: This is a valid IPv4 address, return "IPv4".
Example 2:

Input: IP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
Output: "IPv6"
Explanation: This is a valid IPv6 address, return "IPv6".
Example 3:

Input: IP = "256.256.256.256"
Output: "Neither"
Explanation: This is neither a IPv4 address nor a IPv6 address.
 

Constraints:

IP consists only of English letters, digits and the characters "." and ":".
*/

class Solution {
public:
    string validIPAddress(string IP) {
        if(isIPv4(IP))
            return "IPv4";
        if(isIPv6(IP))
            return "IPv6";
        return "Neither";
    }
private:
    bool isIPv4(string IP){
        string dec = "";
        int ct = 0;
        int ct_dot = 0;
        for (int i=0;i<IP.length();++i) {
            if(IP[i]!='.'){
                int dig = IP[i] - '0';
                if(dig<0 || dig>=10) 
                    return false;
                dec+=IP[i];
            }else{
                if (dec=="")
                    return false;
                int dig = stoi(dec);
                if(ct>4 || dig <0 || dig>255)
                    return false;
  
                if(dec[0]=='0' && dec.length()>1)
                    return false;
                ct = 0;
                dec = "";
                ct_dot++;
            }
            ct++;
            if(ct>4)
                return false;
        }
        
        if (ct_dot!=3)
            return false;
        
       if (dec=="")
            return false;
        
        int dig = stoi(dec);
        
        if (ct>4 || dig <0 || dig>255)
            return false;
        
        if(dec[0]=='0' && dec.length()>1)
            return false;
        
        return true;
    }
    bool isIPv6(string IP){
        int ct = 0;
        int ct_dot = 0;
        string dec = "";
        for (int i=0;i<IP.length();++i) {
            if(IP[i]!=':'){
                int dig = IP[i] - '0';
                //cout<<dig;
                if(dig<0) 
                    return false;
                if(dig>=10 && dig< 'A'-'0')
                    return false;
                if(dig > 'F'-'0' && dig< 'a'-'0')
                    return false;
                if(dig > 'f'-'0')
                    return false;
                dec+=IP[i];
            }else{
                if(ct>5 || dec=="")
                    return false;
                ct = 0;
                dec = "";
                ct_dot++;
            }
            ct++;
            if(ct>5)
                return false;
        }
        if (ct>5 || ct_dot!=7)
            return false;
        return true;
    }
};
