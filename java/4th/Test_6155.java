abstract class Shape {
	public abstract double area();
	public abstract double perimeter();
};

class Rectangle extends Shape {
	private double m_length;
	private double m_width;

	public Rectangle(double lenth, double width) {
		m_length = lenth;
		m_width = width;
	}
	public double area() {
		return m_length * m_width;
	}
	public double perimeter() {
		return (m_length + m_width) * 2;
	};
	public void print() {
		System.out.println("width : " + m_width);
		System.out.println("length : " + m_length);
		System.out.println("Area : " + this.area());
		System.out.println("Perimeter :" + this.perimeter());
	};
};

class Triangle extends Shape {
	private double m_a;
	private double m_b;
	private double m_c;

	public Triangle(double a, double b, double c) {
		m_a = a;
		m_b = b;
		m_c = c;
	}
	public double area() {
		double p = this.perimeter() / 2;
		return Math.sqrt(p * (p - m_a) * (p - m_b) * (p - m_c));
	}
	public double perimeter() {
		return m_a + m_b + m_c;
	};

	public void print() {
		System.out.println("a : " + m_a);
		System.out.println("b : " + m_b);
		System.out.println("c : " + m_c);
		System.out.println("Area : " + this.area());
		System.out.println("Perimeter :" + this.perimeter());
	};
};

class Circle  extends Shape {
	private double m_radius;
	private final double m_PI = 3.14159;

	public Circle(double radius) {
		m_radius = radius;
	};

	public double area() {
		return m_PI * m_radius * m_radius;
	}
	public double perimeter() {
		return 2 * m_PI * m_radius;
	};

	public void print() {
		System.out.println("radius : " + m_radius);
		System.out.println("Area : " + this.area());
		System.out.println("Perimeter :" + this.perimeter());
	};
};

public class Test_6155 {
	public static void main(String args[] ) {
		System.out.println("Rectangle:");
		Rectangle A = new Rectangle(2, 3);
		A.print();

		System.out.println("");

		System.out.println("Triangle:");
		Triangle B = new Triangle(3, 4, 5);
		B.print();

		System.out.println("");

		System.out.println("Circle:");
		Circle C = new Circle(1);
		C.print();
	};
};
