#include <iostream>
#include <string>

using namespace std;

//유클리드 호제법 이용
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}


int main() {
    //문자열로 입력받음
    string n, m;
    getline(cin, n, ':');
    cin >> m;
    
    //문자열을 숫자로 변환
    int num_n = stoi(n);
    int num_m = stoi(m);
    
    int num_gcd = gcd(num_n, num_m);
    
    cout << num_n/num_gcd << ':' << num_m/num_gcd;
    
}