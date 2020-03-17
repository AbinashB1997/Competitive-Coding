/*
	maximum length substring with non repeating character
*/

int lengthOfLongestSubstring(string s) {
   int m = 0;
   int start = 0;
   unordered_set<char> st;
   for(int i = 0; i < s.size(); i++) {
       if(st.find(s[i]) != st.end()) {
       //cout << "size before = " << st.size() << endl;
       while(s[start] != s[i]) {
             st.erase(s[start++]);
       }
       st.erase(s[start++]);
       //cout << "size after = " << st.size() << endl;
       }
       cout << "char : " << s[i] << endl;
       st.insert(s[i]);
       int size = st.size();
       m = std::max(m, size);
   }
   return m;
}