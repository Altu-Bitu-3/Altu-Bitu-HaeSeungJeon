#include <iostream>
#include <stack>
#include <map>

using namespace std;

//연산자들 간의 우선순위를 반환
int prec(char op){
    switch(op){
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
    return -1;
}

/*  원칙
    1. ()괄호 안의 연산은 우선 독립적인 연산이라고 생각하고 계산한다.
    2. 같은 괄호 안이거나 같이 괄호 밖인 연산자들은 연산자의 우선순위대로 처리한다.
    2-1. 연산자의 우선순위 : *, / > +, -
    3. 괄호 안과 밖에 각각 있는 연산자는 우선 괄호 안의 연산이 다 처리되면 진행한다.
*/

string postfix(string &s){
    string ans=""; //답이 되는 최종 후위 표기식
    stack<char> st; //연산자를 넣을 스텍
    
    for(int i=0;i<s.length();i++){
        switch(s[i]){
            case '*': case '+': case '/': case '-':
                //스텍에 있는 연산자의 우선순위가 더 크거나 같으면 출력
                while(!st.empty() && (prec(s[i]) <= prec(st.top()))){
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
                break;
            //왼쪽 괄호는 괄호 스텍에 넣기
            case '(':
                st.push(s[i]);
                break;
            //오른쪽 괄호가 나타나면
            case ')':
                //왼쪽 괄호 나타날 때까지 출력
                while(st.top() != '('){
                    ans += st.top();
                    st.pop();
                }
                st.pop(); //마지막으로 '('괄호를 스텍에서 제거
                break;
            //피연산자라면 문자열에 붙이기
            default:
                ans+=s[i];
                break;
        }
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main() {
    string s; //입력되는 문자열
    
    getline(cin, s);
    cout << postfix(s);
 
    return 0;
}