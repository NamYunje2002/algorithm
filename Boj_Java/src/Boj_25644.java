import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Boj_25644 {
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int arr[] = new int[n];
		long dp[] = new long[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		long ans = 0;
		for (int i = 1; i < n; i++) {
			dp[i] = Math.max(0, arr[i] - arr[i - 1] + dp[i - 1]);
			ans = Math.max(ans, dp[i]);
		}
		System.out.println(ans);
	}
}