#include <iostream>
#include <algorithm>

using namespace std;

//풀이 방법: 시간이 적게 걸리는 사람을 더 앞에 세우기

//모든 사람의 시간의 합을 구해주는 함수
int sum(int n, int arr[]){
    int result=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            result+=arr[j];
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    int line[n];
    
    for(int i=0;i<n;i++){
        cin >> line[i];
    }
    
    sort(line, line+n); //오름차순 정렬
    cout << sum(n, line);
}