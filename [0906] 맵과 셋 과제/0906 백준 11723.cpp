#include <iostream>
#include <cstring>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int m, num;
    cin >> m;
    bool arr[20]; //1부터 20까지의 원소의 유무를 저장할 bool 배열

    string str;
    
    for(int i=0;i<m;i++){
        
        cin >> str;
        if(str == "add"){ //add 연산이 들어오면 해당 원소가 존재한다고 표시
            cin >> num;
            arr[num-1] = true;
        }
        if(str == "remove"){ //remove 연산이 들어오면 해당 원소가 존재하지 않는다고 표시
            cin >> num;
            arr[num-1] = false;
        }
        if(str == "check"){ //check 연산이 들어오면 해당 원소가 존재하는지 확인
            cin >> num;
            cout << (arr[num-1] == true) ? 1 : 0;
            cout << '\n';
        }
        if(str == "toggle"){ //toggle 연산이 들어오면 해당 원소의 존재 유무를 바꾸기
            cin >> num;
            arr[num-1] = (arr[num-1] == true) ? false : true;
        }
        if(str == "all"){ //all 연산이 들어오면 전부 true로 초기화하기
            fill_n(arr, 20, true);
        }
        if(str == "empty"){
            fill_n(arr, 20, false); //empty 연산이 들어오면 전부 false 초기화하기
        }
    }
    return 0;
}