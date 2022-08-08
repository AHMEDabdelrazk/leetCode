class Solution {
public:
    
    // So Important And Informative Problem
    
   bool wordPattern(string pattern, string s) 
 {
	 map<char, string> m;
	 int index = 0;
	 string myString;
	 for (int i = 0; i < pattern.size(); i++)
	 {
		 myString = "";
		  while((index < s.size()) && (s[index] != ' '))
			 {
				 myString.push_back(s[index]);
				
				 index++;
			 }
			 index++;
		 if (m.find(pattern[i]) == m.end()) 
		 {
			 for (auto it = m.begin(); it != m.end(); it++)
				 if (it->second == myString) return false;
			 m[pattern[i]] = myString;
		 }
		 else
		 {
			 if (m[pattern[i]] != myString) return false;
		 }
		 if (index > (s.size()+1)) return false;
	 }
	 if (index < s.size()) return false;
	 return true;
 }
			 
			 
		
};