#include <iostream>
#include <vector>
#include <algorithm> //sort 사용
#include <utility>

using namespace std;

vector<int> arr; //수열, 임시 배열

//비교함수
bool cmpAdv(const pair<int, int>&a, const pair<int, int>&b){
    if(a.second != b.second){ //y좌표가 다르다면
        return a.second <  b.second; //y좌표가 증가하는 순서대로 정렬
    }
    //y좌표가 같으면 x좌표는 무조건 다름(위치가 같은 두 점은 존재하지 X)
    return a.first <  b.first; //x좌표가 증가하는 순서대로 정렬
}

int main() {
    int n; //점의 개수

    cin >> n;
    
    vector<pair<int, int>> arr(n); //vector와 pair 컨테이너 같이 사용
    
    for(int i=0;i<n;i++){
        cin >> arr[i].first >> arr[i].second;
    }
    
    sort(arr.begin(), arr.end(), cmpAdv);
    
    //출력
    for(int i=0; i<n; i++){
        cout << arr[i].first << " " << arr[i].second << "\n";
    }
    return 0;
}