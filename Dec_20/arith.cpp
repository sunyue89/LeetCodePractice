//calculate the arithmetic results given an input string composed of digits and arithmetic symbols

//for instance 3+5*6-4/2

#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>
#include <string>
#include <queue>

using namespace std;

class Sol{

public:
	
	int Eval(string s){
		int i=0;
		for(i=0; i<s.length(); ++i){
			if(s[i] == '+' || s[i] == '-')
				break;
		}
		if(i>=s.length()){
			for(i=s.length()-1;i>=0;--i){
				if(s[i] == '*' || s[i] == '/')
					break;
			}
		}
		if(i<0 || i>=s.length())
			return stoi(s);

		switch (s[i]){
			case '+':
				return Eval(s.substr(0,i)) + Eval(s.substr(i+1,s.length()));
			case '-':
				return Eval(s.substr(0,i)) - Eval(s.substr(i+1,s.length()));
			case '*':
				return Eval(s.substr(0,i)) * Eval(s.substr(i+1,s.length()));
			case '/':
				return Eval(s.substr(0,i)) / Eval(s.substr(i+1,s.length()));
			default:
				return 0;
		}

	}

};

int main(){
	Sol s;
	string in;
	cout<<"input string"<<endl;
	cin>>in;
	cout<<s.Eval(in)<<endl;
	return -1;
}
