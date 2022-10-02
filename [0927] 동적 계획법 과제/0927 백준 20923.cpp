#include <iostream>
#include <deque>

using namespace std;

deque<int> do_card; //도도의 덱
deque<int> su_card; //수연이의 덱
deque<int> do_gnd; //도도의 그라운드
deque<int> su_gnd; //수연이의 그라운드

int n, m;

/*자꾸 AccessEmptyContainer 에러가 뜨는 데 그 이유를 모르겠습니다.
  도와주시면 감사하겠습니다!
*/

void TakeCardCheck(){
    //양측 그라운드가 모두 차 있고, 그라운드의 합이 5라면 소연이가 카드 가져감
    if(!do_gnd.empty() && !su_gnd.empty() && do_gnd.back()+su_gnd.back() == 5){
        while(do_gnd.size()){
            su_card.push_front(do_gnd.front()); //상대방 것 가져가기
            do_gnd.pop_front();
        }
        while(su_gnd.size()){
            su_card.push_front(su_gnd.front()); //자신의 것 가져가기
            su_gnd.pop_front();
        }
    }
    
    //한쪽 그라운드에서 숫자 5 카드가 나오면 도도가 카드 가져감
    if((!do_gnd.empty() && do_gnd.back() == 5) || (!su_card.empty() && su_gnd.back() == 5)){
        while(su_gnd.size()){
            do_card.push_front(su_gnd.front()); //상대방 것 가져가기
            su_gnd.pop_front();
        }
        while(do_gnd.size()){
            do_card.push_front(do_gnd.front()); //자신의 것 가져가기
            do_gnd.pop_front();
        }
    }
}

void HalliGalli(){
    while(true){
        if(!do_card.empty()){
            do_gnd.push_back(do_card.back());
            do_card.pop_back();
        }
        //덱이 비는 순간 바로 상대의 승리
        if(do_card.empty()){
            cout << "su";
        }
        //카드 가져가는 사람 알아내기
        TakeCardCheck();
        m--;
        if(m==0) break;
        
        if(!su_card.empty()){
            su_gnd.push_back(su_card.back());
            su_card.pop_back();
        }
        //덱이 비는 순간 바로 상대의 승리
        if(su_card.empty()){
            cout << "do";
        }
        //카드 가져가는 사람 알아내기
        TakeCardCheck();
        m--;
        if(m==0) break;
    }
    if(do_card.size() == su_card.size()){
        cout << "dosu";
    }
    else if(do_card.size() < su_card.size()){
        cout << "su";
    }
    else {
        cout << "do";
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m; //카드의 갯수, 게임 진행횟수
    
    //도도와 수연의 카드 저장
    for(int i=0;i<n;i++){
        int do_in, su_in;
        cin >> do_in >> su_in;
        do_card.push_back(do_in);
        su_card.push_back(su_in);
    }
        
    HalliGalli();
}