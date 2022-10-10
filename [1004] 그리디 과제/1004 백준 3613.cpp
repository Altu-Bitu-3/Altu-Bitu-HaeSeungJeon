#include <iostream>

using namespace std;

string turnCpp(string s){
    for(int i=0;i<s.length();i++){
        //Java 형식에 C++이 섞여있다면 틀린 형식
        if(s[i]=='_'){
            return "Error!";
        }
        //대문자를 확인하면 소문자로 바꾸고 그 앞에 _ 추가
        if(isupper(s[i])!=0){
            s[i]=tolower(s[i]);
            s.insert(i, "_");
        }
    }
    return s;
}

string turnJava(string s){
    for(int i=0;i<s.length();i++){
        //C++ 형식에 Java 형식이 섞여있다면 틀린 형식
        if(isupper(s[i])!=0){
            return "Error!";
        }
        //_ 문자를 확인하면 지우고 뒤의 문자를 대문자로 바꾸기
        if(s[i]=='_'){
            s.erase(i, 1);
            if(isupper(s[i])!=0 || s[i]=='_'){ //_ 두개 연속이거나, _ 뒤에 대문자인지 확인
                return "Error!";
            }
            s[i]=toupper(s[i]);
        }
    }
    return s;
}

string check(string s){
    //반례 출처: https://www.acmicpc.net/board/view/92676
    //반례를 참고하기 위해 이용했습니다.
    //첫글자가 대문자 또는 _이거나, 마지막 글자가 _면 틀린 형식
    if(isupper(s[0])!=0 || s[0]=='_' || s[s.length()-1]=='_'){
        return "Error!";
    }
    string ans;
    bool lowerflag;
    for(int i=0;i<s.length();i++){
        //java 형식이라면 c++로 변환
        if(isupper(s[i])!=0){
            lowerflag=0;
            ans = turnCpp(s);
            break;
        }
        //c++ 형식이라면 java로 변환
        if(s[i]=='_'){
            lowerflag=0;
            ans = turnJava(s);
            break;
        }
        lowerflag=1;
    }
    //java 형식에도 안 걸리고 c++ 형식에도 안 걸렸다
    //-> _ 문자와 대문자 없음 -> 전부 다 소문자 -> 그대로 리턴
    if(lowerflag==1){
        return s;
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << check(s);
}