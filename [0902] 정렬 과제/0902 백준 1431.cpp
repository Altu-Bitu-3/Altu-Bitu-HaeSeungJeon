#include <iostream>
#include <vector>
#include <algorithm> //sort 사용

using namespace std;
#define SERIAL_MAX 50

//합 비교함수
bool cmp_sum(int &a_size, int &b_size, const string&a, const string&b){
    //2. 합이 다르다면
    int a_sum = 0, b_sum = 0;
    for(int i=0;i<a_size;i++){
        if(isdigit(a[i]))
            a_sum += a[i] - '0';
        if(isdigit(b[i]))
            b_sum += b[i] - '0';
    }
    if(a_sum != b_sum)
        return a_sum < b_sum; //숫자 합 오름차순 정렬
    
    //1, 2로 비교할 수 없다면
    return a < b; //사전 순 정렬
}

//길이 비교함수
bool cmp_length(const string&a, const string&b){
    
    int a_size = a.size(), b_size = b.size();
    
    //1. 길이가 다르다면
    if(a_size != b_size){
        return a_size < b_size; //길이가 증가하는 순서대로 정렬
    }
    
    //2. 합이 다르다면
    return cmp_sum(a_size, b_size, a, b);
}

int main() {
    int n; //시리얼 번호 갯수

    cin >> n;
    
    vector<string> serial(n);  //n개 시리얼 번호
    
    for (int i = 0; i < n; i++){ //시리얼 번호 배열에 저장
        cin >> serial[i];
    }
    
    sort(serial.begin(), serial.end(), cmp_length);

    
    //출력
    for(int i=0; i<n; i++){
        cout << serial[i] << "\n";
    }
    return 0;
}