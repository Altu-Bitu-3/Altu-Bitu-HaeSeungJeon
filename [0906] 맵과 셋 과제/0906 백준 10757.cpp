#include <iostream>

using namespace std;

string add(int &A_size, int &B_size, string &A, string &B){
    string ans;
    int round_up = 0; //계산하는 과정에서 올림수
    
    while(A_size > 0 || B_size > 0){ 
        int sum = 0;
        if(A_size > 0){ //A 문자열에 숫자가 남아있으면 더하기
            sum += A[--A_size] - '0';
        }
        if(B_size > 0) { //B 문자열에 숫자가 남아있으면 더하기
            sum += B[--B_size] - '0';
        }
        sum += round_up;    //아래 자릿수 계산에서 올림수가 있었다면 더하기
        //이번 계산에서의 올림수 저장해주기(10 미만이면 올림수는 0, 10 이상이면 올림수 생김)
        round_up = sum/10; 
        sum = sum % 10;
        ans += sum + '0';   //ans 문자열 뒤에 붙이기
    }
    if(round_up >0){ //가장 높은 자릿수 계산까지 했는데 올림수가 남아있다면
        ans += round_up + '0'; //ans에 반영
    }
    return ans;
}

int main() {
    string A, B; //숫자가 크기 때문에 문자열로 저장
    string ans; //답을 저장할 문자열
    int A_size, B_size; //A 문자열과 B 문자열의 길이
    
    cin >> A >> B;
    A_size = A.length();
    B_size = B.length();
    
    ans = add(A_size, B_size, A, B);

    for(int i=ans.length()-1;i>=0;i--) { //역순으로 출력
        cout << ans[i];
    }
}