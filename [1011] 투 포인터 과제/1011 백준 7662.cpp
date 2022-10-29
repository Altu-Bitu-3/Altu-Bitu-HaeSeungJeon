#include <iostream>
#include <queue>

using namespace std;
/*참고 문헌: https://velog.io/@mttw2820/백준-7662.-이중-우선순위-큐
  참고 이유: 같은 값 중복이라는 조건을 못 봐서 valid를 map으로 구현했었는데,
  자꾸 오류가 나서 이를 고치고자 valid를 배열로 구현하는 법을 참고했습니다.
*/
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t=0;
    // 입력
    cin >> t;

    //각 테스트 케이스
    while(t--){
        priority_queue<pair<int, int>> max_heap; // heap 초기화(최대 힙, 내림차순 정렬)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap; //최소 힙, 오름차순 정렬
        bool valid[1000001]; //해당 숫자가 valid 한지 확인
        int k=0; 
        cin >> k; //테스트 케이스 당 연산의 갯수

        for(int idx=0; idx< k; idx++) {
            char oper; int num=0;
            cin >> oper >> num;
            
            if (oper == 'D') { //삭제 연산
                if(num == 1){ //최댓값 삭제
                    //top에 이미 삭제된 값이 있다면 pop
                    while(!max_heap.empty() && !valid[max_heap.top().second]){
                        max_heap.pop();
                    }
                    if(!max_heap.empty()){
                        valid[max_heap.top().second] = false;
                        max_heap.pop();
                    }
                }
                else{ //최솟값 삭제
                    //top에 이미 삭제된 값이 있다면 pop
                    while(!min_heap.empty() && !valid[min_heap.top().second]){
                        min_heap.pop();
                    }
                    if(!min_heap.empty()){
                        valid[min_heap.top().second] = false;
                        min_heap.pop();
                    }
                }
            }
            if(oper == 'I'){ //삽입 연산
                valid[idx] = true;
                min_heap.push(make_pair(num, idx));
                max_heap.push(make_pair(num, idx));
            }
        }
        while(!max_heap.empty() && !valid[max_heap.top().second]){
            max_heap.pop();
        }
        while(!min_heap.empty() && !valid[min_heap.top().second]){
            min_heap.pop();
        }
        
        if(max_heap.empty()){
            cout << "EMPTY\n";
        } else{ //주의할 점: 마지막 줄에 '\n' 안 넣으면 3%에서 틀렸다고 나옴
            cout << max_heap.top().first << ' ' << min_heap.top().first << '\n';
        }
    }
    return 0;
}