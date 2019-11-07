using namespace std;

string caesarCypherEncryptor(string str, int key) {
  // Write your code here.
	vector<char> converted;
	
	for(int i=0; i<str.size(); i++){
		int ascii_int_val = str[i];
		ascii_int_val += (key%26);
		if(ascii_int_val > 122){
			ascii_int_val -= 26;
		}
		
		converted.push_back((char)ascii_int_val);
	}
	
	return string(converted.begin(), converted.end());
}
