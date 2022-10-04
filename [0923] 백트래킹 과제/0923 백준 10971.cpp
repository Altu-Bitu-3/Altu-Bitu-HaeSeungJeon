#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define SIZE 10

using namespace std;

int n;
int min_cost=INT_MAX;
int city[SIZE][SIZE];
bool check[SIZE];

void backtracking(int row, int city_num, int result_cost){ //방문한 도시수, 도시 방문한 결과(비용)

    if(city_num==n){ //모든 도시 다 방문한 경우(기저 조건)
        /* if(city[row][0]==0) 조건문 코드 참고: https://regularmember.tistory.com/53
           참고 이유: 마지막 도시에서 출발 도시로 당연히 올 수 있으리라 생각해서 자꾸 50%쯤에서 '틀렸습니다'가 떴습니다.
           해결하기 위해 구글링하다가 놓친 마지막 조건을 발견해 이 부분 코드를 해당 블로그를 참고했습니다.
        */
        //마지막 도시에서 출발 도시로 올 수 없거나, 현재까지 계산한 값이 이미 최소값보다 크면 return
        if(city[row][0]==0 || result_cost > min_cost){
            return;
        }
        min_cost = min(min_cost, result_cost+city[row][0]); //해당 경로 값이 최솟값이 되는지 확인
        return;
    }
    for(int j=0;j<n;j++){ //j: 열
        //같은 행의 다른 열을 방문해주면 그게 곧 한 도시에서 갈 수 있는 도시를 방문하는 게 됨.
        if(!check[j] && city[row][j]!=0){ //이미 방문한 도시 또는 자기 자신은 방문 불가
            check[j]=true; //어떤 도시 방문하면 그 도시 선택지 전부 없애기
            backtracking(j, city_num+1, result_cost+city[row][j]); //다음 도시의 행 호출
            //재탐색이 가능하도록 원래 상태로 돌려준다.
            check[j]=false;
        }
    }
}

int main() {
    cin >> n; //도시의 수 
    for(int i=0;i<n;i++){ //각 도시의 비용 입력
        for(int j=0;j<n;j++){
            cin >> city[i][j];
        }
    }
    
    check[0] = true;
    backtracking(0, 1, 0);
    cout << min_cost;
    return 0;
    
}