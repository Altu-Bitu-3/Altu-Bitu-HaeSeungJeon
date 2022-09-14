#include <iostream>
#include <stack>
#include <map>

using namespace std;

int isStable(string &s){
    stack<char> st;
    map<char, char> m;
    int cnt=0; //최소 연산의 수 카운트
    m['}'] = '{';
    
    for(int i=0;i<s.length();i++){
        switch(s[i]){
            //왼쪽 괄호는 스텍에 넣기
            case '{':
                st.push(s[i]);
                break;
            //오른쪽 괄호는 짝이 맞는지 체크
            case '}':
                //오른쪽 괄호가 나타났는데, 1. 스텍이 비어있거나 2. 스텍에 있는 괄호가 왼쪽이 아니라면
                if(st.empty() || st.top() != m[s[i]]){
                    st.push(s[i]);
                    break;
                }
                st.pop(); 
                break;
        }
    }
    /*S가 안정적이라면, {S}도 안정적인 문자열이다.
      따라서 이미 안정적인 S("{}"쌍을 뜻함)을 지우고 남은 불안정한 문자열을 안정적으로 만들어주면 된다.
      불안정한 문자열 쌍은 "}{", "}}", "{{"이 있다. "}{" 은 두 개를 다 바꿔줘야 하고, 나머진 하나만 바꿔주면 된다.
    */
    
    while(!st.empty()){
        char top = st.top();
        st.pop();
        if(st.top() != top){
            cnt+=2;

        }
        else{
          cnt++;  
        }
        st.pop();
    }
    return cnt;
}

int main() {
    string s; //입력되는 문자열
    int s_num = 0; //문자열 넘버
    
    //getline(cin, <문자열 이름>): 공백 포함 입력받기
    while(getline(cin, s)){
        if(s[0] == '-'){ //끝이면 바로 종료
            break;
        }
        if(s == ""){ //빈 문자열이면 0을 출력
            cout << ++s_num << ". 0"; 
            continue;
        }
        cout << ++s_num << ". " << isStable(s) << '\n'; //문자열이 있으면 최소 연산의 수 출력
    }
    
    return 0;
}