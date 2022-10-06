#include <iostream>
#include <vector>

using namespace std;

//소수를 구하는 함수
void findPrime(int n, vector<bool> &number){
    
    //0과 1은 소수가 아니므로 false
    number[0] = number[1] = false;
    
    //각 숫자를 하나씩 검사하기
    for(int i=2;i<=n;i++){
        if(!number[i]){ //이미 소수가 아니라고 판단되어 있으면 다음 수로 넘어가기
            continue;
        }
        //i의 배수를 지워줌
        for(int j=i+i;j<=n;j+=i){
            if(!number[j]){ //이미 소수가 아니라고 판단되어 있으면 다음 수로 넘어가기
                continue;
            }
            number[j] = false;
        }    
    }
}

//제곱의 합을 구하는 함수
int sum(int temp){
    int answer = 0;
    while(temp!=0){
        answer += (temp % 10)*(temp % 10);
        temp = temp / 10;
    }
    return answer;
}

//상근수를 구하는 함수
void findSquared(int n, vector<bool> &number, vector<int> &answer){
    //n의 범위가  (10 <= n <= 1,000,000)이므로, 각 자릿수 제곱의 합이 가장 큰 수는 999,999임
    //(9*9) * 6 = 486이므로 배열로 구현해도 메모리가 크게 소모되지 않음

    for(int i=2;i<=n;i++){ //숫자 n을 나타내는 변수 i
        vector<bool> squareSum_visited(487, false);
        if(!number[i]){ //소수가 아니라면 상근수인지 검사하지 않음
            continue;
        }
        int temp=i;
        while(true){
            int result=sum(temp); //자릿수 제곱의 합을 result에 저장
            if(result==1){ //resul가 1이라면 소수상근수라는 의미이므로 answer에 저장
                answer.push_back(i);
                break;
            }
            if(!squareSum_visited[result]) //아직 방문하지 않은 숫자였다면 방문으로 표시
                squareSum_visited[result]=true;
            else //이미 방문한 숫자였다면 circle이라는 뜻이므로 break
                break;
            
            temp = result;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    
    vector<bool> number(n+1, true); //true로 초기화
    vector<bool> squared_sum(487, false);
    vector<int> answer;
       
    findPrime(n, number);
    findSquared(n, number, answer);
       
    for(int i=0;i<answer.size();i++){
        cout << answer[i] << '\n';
    }
       
    return 0;
}