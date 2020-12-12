/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-10 23:10:59
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-10 23:42:20
 * @Description  :
*********************************************/

class Book {
    private String m_name;
    private int m_id;
    private int m_cost;
    private static int m_count = 0;

    public Book(String name){
        m_name = name;
        m_count++;
        m_id = m_count;
    }

    public void setName(String name) {
        m_name = name;
    }
    public void setId(int id) {
        m_id = id;
    }
    public void setCost(int cost) {
        m_cost = cost;
    }

    public static int getCount(){
        return m_count;
    }
    public String getName() {
        return m_name;
    }
    public int getId() {
        return m_id;
    }
    public int getCost() {
        return m_cost;
    }
}

public class Test_9 {
    public static void main(String [] args) {
        Book [] array = new Book [13];

        for (Book item : array) {
            item = new Book("book");
        }
        System.out.println("总册数：" + Book.getCount());
    }
}
