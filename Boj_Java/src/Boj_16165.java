import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Boj_16165 {
    public static void main(String[] args) throws NumberFormatException, IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringTokenizer s = new StringTokenizer(br.readLine());
    	
    	int n = Integer.parseInt(s.nextToken());
    	int m = Integer.parseInt(s.nextToken());
    	
    	HashMap<String, String> memberToGroup = new HashMap<String, String>();
    	HashMap<String, String[]> groupToMember = new HashMap<String, String[]>();
    	
    	for (int i = 0; i < n; i++) {
    		String groupName = br.readLine();
    		int memberCnt = Integer.parseInt(br.readLine());
    		String memberArr[] = new String[memberCnt];
    		
    		for (int j = 0; j < memberCnt; j++) {
    			String memberName = br.readLine();
    			memberToGroup.put(memberName, groupName);
    			memberArr[j] = memberName;
    		}
    		Arrays.sort(memberArr);
    		groupToMember.put(groupName, memberArr);
    	}
    	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    	
    	for (int i = 0; i < m; i++) {
    		String name = br.readLine();
    		int k = Integer.parseInt(br.readLine());
    		if (k == 0) {
    			String arr[] = groupToMember.get(name);
    			for (int j = 0; j < arr.length; j++) {
    				bw.write(arr[j] + "\n");
    			}
    		} else {
    			bw.write(memberToGroup.get(name) + "\n");
    		}
    	}
    	bw.flush();
    	bw.close();
    	br.close();
    }
}