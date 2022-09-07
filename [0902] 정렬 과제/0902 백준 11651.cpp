#include <iostream>
#include <vector>
#include <algorithm> //sort 사용

using namespace std;

vector<int> arr; //수열, 임시 배열

struct coordinate{
    int x, y;
};

//비교함수
bool cmpAdv(const coordinate&a, const coordinate&b){
    if(a.y != b.y){ //y좌표가 다르다면
        return a.y <  b.y; //y좌표가 증가하는 순서대로 정렬
    }
    
    if(a.x != b.x){ //x좌표가 다르다면
        return a.x <  b.x; //x좌표가 증가하는 순서대로 정렬
    }
    return 0;
}

int main() {
    int n; //점의 개수

    cin >> n;
    
    vector<coordinate> arr(n);
    
    for(int i=0;i<n;i++){
        cin >> arr[i].x >> arr[i].y;
    }
    
    sort(arr.begin(), arr.end(), cmpAdv);
    
    //출력
    for(int i=0; i<n; i++){
        cout << arr[i].x << " " << arr[i].y << "\n";
    }
    return 0;
}