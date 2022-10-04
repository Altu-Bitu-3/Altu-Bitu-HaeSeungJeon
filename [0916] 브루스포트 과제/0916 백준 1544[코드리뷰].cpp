#include <iostream>
#include <set>

using namespace std;

//단어의 길이가 최대 50이므로, 한 단어의 순서를 바꿔주는 계산 수는 50
//단어의 개수 N은 최대 50이므로, 최대 계산 수는 250 -> 브루스포트 가능!

//단어의 글자 순서를 바꾸면서 확인하는 함수
int findCircle(set<string>& word, string s){
    int s_size = s.length(); //단어의 길이 구하기

        for(int i=0;i<s_size;i++){
            // 같은 단어가 있는 경우
		    if (word.find(s) != word.end()) {
			    return true;
	    	}
            s = s + s[0]; //단어의 순서 바꿔서 다시 시도
		    s.erase(0, 1);
        }       
        return false;
}

int main() {
    int n;
    cin >> n;
    string s;
    set<string> word; //각 단어의 대표 하나만 저장해줌
    
    for(int i=0;i<n;i++){
        cin >> s;
        if (!findCircle(word, s)) {
			word.insert(s);
		}
    }
    
    cout << word.size();
}