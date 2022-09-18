#include <iostream>
#include <algorithm>

using namespace std;

/*  대각선이 지나가는 타일의 개수는
    1. 대각선이 가로선을 한번 지나갈 때마다 하나씩 늘고
    2. 대각선이 세로선을 한번 지나갈 떄마다 하나씩 는다.
    규칙: (세로선의 개수)+(가로선의 개수)+(중복으로 제외한 처음 시작 타일 개수 1)
*/

//유클리드 호제법 이용
int gcd(int x, int y) {
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

int main() {
    //입력
    int x, y;
    cin >> x >> y;
    
    int result = gcd(x, y);
    
    cout << ((x/result-1)+(y/result-1)+1)*result;
        
}