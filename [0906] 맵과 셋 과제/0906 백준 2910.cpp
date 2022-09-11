#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
map<int, int> frq; //숫자와 빈도 저장
map<int, int> idx; //숫자와 처음 나온 인덱스 저장
vector<pair<int,int>> vec; //정렬을 위해 vector 이용

/*map을 value 값으로 정렬하는 코드*/
bool frequency(const pair<int,int>& a, const pair<int,int>& b) {
	if (a.second == b.second) 
	    return idx[a.first] < idx[b.first];
	return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
    int n, c;
    cin >> n >> c;
    
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        frq[num]++; //숫자의 빈도수 증가
        if(idx[num]==0) //만약 처음 등장한 숫자라면
            idx[num]=i+1; //숫자가 처음 나온 인덱스 저장
    }
    vector<pair<int,int>> vec( frq.begin(), frq.end() ); //map의 값을 백터로 이동
    
    sort(vec.begin(), vec.end(), frequency); //빈도(value)로 정렬하기 위해 sort 함수 사용
    
    //출력
    for (auto num : vec) {
        for(int i =0;i<num.second;i++){
            cout << num.first << ' ';
        }
	}

    return 0;
}