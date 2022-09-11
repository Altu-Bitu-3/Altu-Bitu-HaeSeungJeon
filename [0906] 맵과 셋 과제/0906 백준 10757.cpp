#include <iostream>

using namespace std;

int main() {
    string A, B; //숫자가 크기 때문에 문자열로 저장
    string ans; //답을 저장할 문자열
    int A_size, B_size; //A 문자열과 B 문자열의 길이
    int ans_size=0; //답이 되는 문자열의 길이
    int round_up = 0; //계산하는 과정에서 올림수
    
    cin >> A >> B;
    A_size = A.length();
    B_size = B.length();
    
    //두 문자열 중 하나라도 남아있으면 계산을 진행
    while(A_size > 0 || B_size > 0){ 
        int sum = 0;
        if(A_size > 0){ //A 문자열에 숫자가 남아있으면 더하기
            sum += A[--A_size] - '0';
        }
        if(B_size > 0) { //B 문자열에 숫자가 남아있으면 더하기
            sum += B[--B_size] - '0';
        }
        sum += round_up;    //아래 자릿수 계산에서 올림수가 있었다면 더하기
        if(sum >= 10){      //이번 계산에서 올림수가 있는지 확인
            round_up = sum/10; 
            sum = sum % 10;
        }
        else round_up=0;    //올림수가 없다면 0으로 다시 초기화
        ans += sum + '0';   //ans 문자열 뒤에 붙이기
        ans_size++;
    }
    if(round_up >0){ //가장 높은 자릿수 계산까지 했는데 올림수가 남아있다면
        ans += round_up + '0'; //ans에 반영
    }
    
    for(int i=ans.length()-1;i>=0;i--) { //역순으로 출력
        cout << ans[i];
    }
}