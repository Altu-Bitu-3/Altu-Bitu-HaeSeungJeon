#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//값을 계산하는 과정에서 숫자가 |10억|을 넘지 않으므로, int 형을 사용해도 된다.
//계산해 봐야 하는 케이스는 최소 1번~최대 약 10C3*7C2*5C3*2C2=25,200번이므로, 모든 케이스를 시도해도 된다.

int max_cal = -1e9-1;
int min_cal = 1e9+1;

//연산하는 함수
void calculate(int n, vector<int> &num, vector<int> &oper){
    
    do{
        int answer=num[0]; 
        for(int i=0;i<n-1;i++){ //배열에 저장된 연산자 순서대로 계산
            if(oper[i]==0){
                answer += num[i+1];
            }
            if(oper[i]==1){
                answer -= num[i+1];
            }
            if(oper[i]==2){
                answer *= num[i+1];
            }
            if(oper[i]==3){
                answer /= num[i+1];
            }
        }
        
        if(answer >  max_cal) max_cal = answer;
        if(answer < min_cal) min_cal = answer;
        
    }while(next_permutation(oper.begin(), oper.end()));  //연산자 순서 새롭게 바꾸기
}

int main() {
    int n;
    cin >> n;
    vector<int> num(n); //피연산자 저장
    vector<int> oper; //연산자 저장
    
    for(int i=0;i<n;i++){
        cin >> num[i]; //피연산자 저장
    }
    
    int oper_weight=0; //각 연산자를 구분해주기 위한 가중치
    
    while(oper_weight<4){
        int oper_num; //연산자의 개수
        cin >> oper_num;

        for(int i=0;i<oper_num;i++){
            oper.push_back(oper_weight); //연산자의 개수만큼 벡터에 넣어주기
        }
        oper_weight += 1; //다음 연산자를 저장하기 위해 가중치 증가
    }
    
    calculate(n, num, oper);
    
    cout << max_cal << '\n' << min_cal;

}