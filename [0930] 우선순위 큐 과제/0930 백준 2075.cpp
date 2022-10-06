#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int temp=0;
    priority_queue<int, vector<int>, greater<int>> q; //오름차순 정렬되는 큐
        
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> temp;
            //우선 순위 큐의 크기가 n으로 일정하도록 만든다.
            //(top의 작은 값을 제외해 나가면서 큐의 크기를 n으로 유지하면, 결국 우선순위 큐에 1부터 n번째로 큰 수만 남음.)
            if(q.size() < n){ //크기가 n보다 작다면 그냥 넣어준다
                q.push(temp);
                continue;
            }
            //크기가 n이라면 top 보다 넣으려는 값이 클 경우에만 넣는다.
            if(temp > q.top()){
                q.push(temp);
                q.pop(); //n으로 맞추기 위해 하나 빼준다.
            }
            
        }
    }
    
    cout << q.top();
    
}