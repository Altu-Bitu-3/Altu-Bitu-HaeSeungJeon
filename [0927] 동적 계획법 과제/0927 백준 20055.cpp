#include <iostream>
#include <deque>

using namespace std;

int spin(int n, int k, deque<int> &belt, deque<bool> &robot){
    int ans=0;
    int zero_belt=0;

    while(zero_belt<k){
        ans++; //단계 하나 증가
        
        //1. 한 칸 회전(덱을 이용하여 회전한 것처럼 만듬)
        belt.push_front(belt.back());
        belt.pop_back();
        //1.1 로봇도 같이 회전
        robot.pop_back();
        robot.push_front(false);
        robot[n-1]=false; //마지막 n 번째 칸에 있던 로봇은 무조건 내려줘야 함
    
        //2. 벨트 위의 로봇들을 앞으로 이동
        for(int i=n-2;i>=0;i--){ //가장 먼저 컨테이너에 올라간 로봇부터 앞으로 이동
            //로봇이 현재 검사하는 벨트 위에 존재하고, 다음 칸의 내구도가 1 이상이며 로봇이 없다면 이동
            if(robot[i]==true && belt[i+1]>0 && robot[i+1]==false){ 
                robot[i]=false; //로봇 다음 칸으로 이동
                robot[i+1]=true;
                belt[i+1]--; //내구도 감소
                if (belt[i+1]<=0) //내구도 감소한 결과가 0이라면 카운트
                    zero_belt++;
            }
        }
        robot[n-1]=false; //마지막 n 번째 칸에 있던 로봇은 무조건 내려줘야 함
        
        //3. 로봇 올리기
        if(belt[0]>0 && robot[0]==false){ //올리는 칸의 내구도가 1 이상이고 로봇이 없다면
            robot[0]=true; //로봇 올리기
            belt[0]--; //내구도 감소
            if (belt[0]<=0) 
                zero_belt++;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    deque<int> belt; //벨트의 내구도를 저장하는 배열
    deque<bool> robot(n, false); //벨트 위에 로봇이 있는지 저장하는 배열(false로 초기화)

    //벨트 내구도 저장
    for(int i=0;i<2*n;i++){
        int belt_in;
        cin >> belt_in;
        belt.push_back(belt_in);
    }
    
    cout << spin(n, k, belt, robot);
}