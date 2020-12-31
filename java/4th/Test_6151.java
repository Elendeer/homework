interface ClassName {
	public abstract String getClassName();
};

class Company implements ClassName {
	private String m_name;

	public Company(String name) {
		m_name = name;
	};
	public String getClassName() {
		return m_name;
	};
};

public class Test_6151 {
	public static void main(String args[] ) {
		Company A = new Company("A");
		System.out.println(A.getClassName());
	};
};
