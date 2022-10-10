#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define MAX 999

//9*8*7=504가 최대 경우의 수가 되므로, 브루트포스 사용 가능
//가능한 스트라이크-볼 조합: 3-0, 2-0, 1-2, 1-1, 1-0, 0-3, 0-2, 0-1, 0-0
bool checked[MAX+1];

struct Cases{
    string num;
    int strike;
    int ball;
};

//스트라이크 수와 볼 수가 많은 순서대로 정렬하는 함수
bool cmp(const Cases &a, const Cases &b){
    if(a.strike == b.strike){
        return a.ball > b.ball; //스트라이크 수가 같다면 볼이 많은 순서대로 정렬
    } else{
        return a.strike > b.strike; //스트라이크 수 큰 순서대로 정렬
    }
}

void checkNumCase(int n, struct Cases arr[]){
    for(int i=0;i<n;i++){ //각 케이스 별 검사
        for(int j=111;j<MAX+1;j++){ //모든 숫자 검사
            if(checked[j]==false){ //이미 이전 케이스 검사 결과 올바르지 않으면 패스
                continue;
            }
            string j_num = to_string(j);
            //숫자에 0포함되어 있으면 패스
            if(j_num.find('0') != string::npos){
                checked[j]=false;
                continue;
            }
            //숫자에 같은 숫자가 포함되어 있으면 패스
            if(j_num[0]==j_num[1] || j_num[1]==j_num[2] || j_num[2]==j_num[0]){
                checked[j]=false;
                continue;
            }
            int s_cnt=0;
            int s_digit[3];
            //스트라이크 수 같은지 확인
            for(int k=0;k<3;k++){
                if(j_num[k]==arr[i].num[k]){
                    s_cnt++;
                }
            }
            if(s_cnt!=arr[i].strike){
                checked[j]=false;
                continue;
            }
            int b_cnt=0;
            //볼 수 같은지 확인
            for(int k=0;k<3;k++){
                if(j_num[k]!=arr[i].num[k] && j_num.find(arr[i].num[k]) != string::npos){
                    b_cnt++;
                }
            }
            if(b_cnt!=arr[i].ball){
                checked[j]=false;
                continue;
            }
        }
    }
    
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    struct Cases arr[n]; //구조체 배열 생성 
    for(int i=0;i<n;i++){
        cin >> arr[i].num >> arr[i].strike >> arr[i].ball;
    }
    //구조체 배열 정렬
    sort(arr, arr+n, cmp);
    fill_n(checked, MAX+1, true);
    
    //가능한 숫자의 개수 맞추기
    checkNumCase(n, arr);
    int ans=0;
    for(int i=111;i<MAX+1;i++){
        if(checked[i]==true){
            ans++;
        }
    }
    cout << ans;
}