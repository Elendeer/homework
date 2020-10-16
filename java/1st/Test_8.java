import java.util.Scanner;

public class Test_2 {
	public static void main (String [] args) {
		Scanner s = new Scanner(System.in);

		int num = s.nextInt();
		int nnum = 0;
		while (num != 0) {
			nnum = nnum * 10 + num % 10;
			num /= 10;
		}

		System.out.println(nnum);

		s.close();
	}
}
