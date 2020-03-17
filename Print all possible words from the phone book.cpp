string phonebook[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void solve()
{
    //WRITE YOUR CODE HERE
    int n; cin >> n; 
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] -= 2;
    }
    queue<string> q;
    for(int i = 0; i < phonebook[arr[0]].size(); i++) {
        string s = "";
        s += phonebook[arr[0]][i];
        q.push(s);
    }
    int j = 1;
    while(!q.empty()) {
        if(j == n) {
            break;
        }
        int size = q.size();
        string toBeAdded = phonebook[arr[j]];
        while(size--) {
            string s = q.front();
            q.pop();
            for(int i = 0; i < toBeAdded.size(); i++) {
                q.push(s + toBeAdded[i]);
            }
        }
        j++;
    }
    while(!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
    }
    cout << endl;
}