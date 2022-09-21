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

void calculate(int R, int B){
    while(true){
        W=0.5*R-L+2;
        
        if(B==L*W-R){ //주어진 R, B 값에 계산 공식이 일치하면 break
            break;
        }
        else{
            L++;
        }
    }
}

int main() {
    int R, B;
    cin >> R >> B;
    
    calculate(R, B);
    
    if(L<W) swap(L, W); //더 큰 수를 L로 설정
    
    cout << L << ' ' << W;

}