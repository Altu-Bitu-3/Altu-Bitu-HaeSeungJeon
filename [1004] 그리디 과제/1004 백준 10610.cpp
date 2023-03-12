#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int respect(int s_size, vector<int> &v){
    //30으로 나누어지는 조건=10으로 나누어져야 함(일의 자리 숫자가 0)&&3으로 나누어져야 함(자릿수 합이 3으로 나누어짐)
    if(v[s_size-1]!=0){ //10으로 안 나누어지면 리턴 -1
        return -1;
    }
    int sum=0;
    for(int i=0;i<s_size;i++){ //자릿수 합 구하기
        sum+=v[i];
    }
    if(sum%3==0){ //자릿수 합이 3으로 나누어지면 리턴 1
        return 1;
    } else{ //자릿수 합이 3으로 안 나누어지면 리턴 -1
        return -1;
    }
}

int main() {
    string s;
    cin >> s; //문자열로 입력받기
    int s_size = s.length();
    vector<int> v(s_size);
    
    for(int i=0;i<s_size;i++){
        v[i] = s[i] - '0'; //각 자릿수 저장
    }
    sort(v.begin(), v.end(), greater<>()); //내림차순 정렬
    
    int result=respect(s_size, v);
    switch(result){
        case -1:
            cout << -1;
            break;
        case 1:
            for(int i=0;i<s_size;i++){ //최종 답 프린트
                cout << v[i];
            }
            break;
    }
}