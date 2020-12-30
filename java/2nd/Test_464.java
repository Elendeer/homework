/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-30 23:10:16
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-30 23:48:30
 * @Description  :
*********************************************/
public class Test_464 {
    public static void main(String[] args) {
        int [] a = {1, 2, 3, 5, 12, 4};

        int sum = 0;
        for (int i = 0; i < 6; ++ i ) {
            sum += a[i];
        }
        System.out.println("sum : " + sum);

        int min = a[0];
        for (int i = 0; i < 6; ++ i ) {
            min = Math.min(min, a[i]);
        }
        System.out.println("min : " + min);

        int max = a[0];
        for (int i = 0; i < 6; ++ i ) {
            max = Math.max(max, a[i]);
        }
        System.out.println("max : " + max);



    }
}
