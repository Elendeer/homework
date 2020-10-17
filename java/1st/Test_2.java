import java.util.Scanner;

public class Test_1 {
	public static void main (String [] args) {
		Scanner s = new Scanner(System.in);

		System.out.println("Input i and j, and I will swap them.");

		System.out.print("i :");
		int i = s.nextInt();
		System.out.print("j :");
		int j = s.nextInt();

		int t = i;
		i = j;
		j = t;

		System.out.println("i : " + i + '\n' + "j : " + j);

		s.close();
	}
}
