#include <iostream>
#include <queue>

using namespace std;
/*참고자료: 알튜비튜 '우선순위 큐' 강의*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n;
    
    priority_queue<int, vector<int>, greater<int>> pq; //오름차순으로 정렬
    while(n--){
        cin >> x;
        if(x==0){ //0이 입력값이라면 제거하기
            //비었다면 0 출력
            if(pq.empty()){
                cout << "0\n";
            } else{ //비어있지 않다면 배열에서 제외하기
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else{ //0 이외의 수라면 넣기
            pq.push(x);
        }
    }
    
}