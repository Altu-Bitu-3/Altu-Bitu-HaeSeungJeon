#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cntSnack(int length, vector<int> &snack) {
    int cnt = 0; //과자 조각 갯수

    for (int i = 0; i < snack.size(); i++) {
        if (snack[i]/length >= 1) { //막대 과자를 조각으로 나누기
            cnt+=snack[i]/length; //과자 조각 생성
        }
    }
    return cnt; //만들어진 과자 조각의 수
}

int upperSearch(int left, int right, int target, vector<int> &snack) {
    while (left <= right) {
        int mid = (left + right) / 2;
        
        //해당 과자 길이로 과자 조각을 만들면 모두에게 줄 수 있는지 테스트
        int snackPiece = cntSnack(mid, snack);
        
        if (snackPiece >= target) { //과자 조각 수가 더 많으면 조각의 길이를 늘려보기
            left = mid + 1;
        } else { //과자 조각이 더 적으면 조각의 길이를 줄여야 함
            right = mid -1;
        }
    }
    return left - 1; //upper bound값에서 1을 뺌
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m, n;
    
    cin >> m >> n;
    vector<int> snack(n, 0);
    for (int i = 0; i < n; i++) { //과자의 길이 저장
        cin >> snack[i];
    }
    
    //정렬
    sort(snack.begin(), snack.end());
    
    //조각의 길이 최소: 1
    //조각의 길이 최대: 가장 긴 막대 과자의 길이(조각을 합칠 수 없으므로, 이 이상은 불가)
    cout << upperSearch(1, snack[n-1], m, snack);
}