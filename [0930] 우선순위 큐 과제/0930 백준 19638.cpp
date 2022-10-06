 #include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int isStillTaller(int t, int centi, priority_queue<int> &q){
    int flag=0;
    for(int i=0;i<t;i++){
        if(q.top() >= centi && q.top() > 1){ //만약 거인이 센티보다 더 키가 크다면
            flag++; //뿅망치 한번 사용
            q.push(q.top()/2); //다시 큐에 넣기
            q.pop();
        }
        if(q.top() < centi){ //만약 top의 거인이 센티보다 작다면
            return flag; //뿅망치 사용 횟수 리턴
        }
    }
    if(q.top() >= centi) //여전히 top의 거인이 센티보다 크다면 -1 반환
        return -1;
    return -1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, centi, t; //거인 나라 인구수, 센티의 키, 마법의 뿅망치 횟수 제한
    cin >> n >> centi >> t;
    priority_queue<int> q; //내림차순 정렬되는 큐
    
    //큐에 저장
    int giant_height;
    for(int i=0;i<n;i++){
        cin >> giant_height;
        q.push(giant_height);
    }
    int result=isStillTaller(t, centi, q);
    switch(result){
        case -1: 
            cout << "NO\n"; //여전히 키 큰 거인이 남아있는 경우
            cout << q.top();
            break;
            
        default:
            cout << "YES\n"; //모든 거인이 센티보다 키가 작은 경우
            cout << result;
            break;
        
    }

}