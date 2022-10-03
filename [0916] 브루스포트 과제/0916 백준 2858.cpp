#include <iostream>
#include <algorithm>

using namespace std;

//R, B, L, W 사이 관계를 나타내는 공식
// 1. R=2*L+2*W-4
// 2. B=(L*W)-R

//R ≤ 5000, B ≤ 2,000,000
//따라서 L = 0.5R-W+2 = 2500-W+2 이므로 L을 1부터 검사해도 시간 초과나지 않음

int L=1; //1부터 검사
int W;

void calculate(int R, int B, pair<int, int> &ans){
    while(true){
        W=0.5*R-L+2;
        
        if(B==L*W-R){ //주어진 R, B 값에 계산 공식이 일치하면 break
            break;
        }
        else{
            L++;
        }
    }
    ans.first=W; //더 큰 수가 먼저 출력되어야 함 (정답을 찾는 순간 바로 break -> W가 항상 더 큼)
    ans.second=L;
}

int main() {
    int R, B;
    cin >> R >> B;
    
    pair<int, int> ans;
    
    calculate(R, B, ans);
    
    
    
    cout << ans.first << ' ' << ans.second;

}