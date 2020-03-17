// Reverse Words in a string
void reverseWords(string &A) {
    string out;
    vector<string> ans;
    stringstream ss;
    ss << A;
    while(ss >> out) {
        ans.push_back(out);
    }
    out.clear();
    for(int i = ans.size() - 1; i >= 0; i--) {
        for(char ch : ans[i]) {
            out.push_back(ch);
        }
        out.push_back(' ');
    }
    if(out[out.size() - 1] == ' ') {
        out.pop_back();
    }
    A = out;
}