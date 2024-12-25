import java.io.*;
import java.util.*;

public class Boj_21317 {
    public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] dp = new int[n + 1][2];
        int[][] jump = new int[n + 1][2];
        
        for (int i = 0; i <= n; i++) {
            dp[i][0] = dp[i][1] = 0x3f3f3f3f;
        }
        dp[1][0] = 0;
        
        for (int i = 1; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            jump[i][0] = Integer.parseInt(st.nextToken());
            jump[i][1] = Integer.parseInt(st.nextToken());
        }
        int k = Integer.parseInt(br.readLine());
        
        for (int i = 2; i <= n; i++) {
            if (i - 1 >= 1) {
                dp[i][0] = Math.min(dp[i][0], dp[i - 1][0] + jump[i - 1][0]);
            }
            if (i - 2 >= 1) {
                dp[i][0] = Math.min(dp[i][0], dp[i - 2][0] + jump[i - 2][1]);
            }
            
            if (i - 3 >= 1) {
            	dp[i][1] = Math.min(dp[i][1], dp[i - 1][1] + jump[i - 1][0]);
            	dp[i][1] = Math.min(dp[i][1], dp[i - 2][1] + jump[i - 2][1]);
            	dp[i][1] = Math.min(dp[i][1], dp[i - 3][0] + k);
            }
        }
        System.out.println(Math.min(dp[n][0], dp[n][1]));
    }
}