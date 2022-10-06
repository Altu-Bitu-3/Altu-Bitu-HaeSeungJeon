#include <iostream>

using namespace std;

/*  문제의 case 분류
    1. 홀수 개수인 알파벳이 2개 이상 있으면-> 팰린드롬이 될 수 없으므로 I'm Sorry Hansoo 출력
    2. 홀수 개수인 알파벳이 1개 있으면 -> 그 알파벳 하나를 중간에 넣어주고 나머지는 사전순 출력
    3. 홀수 개수인 알파벳이 없으면 -> 사전순 출력
*/

//출력하는 함수
void printPalindrome(int a, int b, int alpha[]){
    if(a<b){
        for(int i=a;i<=b;i++){
            if(alpha[i]>0){ //만약 값이 있다면
                int temp = alpha[i]/2;
                while(temp--){
                    cout << char(i + 'A' - 1);
                }
            }
        }
    }
    else{
        for(int i=a;i>=b;i--){
            if(alpha[i]>0){ //만약 값이 있다면
                int temp = alpha[i]/2;
                while(temp--){
                    cout << char(i + 'A' - 1);
                }
            }
        }
    }
}

//case 중 어느 것인지 분류하는 함수
void isPalindrome(int length, int alpha[]){
    int cnt=0;
    int center;
    
    for(int i=1;i<=26;i++){
        if(alpha[i]%2==1){ //만약 홀수가 있다면
            center = i;
            cnt++; //홀수인 알파벳 개수를 세 준다.
        }
    }
    
    if(cnt>1){
        cout<< "I'm Sorry Hansoo";
    }
    
    if(cnt==0){
        printPalindrome(1, 26, alpha);
        printPalindrome(26, 1, alpha);
    }
    if(cnt==1){
        alpha[center]--;
        printPalindrome(1, 26, alpha);
        cout << char(center + 'A' - 1); //중간에 알파벳 넣어주기
        printPalindrome(26, 1, alpha);
    }
    
}

int main() {
    
    int alpha[27] = {0};
    string name;
    
    cin >> name;
    int length = name.length();
    
    //문자열의 알파벳 개수 세서 저장
    for(int i=0;i<length;i++){
        int idx = name[i] - 'A' + 1;
        alpha[idx]++;
    }
    
    isPalindrome(length, alpha);
}