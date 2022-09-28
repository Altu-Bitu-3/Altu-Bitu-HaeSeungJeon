#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 8

using namespace std;

//재귀함수 사용 시, 함수를 계속 호출할 때 매개변수도 생성되므로 전역변수로 선언하는 것이 더 효율적
int n, m;
int input_data[SIZE], num[SIZE]; //초기값 저장, 결과값 저장
bool check[SIZE]; //중복확인

void backtracking(int cnt){ //cnt: 수열의 인덱스
    if(cnt==m){ //m개의 수열 만든 경우(기저 조건)
        for(int i=0;i<m;i++){
            cout << num[i] << ' ';  //출력
        }
        cout << '\n';
        return;
    }
    /*직전에 골랐던 수를 저장하는 수 prev_num
      참고 출처: https://m.blog.naver.com/js568/221857286945
      참고 이유: 다른 로직은 백트레킹 강의를 통해 완성할 수 있었으나,
      중복 방지를 어떻게 하는지 모르겠어서 참고했습니다.
      자동 중복 방지를 위해 set이나 map을 사용해보려 했는데 어떻게 코드를 짜야 할 지 모르겠습니다...
     */
    int prev_num =0;
    for(int i=0;i<n;i++){
        if(!check[i] && input_data[i]!=prev_num ){
            num[cnt]=input_data[i]; //사용
            prev_num =num[cnt]; //사용한 숫자 저장
            check[i] = true;
            backtracking(cnt+1);
            check[i] = false;
        }
    }
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
		cin >> input_data[i];
		
	sort(input_data, input_data + n); //오름차순 정렬
	fill_n(check, SIZE, false); //false로 일단 초기화
    
    backtracking(0);
    return 0;
    
}