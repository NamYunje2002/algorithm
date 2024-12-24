// https://www.acmicpc.net/problem/13460

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m, rx, ry, bx, by, ans = -1;
char board[12][12];
queue<tuple<pair<int, int>, pair<int, int>, int>> q;

// 위로 굴리기
pair<int, int> up(pair<int, int> cur, pair<int, int> block) {
	while (1) {
		// 벽에 닿거나 다른 공에 닿으면 종료.
		if (board[cur.X - 1][cur.Y] == '#' || cur.X - 1 == block.X && cur.Y == block.Y) break;
		// 구멍에 빠지면 {-1, -1} 반환
		else if (board[cur.X - 1][cur.Y] == 'O') return { -1,-1 };
		cur.X--;
	}
	return { cur.X, cur.Y };
}


// 밑으로 굴리기
pair<int, int> down(pair<int, int> cur, pair<int, int> block) {
	while (1) {
		if (board[cur.X + 1][cur.Y] == '#' || cur.X + 1 == block.X && cur.Y == block.Y) break;
		else if (board[cur.X + 1][cur.Y] == 'O') return { -1,-1 };
		cur.X++;
	}
	return { cur.X,cur.Y };
}


// 왼쪽으로 굴리기
pair<int, int> left(pair<int, int> cur, pair<int, int> block) {
	while(1) {
		if (board[cur.X][cur.Y - 1] == '#' || cur.X == block.X && cur.Y - 1 == block.Y) break;
		else if (board[cur.X][cur.Y - 1] == 'O') return { -1,-1 };
		cur.Y--;
	}
	return { cur.X,cur.Y };
}


// 오른쪽으로 굴리기
pair<int, int> right(pair<int, int> cur, pair<int, int> block) {
	while (1) {
		if (board[cur.X][cur.Y + 1] == '#' || cur.X == block.X && cur.Y + 1 == block.Y) break;
		else if (board[cur.X][cur.Y + 1] == 'O') return { -1,-1 };
		cur.Y++;
	}
	return { cur.X,cur.Y };
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R') {
				rx = i;
				ry = j;
			} else if (board[i][j] == 'B') {
				bx = i;
				by = j;
			}
		}
	}
	
	// 빨간 공 좌표, 파란 공 좌표, 이동 횟수를 tuple로 만들어서 q에 넣음
	q.push(make_tuple(make_pair( rx, ry ), make_pair( bx, by ), 1));
	while (!q.empty()) {
		tuple<pair<int, int>, pair<int, int>, int > cur = q.front(); q.pop();
		pair<int, int> red = get<0>(cur);
		pair<int, int> blue = get<1>(cur);
		int cnt = get<2>(cur);
		if (cnt > 10) continue;


		/* 위로 굴리기 */
		// 빨간 공이 파란 공보다 위에 있는 경우
		if (red.X < blue.X) {
			// 빨간 공 먼저 이동하고, 파란 공 이동
			pair<int, int> nxtRed = up(red, blue);
			pair<int, int> nxtBlue = up(blue, nxtRed);
			if (nxtRed.X == -1 && nxtBlue.X != -1) {
				ans = cnt;
				break;
			}
			if (nxtRed.X != -1 && nxtBlue.X != -1)
				if(red != nxtRed || blue != nxtBlue)
					q.push(make_tuple(nxtRed, nxtBlue, cnt + 1));
		}
		// 파란 공이 빨간 공보다 위에 있는 경우
		else {
			// 파란 공 먼저 이동하고, 빨간 공 이동
			pair<int, int> nxtBlue = up(blue, red);
			pair<int, int> nxtRed = up(red, nxtBlue);
			if (nxtRed.X == -1 && nxtBlue.X != -1) {
				ans = cnt;
				break;
			}
			if (nxtRed.X != -1 && nxtBlue.X != -1)
				if(red != nxtRed || blue != nxtBlue)
					q.push(make_tuple(nxtRed, nxtBlue, cnt + 1));
		}


		/* 밑으로 굴리기 */
		if (red.X > blue.X) {
			pair<int, int> nxtRed = down(red, blue);
			pair<int, int> nxtBlue = down(blue, nxtRed);
			if (nxtRed.X == -1 && nxtBlue.X != -1) {
				ans = cnt;
				break;
			}
			if (nxtRed.X != -1 && nxtBlue.X != -1)
				if(red != nxtRed || blue != nxtBlue)
					q.push(make_tuple(nxtRed, nxtBlue, cnt + 1));
		}
		else {
			pair<int, int> nxtBlue = down(blue, red);
			pair<int, int> nxtRed = down(red, nxtBlue);
			if (nxtRed.X == -1 && nxtBlue.X != -1) {
				ans = cnt;
				break;
			}
			if (nxtRed.X != -1 && nxtBlue.X != -1)
				if(red != nxtRed || blue != nxtBlue)
					q.push(make_tuple(nxtRed, nxtBlue, cnt + 1));
		}


		/* 왼쪽으로 굴리기 */
		if (red.Y < blue.Y) {
			pair<int, int> nxtRed = left(red, blue);
			pair<int, int> nxtBlue = left(blue, nxtRed);
			if (nxtRed.X == -1 && nxtBlue.X != -1) {
				ans = cnt;
				break;
			}
			if (nxtRed.X != -1 && nxtBlue.X != -1)
				if(red != nxtRed || blue != nxtBlue)
					q.push(make_tuple(nxtRed, nxtBlue, cnt + 1));
		}
		else {
			pair<int, int> nxtBlue = left(blue, red);
			pair<int, int> nxtRed = left(red, nxtBlue);
			if (nxtRed.X == -1 && nxtBlue.X != -1) {
				ans = cnt;
				break;
			}
			if (nxtRed.X != -1 && nxtBlue.X != -1)
				if(red != nxtRed || blue != nxtBlue)
					q.push(make_tuple(nxtRed, nxtBlue, cnt + 1));
		}


		/* 오른쪽으로 굴리기 */
		if (red.Y > blue.Y) {
			pair<int, int> nxtRed = right(red, blue);
			pair<int, int> nxtBlue = right(blue, nxtRed);
			if (nxtRed.X == -1 && nxtBlue.X != -1) {
				ans = cnt;
				break;
			}
			if (nxtRed.X != -1 && nxtBlue.X != -1)
				if(red != nxtRed || blue != nxtBlue)
					q.push(make_tuple(nxtRed, nxtBlue, cnt + 1));
		}
		else {
			pair<int, int> nxtBlue = right(blue, red);
			pair<int, int> nxtRed = right(red, nxtBlue);
			if (nxtRed.X == -1 && nxtBlue.X != -1) {
				ans = cnt;
				break;
			}
			if (nxtRed.X != -1 && nxtBlue.X != -1)
				if(red != nxtRed || blue != nxtBlue)
					q.push(make_tuple(nxtRed, nxtBlue, cnt + 1));
		}
	}
	cout << ans;
}
