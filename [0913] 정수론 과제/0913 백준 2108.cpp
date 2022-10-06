#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>

using namespace std;
#define pp pair<int,int>

//최빈값 구하기 위해 map의 value를 기준으로 정렬하는 함수
bool cmp(const pp& a, const pp& b) {
	if (a.second == b.second) return a.first > b.first; //같은 빈도 내에서는 내림차순 정렬
	return a.second < b.second; //서로 다른 빈도 내에서는 오름차순 정렬
}

//산술 평균 구하는 함수
void mean(int num[], int n){
    double sum=0; //float를 쓸 경우 오류 발생 -> 더 정확한 double 사용!
    for(int i=0;i<n;i++){
        sum += num[i];
    }
    //-0은 따로 처리하기
    if(round(sum/n) != -0){
        cout <<  round(sum/n) << '\n';
    }
    else cout << abs(round(sum/n)) << '\n';
}

//중앙값 구하는 함수
void median(int num[], int n){
    sort(num, num+n); //숫자들을 오름차순으로 정렬
    cout << num[n/2] << '\n';
}

//최빈값 구하는 함수
void mode(vector<pair<int,int>> &vec){
    sort(vec.begin(), vec.end(), cmp);
    if(vec[vec.size()-1].second!=vec[vec.size()-2].second){ //빈도 수 다르다면 최빈값 그대로 출력
        cout << vec[vec.size()-1].first << '\n';
    }
    else{
        cout << vec[vec.size()-2].first << '\n'; //빈도 수가 같다면 두번째로 작은 숫자 출력
    }
        
}

//범위 구하는 함수
void range(int num[], int n){
    int range = num[n-1] - num[0];
    cout << abs(range);
}

int main() {
    int n;
    cin >> n;
    
    int num[n];
    map<int, int> frequency;
    
    
    for(int i=0;i<n;i++){
        int input;
        cin >> input;
        
        //숫자의 빈도 저장
        if(frequency[input]){
           frequency[input]++; //빈도 증가
        }
        else{
            frequency[input] =1; //빈도를 처음으로 저장
        }
        
        //숫자 자체를 저장
        num[i]=input;
    }
    
    mean(num, n);
    median(num, n);
    
    vector<pp> vec(frequency.begin(), frequency.end());
    mode(vec);
    range(num, n);
    
}