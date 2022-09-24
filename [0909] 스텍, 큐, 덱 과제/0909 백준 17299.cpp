#include <iostream>
#include <stack>
#include <map>

using namespace std;

/*  오른쪽에서 왼쪽으로 s[i] 검사:
    1. 우선순위가 스텍 top의 우선순위보다 작으면 스텍에 넣는다.
    2. 우선순위가 스텍 top의 우선순위보다 크거나 같으면 스텍 top을 pop한다.
       (우선순위가 더 큰 top이 나타날 때까지)
    3. 스텍이 empty 상태면 push한다.
*/

void ngf(int n, int frequency[], int num[], int ans[]){
    stack<int> st;
    
    for (int i = n - 1; i >= 0; i--) {
		while (!st.empty()) {
		    //우선순위가 스텍 top의 우선순위보다 크거나 같으면 스텍 top을 pop
			if (frequency[num[i]] >= frequency[st.top()]){
			    st.pop();
			}
			else break;
		}
		ans[i] = -1; //오등큰수가 없으면 -1로 설정
		//우선순위가 스텍 top의 우선순위보다 작으면 스텍에 push
		if (!st.empty()){
		    ans[i] = st.top();
		}
		st.push(num[i]); //스텍이 empty 상태면 push
	}
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    
    cin >> n;
    
    const int MAX = 1e6+1;
    
    int frequency[MAX], num[MAX], ans[MAX]; //인덱스가 숫자 a가 되고, 요소가 F(a) 즉 우선순위가 되는 배열 frequency

    //F 값, 숫자 저장
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        num[i] = a; frequency[num[i]]++; 
    }
    
    ngf(n, frequency, num, ans);
    
    for(int i=0;i<n;i++){
        cout << ans[i] << ' ';
    }
 
    return 0;
}