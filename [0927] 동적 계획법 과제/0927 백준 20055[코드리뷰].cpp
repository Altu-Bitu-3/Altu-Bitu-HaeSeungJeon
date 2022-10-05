#include <iostream>
#include <deque>

using namespace std;

struct Container{ //벨트 내구도와 로봇의 유무를 모두 저장하는 구조체
    bool robot=false;
    int belt;
};

void rotate(int n, deque<Container> &de){
    //1. 컨테이너 한 칸 회전(덱을 이용하여 회전한 것처럼 만듬)
    de.push_front(de.back());
    de.pop_back();
    de[n-1].robot = false; //마지막 n 번째 칸에 있던 로봇은 무조건 내려줘야 함
}

int spin(int n, int k, deque<Container> &de){
    int ans=0;
    int zero_belt=0;

    while(zero_belt<k){
        ans++; //단계 하나 증가
        
        //1.로봇과 벨트 회전
        rotate(n, de);
    
        //2. 벨트 위의 로봇들을 앞으로 이동
        for(int i=n-2;i>=0;i--){ //가장 먼저 컨테이너에 올라간 로봇부터 앞으로 이동
            //로봇이 현재 검사하는 벨트 위에 존재하고, 다음 칸의 내구도가 1 이상이며 로봇이 없다면 이동
            if(de[i].robot==true && de[i+1].belt>0 && de[i+1].robot==false){ 
                de[i].robot=false; //로봇 다음 칸으로 이동
                de[i+1].robot=true;
                de[i+1].belt--; //내구도 감소
                if (de[i+1].belt<=0) //내구도 감소한 결과가 0이라면 카운트
                    zero_belt++;
            }
        }
        de[n-1].robot=false; //마지막 n 번째 칸에 있던 로봇은 무조건 내려줘야 함
        
        //3. 로봇 올리기
        if(de[0].belt>0 && de[0].robot==false){ //올리는 칸의 내구도가 1 이상이고 로봇이 없다면
            de[0].robot=true; //로봇 올리기
            de[0].belt--; //내구도 감소
            if (de[0].belt<=0) 
                zero_belt++;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    deque<Container> de(2*n);

    //벨트 내구도 저장
    for(int i=0;i<2*n;i++){
        cin >> de[i].belt;
    }
    
    cout << spin(n, k, de);
}