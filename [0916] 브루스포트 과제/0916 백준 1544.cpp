#include <iostream>
#include <deque>

using namespace std;

//단어의 길이가 최대 50이므로, 한 단어의 순서를 바꿔주는 계산 수는 50
//단어의 개수 N은 최대 50이므로, 최대 계산 수는 250 -> 브루스포트 가능!

//단어가 같은지 확인하는 함수
bool isSame(deque<char> a, deque<char> b){
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]){
            return false;
        }
    }
    return true;
}

//단어의 글자 순서를 바꾸는 함수
int findCircle(int n, deque<char> de[]){
    int visited[n]={false};
    int answer=0;
    
    for(int i=0;i<n;i++){
        if(visited[i]==true){ //이미 방문했다면 다음 단어로 넘어가기
            continue;
        }
        for(int j=i;j<n;j++){ //다른 단어들과 비교
            if(de[i].size()!=de[j].size()){ //단어의 길이부터 다르다면 당연히 같은 단어 아님
                continue;
            }
            for(int k=0;k<de[i].size();k++){

                if(isSame(de[i], de[j])){ //단어가 같은지 확인
                    visited[j] = true; //같다면 같은 단어 집합이라고 표시하기
                }
                
                char move = de[i].back(); //단어의 순서 바꾸기
                de[i].pop_back();
                de[i].push_front(move);
            }
        }
        answer++; //같은 단어 집합을 다 찾아내면 +1
    }
    
    return answer;
}

int main() {
    int n;
    cin >> n;
    deque<char> de[n];
    
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<s.length();j++){
            de[i].push_back(s[j]); //각 문자열의 문자를 덱에 집어넣기
        }
    }
    int answer = findCircle(n, de);
    
    cout << answer;
}