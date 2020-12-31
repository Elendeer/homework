class Person {
	private String m_name;
	private String m_addr;
	private char m_sex;
	private int m_age;

	public Person(String name, String addr, char sex, int age) {
		m_name = name;
		m_addr = addr;
		m_sex = sex;
		m_age = age;
	};
	public Person(String name, String addr) {
		m_name = name;
		m_addr = addr;
		m_sex = 'n';
		m_age = 0;
	};
	public Person() {
		m_name = "none";
		m_addr = "none";
		m_sex = 'n';
		m_age = 0;
	};

	public void print() {
		System.out.println("name : " + m_name);
		System.out.println("addr : " + m_addr);
		System.out.println("sex : " + m_sex);
		System.out.println("age : " + m_age);
	}
};

class Student extends Person {
	private int m_math;
	private int m_english;
	
	public Student(String name, String addr, char sex, int age, int math, int english) {
		super(name, addr, sex, age);
		m_math = -1;
		m_english = -1;
	};
	public Student(String name, String addr) {
		super(name, addr);
		m_math = -1;
		m_english = -1;
	};

	public void print() {
		super.print();
		System.out.println("math : " + m_math);
		System.out.println("english : " + m_english);
	};
};

public class Test_6153 {
	public static void main(String args[] ) {
		Student A = new Student("name", "addr", 'm', 666, 0, 55);
		A.print();
	};
};
