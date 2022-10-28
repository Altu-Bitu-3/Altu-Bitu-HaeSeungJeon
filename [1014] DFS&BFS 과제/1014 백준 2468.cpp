#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> ci;
bool visited[100][100]; //전역 변수로 설정-false 초기화

//1부터 100까지 내리는 모든 비의 경우의 수를 다 구한다.
//BFS 시간 복잡도 O(100^2) * 100을 해도 1,000,000밖에 안 되므로, 브루스 포트가 가능하다.
void bfs(vector<vector<int>> &matrix, queue<ci> &que, int rain, int n){
    // 상, 하, 좌, 우
    int dr[] = {-1, +1, 0, 0};
    int dc[] = {0, 0, -1, +1};
    
    while (!que.empty()) {
        auto[r, c] = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int new_r = r + dr[i];
            int new_c = c + dc[i];
            //새로운 좌표가 범위 안에 있는지, 침수되지 않았는지, 방문하지 않았는지 확인
            if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < n && matrix[new_r][new_c]-rain > 0 && visited[new_r][new_c]==false ){
                que.push({new_r, new_c});
                visited[new_r][new_c] = true; //방문되었다고 표시
            }
        }
    }
}

int safeCnt(int n, vector<vector<int>> &matrix, int max_height) {
    int safeMax = 0; //가장 많은 안전 구역
    
    //내리는 비의 양의 최솟값: 0
    //내리는 비의 양의 최대값: 가장 높은 지점(그 이상은 모든 구역이 물에 잠기므로 의미없음)
    for(int rain=0;rain<=max_height;rain++){
        queue<ci> que;  // 탐색을 하기 위해 사용할 큐
        int cnt = 0;  // 안전 영역의 수
        for(int i=0 ; i<n; i++){
            for(int j=0 ; j<n ; j++){
                //이미 방문했거나, 침수된 지역이면 조사하지 않음
                if(visited[i][j]==true || matrix[i][j]-rain <=0){
                    continue;
                }
                //방문하지 않았고 침수되지 않은 지역이라면 bfs 시작
                que.push({i, j});
                cnt++; //안전 영역 하나 증가
                bfs(matrix, que, rain, n);
            }
        }
        fill(&visited[0][0], &visited[n-1][n], false); //초기화
        safeMax = max(safeMax, cnt);
    }
    return safeMax;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    // 입력
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n, 0)); //각 지점의 높이 정보를 저장할 2차원 벡터

    int max_height=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            //최댓값 저장
            max_height = max(max_height, matrix[i][j]);
        }
    }
    cout << safeCnt(n, matrix, max_height);
    return 0;
}