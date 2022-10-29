#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int answer=0;

void findCow(int left, int right, vector<int> &cow, int s) {
    //left 값을 하나씩 증가
    for(int left=0;left<cow.size();left++){
        while(cow[left] + cow[right] > s && left < right){ //코스튬 사이즈를 넘어가면 오른쪽을 하나 옆의 왼쪽으로 이동
            right--;
        }
        if (cow[left] + cow[right] <= s) { //둘을 더한 값이 코스튬보다 작거나 같으면 쌍을 만들 수 있음
            answer += right-left; //소의 쌍의 수 저장
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, s;
    cin >> n >> s;
    vector<int> cow(n, 0); //초기화
    for(int i=0;i<n;i++){ //소의 사이즈 저장
        cin >> cow[i];
    }
    
    //사이즈 정렬
    sort(cow.begin(), cow.end());
    findCow(0, n-1, cow, s);
    cout << answer;

    return 0;
}