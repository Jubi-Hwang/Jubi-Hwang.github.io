// 9660. 번호 붙이기 (백트래킹 + 가지치기)

#include <bits/stdc++.h>
using namespace std;

// 변수 선언부
int t; // 테스트 케이스의 수 T
int n; // N명의 사람, 1<=n<=5,000
bool isUsed[5002]; // 사용된 번호를 저장하는 배열
int hateNum[5002]; // 각 사람이 싫어하는 수를 저장하는 배열
int temp, result;

void bt(int k) { // k는 번호 부여가 완료된 사람의 수
    if(k == n) {
        temp += 1;
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(i == hateNum[k+1]) { // 싫어하는 수인 경우
            continue;
        } 
        if(!isUsed[i]) { // 사용되지 않은 번호인 경우
                isUsed[i] = true;
                bt(k+1);
                isUsed[i] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./input.txt", "r", stdin);

    cin >> t;
    for(int i = 1; i <= t; i++) { // TC만큼 반복
        // 변수 초기화
        fill(isUsed+1, isUsed+n+1, false);
        fill(hateNum+1, hateNum+n+1, 0);
        temp = 0;

        cin >> n;
        for(int j = 1; j <= n; j++) {
            cin >> hateNum[j];
        }
        
        // 결과 출력부
        // 1,000,000,007로 나눈 나머지를 출력하도록 한다.
        bt(0);
        result = temp % 1000000007;
        cout << '#' << i << ' ' << result << '\n';
    }
}
