#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//값을 계산하는 과정에서 숫자가 |10억|을 넘지 않으므로, int 형을 사용해도 된다.
//계산해 봐야 하는 케이스는 최소 1번~최대 약 10C3*7C2*5C3*2C2=25,200번이므로, 모든 케이스를 시도해도 된다.

int max_cal = -1e9-1;
int min_cal = 1e9+1;

//사칙연산하는 함수
int mathCal(int answer, int i, vector<int> &oper, vector<int> &num){
    if(oper[i]==3){
        return answer += num[i+1];
    }
    if(oper[i]==2){
        return answer -= num[i+1];
    }
    if(oper[i]==1){
        return answer *= num[i+1];
    }
    if(oper[i]==0){
        return answer /= num[i+1];
    }
    return 0;
}

//연산하는 함수
void calculate(int n, vector<int> &num, vector<int> &oper){
    
    do{
        int answer=num[0]; 
        for(int i=0;i<n-1;i++){ //배열에 저장된 연산자 순서대로 계산
           answer = mathCal(answer, i, oper, num); //사칙연산하는 함수 호출
        }
        
        max_cal = max(answer, max_cal);
        min_cal = min(answer, min_cal);
        
    }while(prev_permutation(oper.begin(), oper.end()));  //연산자 순서 새롭게 바꾸기
}

int main() {
    int n;
    cin >> n;
    vector<int> num(n); //피연산자 저장
    vector<int> oper; //연산자 저장
    
    for(int i=0;i<n;i++){
        cin >> num[i]; //피연산자 저장
    }
    
    int oper_weight=4; //각 연산자를 구분해주기 위한 숫자
    
    while(oper_weight--){
        int oper_num; //각 연산자의 개수
        cin >> oper_num;

        for(int i=0;i<oper_num;i++){
            oper.push_back(oper_weight); //연산자의 개수만큼 벡터에 넣어주기
        }
    }
    
    calculate(n, num, oper);
    
    cout << max_cal << '\n' << min_cal;

}