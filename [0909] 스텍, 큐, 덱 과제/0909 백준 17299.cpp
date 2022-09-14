#include <iostream>
#include <stack>
#include <map>

int F[1000001], ans[1000001], num[1000001]; //인덱스가 숫자 a가 되고, 요소가 F(a) 즉 우선순위가 되는 배열 F

using namespace std;

/*  오른쪽에서 왼쪽으로 s[i] 검사:
    1. 우선순위가 스텍 top의 우선순위보다 작으면 스텍에 넣는다.
    2. 우선순위가 스텍 top의 우선순위보다 크거나 같으면 스텍 top을 pop한다.
       (우선순위가 더 큰 top이 나타날 때까지)
    3. 스텍이 empty 상태면 push한다.
*/

void ngf(int n){
    stack<int> st;
    
    for (int i = n - 1; i >= 0; i--) {
		while (!st.empty()) {
		    //우선순위가 스텍 top의 우선순위보다 크거나 같으면 스텍 top을 pop
			if (F[num[i]] >= F[num[st.top()]]){
			    st.pop();
			}
			else break;
		}
		ans[i] = -1;
		//우선순위가 스텍 top의 우선순위보다 작으면 스텍에 push
		if (!st.empty()){
		    ans[i] = num[st.top()];
		}
		st.push(i); //스텍이 empty 상태면 push
	}
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    
    cin >> n;
    
    //F 값, 숫자 저장
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        num[i] = a; F[num[i]]++; 
    }
    
    ngf(n);
    
    for(int i=0;i<n;i++){
        cout << ans[i] << ' ';
    }
 
    return 0;
}