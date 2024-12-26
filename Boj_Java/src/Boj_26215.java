import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Boj_26215 {
    public static void main(String[] args) throws NumberFormatException, IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	
    	int ans = 0;
    	int n = Integer.parseInt(br.readLine());
    	int[] arr = new int[n];
    	
    	StringTokenizer st = new StringTokenizer(br.readLine());
    	for (int i = 0; i < n; i++) {
    	    arr[i] = Integer.parseInt(st.nextToken());
    	}
    	
    	while (ans <= 1440) {
    		Arrays.sort(arr);
    		if (arr[n-1] == 0) break;
    		ans++;
    		arr[n-1]--;
    		for (int i = n - 2; i >= 0; i--) {
    			if (arr[i] > 0) {
    				arr[i]--;
    				break;
    			}
    		}
    	}
    	if (ans > 1440) ans = -1;
    	System.out.println(ans);
    }
}