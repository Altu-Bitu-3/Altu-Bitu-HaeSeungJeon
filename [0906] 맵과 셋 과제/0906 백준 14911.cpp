#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;
map<int, int> match_pair;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int num, sum;
    int pair_num = 0;
    while (scanf("%d", &num) != EOF){ //입력값이 끝날 때까지 vector에 저장
        vec.push_back(num);
    }
        
    sum = vec.back(); //마지막 수는 합의 값
    vec.pop_back(); //합의 값은 vector에서 제거해주기
    
    int size = vec.size();
    bool visited[size];
    for(int i=0;i<size;i++){
        visited[i] = false;
    }
    sort(vec.begin(), vec.end()); //값의 비교를 쉽게 하기 위해 정렬
    
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(vec[i]+vec[j] == sum && !visited[i] && !visited[j]){
                //중복을 막기 위해 방문 표시
                visited[i] = true;
                visited[j] = true;
                
                match_pair[vec[i]] = vec[j]; //쌍 저장
                pair_num++; //저장된 쌍의 개수 업데이트
            }
        }
    }
    
    //map 출력
    map<int,int>::iterator iter;

    for(iter=match_pair.begin();iter!=match_pair.end();iter++){
         cout << iter->first << ' ' <<iter->second << '\n';
    }
    cout << pair_num;
    
    return 0;
}

