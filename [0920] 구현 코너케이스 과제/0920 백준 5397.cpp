#include <iostream>
#include <list>

using namespace std;

/* 고려해야 하는 코너케이스
   1. 문자열의 끝에 커서가 놓일 때
   2. 문자열의 앞에 커서가 놓일 때
*/

string findPassword(string s){
    string ans="";
    list<char> list_s; //각 문자를 저장할 list
    list_s.clear(); //list 초기화
    list<char>::iterator iter=list_s.begin(); //list의 각 요소를 탐색할 iterator
    
    for(int i=0;i<s.length();i++){
        if(s[i]=='<'){
            if(iter!=list_s.begin()){ //맨 앞이 아니면 이동 가능
                iter--;
            }
            continue;
        }
        if(s[i]=='>'){
            if(iter!= list_s.end()){ //맨 뒤가 아니면 이동 가능
                iter++;
            }
            continue;
        }
        if(s[i]=='-'){
            if(iter!=list_s.begin()){ //맨 앞이 아니면 문자 제거
                iter = list_s.erase(--iter);
            }
            continue;
        }
        if(isalpha(s[i])|| isdigit(s[i])){ //만약 알파벳 또는 숫자라면 붙여넣기
            list_s.insert(iter, s[i]); //list의 iter 위치에 입력하기
            continue;
        }
    }
    //정답이 되는 string에 붙여넣기
    for (iter = list_s.begin(); iter!=list_s.end(); iter++){
        ans += *iter;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    //입력과 함수 호출
    while(n--){
        string s;
        cin >> s;
        cout << findPassword(s) << '\n';
    }
 
    return 0;
}