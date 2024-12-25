import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Boj_2780 {
    public static void main(String[] args) throws NumberFormatException, IOException {
    	final int MOD = 1234567;
    	int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
    	int arr[][] = {
    			{1, 2, 3},
    			{4, 5, 6},
    			{7, 8, 9},
    			{0, 0, 0}
    	};
    	
    	int dp[][] = new int[10][1001];
    	for (int i = 0; i < 10; i++) {
    		dp[i][1] = 1;
    	}
    	for (int i = 2; i < 1001; i++) {
     		for (int x = 0; x < 4; x++) {
    			for (int y = 0; y < 3; y++) {
    				if (x == 3 && y > 0) continue;
    				int cur = arr[x][y];
    				for (int k = 0; k < 4; k++) {
    					int nx = x + dx[k];
    					int ny = y + dy[k];
    					if (nx < 0 || nx >= 4 || ny < 0 || ny >= 3) continue;
    					if (nx == 3 && ny > 0) continue;
    					int nxt = arr[nx][ny];
    					dp[cur][i] = (dp[cur][i] + dp[nxt][i - 1]) % MOD;
    				}
    			}
    		}
    	}
    	
     	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
     	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    	int t = Integer.parseInt(br.readLine());
    	
    	while (t > 0) {
    		int n = Integer.parseInt(br.readLine());
    		int sum = 0;
    		
    		for (int i = 0; i < 10; i++) {
    			sum = (sum + dp[i][n]) % MOD;
    		}
    		bw.write(sum + "\n");
    		t--;
    	}
    	bw.flush();
    	bw.close();
    	br.close();
    }
}