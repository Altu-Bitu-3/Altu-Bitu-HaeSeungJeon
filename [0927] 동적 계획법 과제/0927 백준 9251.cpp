#include <iostream>
#include <string>
#include <algorithm>

#define MAX 1001

using namespace std;

/*참고자료: 컴퓨터알고리즘 수업 코드*/

//LCS 구하는 코드
int longestCommonSub(string s1, string s2, int s1_length, int s2_length){
    int dp[MAX][MAX] = {0}; //0으로 초기화(MAX 1001로 설정하지 않으면 99%에서 '틀렸습니다')
    
    for(int i=1; i<s2_length+1; i++){
        for(int j=1; j<s1_length+1; j++){
            if(s1[j-1]==s2[i-1]){  //만약 두 알파벳이 같으면 왼쪽 대각선의 수에서 +1 
                dp[i][j]=dp[i-1][j-1]+1;//(이유: 현재의 알파벳이 같다면, 그 전까지 가장 큰 LSD를 찾아서 더하기 1을 해야 한다.)
            }
            else{ //만약 두 알파벳이 다르면 위 또는 옆에서 가장 큰 값
                dp[i][j]=max(dp[i][j-1], dp[i-1][j]); //이유: 현재 비교하는 알파벳이 다르다면 바로 전 값 참고 불가
            }
        }
    }
    
  return dp[s2_length][s1_length];
}

int main() {
  string s1, s2;
  
  cin >> s1 >> s2;

  cout << longestCommonSub(s1, s2, s1.length(), s2.length());
  
  return 0;
}