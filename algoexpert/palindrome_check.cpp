using namespace std;

// a b c c b a
// a b c b a

bool isPalindrome(string str) {
  // Write your code here.
	int index_front = 0;
	int index_end = str.size()-1;
	
	while(index_front < index_end){
		if(str[index_front] != str[index_end]){
			return false;
		}
		else{
			index_front++;
			index_end--;
		}
	}
	
	return true;
}
