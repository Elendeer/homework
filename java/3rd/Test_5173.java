/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-30 23:59:35
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-31 00:10:13
 * @Description  :
*********************************************/
public class Test_5173 {
    public static void main(String[] args) {
        String A = "want you to know one thing";
        int count_o = 0,count_n = 0;

        char [] c = A.toCharArray();

        for (int i = 0; i < A.length(); ++ i ){
            if (c[i] == 'o') ++ count_o;
            else if (c[i] == 'n') ++ count_n;
        }

        System.out.println("o : "+count_o);
        System.out.println("n : "+count_n);
    }
}
