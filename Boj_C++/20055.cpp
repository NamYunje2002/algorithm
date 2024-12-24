#include <bits/stdc++.h>
using namespace std;

/*
   arr : 각 칸의 내구도 배열 
   robot : 로봇이 올라가 있으면 1, 없으면 0을 저장하는 배열
*/
int ans, arr[202], robot[202];

int main() {
   ios::sync_with_stdio(0); cin.tie(0);
   int n, k; cin >> n >> k;
   for (int i = 1; i <= 2 * n; i++) cin >> arr[i]; // 각 칸의 내구도 입력
   int st = 1, en = n; // 올리는 위치, 내리는 위치 초기화

   while (1) {
      ans++; // 단계 1증가

      // 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전하는 과정
      st--; if(st == 0) st = 2*n; // 올리는 위치 회전
      en--; if(en == 0) en = 2*n; // 내리는 위치 회전
      
      // 로봇이 내리는 위치에 도달하면 즉시 제거
      if(robot[en]) robot[en] = 0;
      
      // 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동하는 과정
      int ten = en - 1;
      if(ten == 0) ten = 2*n;
      while(ten != en) {
         // 위치가 2*n일 경우만 예외처리
         if(ten == 2*n) {
            if(robot[2*n] && !robot[1] && arr[1] > 0) {
               robot[1] = 1;
               robot[2*n] = 0;
               arr[1]--;
            }
         }else {
            // 다음 칸 로봇 X, 다음 칸 내구도 0 이상, 현재 칸 로봇 O → 3가지 조건을 만족하면
            if(robot[ten] && !robot[ten+1] && arr[ten+1] > 0) {
               robot[ten+1] = 1; // 다음 칸으로 로봇 이동
               robot[ten] = 0; // 현재 칸 로봇 제거
               arr[ten+1]--; // 다음 칸 내구도 1 감소
            }
         }
         ten--;
         if(ten == 0) ten = 2*n;
      }

      // 로봇이 내리는 위치에 도달하면 즉시 제거
      if(robot[en]) robot[en] = 0;

      // 올리는 위치에 로봇이 없고 올리는 위치의 내구도가 0보다 크면 로봇 추가
      if(!robot[st] && arr[st] > 0) {
         arr[st]--; // 올리는 위치 내구도 1감소
         robot[st] = 1; // 올리는 위치에 로봇 추가
      }

      int cnt = 0;
      for (int i = 1; i <= 2 * n; i++) if (arr[i] < 1) cnt++; // 내구도가 0인 칸의 개수 카운트

      if (cnt >= k) break; // 내구도가 0인 칸의 개수가 K개 이상이라면 종료
   }
   cout << ans;
}