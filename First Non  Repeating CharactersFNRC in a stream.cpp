/*
	First Non - Repeating Characters(FNRC) in a stream
*/

void FNRC(string stream) {
	deque<char> DQ;
	map<char, int> Freq;
	for(int i = 0; i < stream.size(); i++) {
		DQ.push_back(stream[i]);              // Insert the character comming sequentially from the stream.
		Freq[stream[i]]++;                    // Count it's freq as we need only the freq of DQ.front()
		while(!DQ.empty()) {
			if(Freq[DQ.front()] > 1) {          // If in any point of time I found freq[DQ.front()] more than 1, that means 
				DQ.pop_front();               // it is repeated. And the DQ.front() should no more the ans. We need to Pop.
			} else {
				cout << DQ.front() << ' ';    // Here we find no element is repeated, hence print the DQ.front() and break
				break;
			}
		}
		if(DQ.empty()) {
			cout << -1 << ' ';               // When the DQ is empty, i.e no more chars found to be uniquely came. Insert
		}                                    // whatever you want to just visualize that 'Yes we donot have more ans'. Here 
	}                                        // I have inserted '-1'.
}