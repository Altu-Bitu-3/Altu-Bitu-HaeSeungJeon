#include <iostream>
#include <queue>

using namespace std;

void josephus(int k, int n, queue<int> &q){
    cout << '<';
    for(int i=1;i<n;i++){
        for(int j=1;j<k;j++){
            q.push(q.front()); //삭제하지 않는 사람은 다시 큐에 넣기
            q.pop();
        }
        cout << q.front() << ", ";
        q.pop(); //삭제하는 사람은 큐에서 꺼내기
    }
    cout << q.front() << '>';
}

int main(){
    int n, k;
    cin >> n >> k;
    
    queue<int> q;
    //큐에 저장하기
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    
    josephus(k, n, q);
}