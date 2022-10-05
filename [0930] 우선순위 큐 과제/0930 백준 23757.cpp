#include <iostream>
#include <queue>

using namespace std;

int checkSatisfied(int m, priority_queue<int> &present, queue<int> &child){
    for(int i=0;i<m;i++){
        if(present.top()>=child.front()){ //만약 상자의 선물 수가 요구보다 많다면
            present.push(present.top()-child.front()); //아이의 요구만큼 빼 주기
            present.pop();
            child.pop();
        } else{ //만약 상자의 선물 수가 요구보다 적다면
            return 0; //선물 나누어주기 실패
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; 
    cin >> n >> m; //선물 상자의 수, 아이들의 수
    
    priority_queue<int> present;
    queue<int> child;
    
    //선물 저장
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        present.push(temp);
    }
        
    //아이들이 원하는 선물의 갯수 저장
    for(int i=0;i<m;i++){
        int temp;
        cin >> temp;
        child.push(temp);
    }

    cout << checkSatisfied(m, present, child);
    
}