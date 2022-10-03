#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int idx[26];

/* 중요한 코너케이스 -> 이 경우에는 fail
   1. 같은 알파벳이 중복으로 다른 위치에 저장된 경우
   2. 같은 바퀴 자리에 다른 알파벳이 저장되려고 하는 경우
*/

int wheel_check(int n, int after, char alpha, vector<char> &wheel){

    if(idx[alpha-'A']!=-1 && idx[alpha-'A']!=after){ //다른 위치에 이미 저장되어 있다면 false
        return -1;
    }
    if(wheel[after]!='?' && wheel[after]!=alpha){ //만약 해당 위치에 이미 다른 알파벳이 저장되어 있다면 false
        return -1;
    }
    wheel[after] = alpha; //문자 넣어주기
    idx[alpha-'A'] = after; //해당 인덱스에서 방문했다고 표시

    return after;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    fill(idx, idx+26, -1);
    
    int n, k; //바퀴의 칸 수, 바퀴를 돌리는 횟수
    cin >> n >> k;
    
    vector<char> wheel(n, '?'); //알파벳을 저장할 바퀴 초기화

    int last=0; //마지막으로 바퀴가 위치했던 인덱스 저장
    
    while(k--){
        int rotate;
        char alpha;
        cin >> rotate >> alpha;
        int after = (last+rotate)%n; //회전 후 인덱스 위치
        last = wheel_check(n, after, alpha, wheel);
        if(last==-1){ //만약 정상적인 바퀴가 아니라면 break
            break;
        }
    }   
    
    if(last==-1){ //정상적이지 않을 경우 ! 출력
        cout << '!';
    }
    else{ //아닐 경우 바퀴 내용 출력
        for(int i=0;i<n;i++){
            cout << wheel[(n+last-i)%n];
        }
    }
    return 0;
}