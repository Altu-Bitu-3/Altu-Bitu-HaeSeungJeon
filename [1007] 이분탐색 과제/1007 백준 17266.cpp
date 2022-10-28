#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//가로등의 높이가 height가 되도록 가로등을 설치했을 때, 설치된 가로등 개수
bool cntLamp(int height, vector<int> &location, int n) {
    int cur = 0; //커버해야 하는 왼쪽 영역

    for (int i = 0; i < location.size(); i++) {
        if (cur >= location[i] - height ) {
            cur = location[i] + height;
        } else {
            return false; //height가 너무 작아 다음 위치를 커버할 수 없는 경우
        }
    }
    //마지막 가로등이 끝까지 커버하는지 검사
    //참고 문헌: https://velog.io/@jms8732/17266.-어두운-굴다리
    //참고 이유: 마지막 조건문을 어떻게 짜야 할지 몰라서 해당 코드를 참고했습니다.
    if(n-cur > 0)
        return false;
    return true;
}

//m개의 가로등을 설치 가능한 최소 높이 탐색
int binarySearch(int left, int right, int target, vector<int> &location, int n) {
    while (left <= right) {
        int mid = (left + right) / 2;
        
        //해당 height로 모든 길을 커버할 수 있는지 테스트
        bool isCovered = cntLamp(mid, location, n);
        if (isCovered==false) { //커버가 불가능하다면 높이를 높여야 함
            left = mid + 1;
        } else { //커버가 가능하다면 높이를 낮춰서 다시 시도
            right = mid -1;
        }
    }
    return left;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;

    //입력
    cin >> n >> m;
    vector<int> location(m, 0);
    for (int i = 0; i < m; i++) { //가로등 설치할 수 있는 위치
        cin >> location[i];
    }

    //연산 & 출력
    cout << binarySearch(1, n, m, location, n);
    
    return 0;
}