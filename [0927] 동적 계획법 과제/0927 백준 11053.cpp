#include <iostream>
#include <algorithm>

using namespace std;

/*알튜비튜 <동적 계획법> 강의 설명을 참고하였습니다.*/

int longestCheck(int n, int dp[], int sequence[]){
    int result_max=dp[0];
    for(int i=1;i<n;i++){ //각 인덱스를 모두 탐색한다. (맨 앞 인덱스 제외)
        int dp_max=0;
        for (int j=0; j<=i-1; j++){ //해당 인덱스의 앞 부분을 검사한다.
            if(sequence[j]>= sequence[i]){ //만약 더 앞의 것이 더 크다면 건너뛰기
                continue;
            }
            dp_max=max(dp[j], dp_max); //만약 앞의 것이 더 작다면 그 중 max가 되는 dp 찾기
        }
        dp[i] = dp_max+1; //앞의 수열과 이어붙이기
        result_max=max(dp[i], result_max); //모든 수열 중 가장 긴 것 찾기
    }
    return result_max;
}

int main() {
    int n;
    cin >> n;
    int dp[n]; //최댓값을 저장할 배열
    int sequence[n]; //숫자 자체를 저장할 배열
    fill_n(dp, n, 1); //우선 자기 자신이 최댓값이 되므로 1로 초기화
   
    for(int i=0;i<n;i++){
        cin >> sequence[i]; //숫자 저장
    }
    cout << longestCheck(n, dp, sequence);
}