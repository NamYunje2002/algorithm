import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Boj_4378 {

	public static void main(String[] args) throws IOException {
		String k = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String s = "";
		while ((s = br.readLine()) != null) {
			for (int i = 0; i < s.length(); i++) {
				char ch = s.charAt(i);
                if (ch == ' ') {
                    bw.write(' ');
                } else {
                    int idx = k.indexOf(ch);
                    bw.write(k.charAt(idx - 1));
                }
			}
			bw.write("\n");
		}
		bw.flush();
		bw.close();
		br.close();
	}

}
