#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj_list;
vector<bool> visited;
vector<int> parent;
 
//재귀함수로 구현한 dfs
void nodeParent(int curr){
    if (visited[curr]) {  // 이전에 방문했던 정점이라면 종료
        return;
    }
    visited[curr] = true; //방문 표시

    for(int i = 0; i < adj_list[curr].size(); i++){
        int next = adj_list[curr][i]; //다음 인접 노드 이동
        //방문이 안 되어 있다면, 자식 노드라는 의미임(부모 노드라면 자식에 앞서서 방문되어 있음)
        if(visited[next] == false){
            parent[next] = curr;
            nodeParent(next);
        }
    }
}
 
int main() {
    int n, a, b; 
    cin >> n;
    adj_list.assign(n+1, vector<int>()); //인접 리스트로 선언
    visited.assign(n+1, false);
    parent.assign(n+1, 0);

    for(int i=0;i<n-1;i++){
        cin >> a >> b; 
        adj_list[a].push_back(b); //양방향 저장
        adj_list[b].push_back(a);
    }
    
    nodeParent(1); //1번 노드가 루트, 즉 시작점이 됨

    for(int i = 2; i <= n; i++){
        cout << parent[i] << '\n';
    }
    
    return 0;
}