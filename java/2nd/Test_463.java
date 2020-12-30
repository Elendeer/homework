/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-30 23:10:16
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-30 23:38:41
 * @Description  :
*********************************************/

public class Test_463 {
    public static void main(String[] args) {
        int [] oldArr = {1, 3, 4, 0, 0, 6, 0, 5, 4, 7, 6, 7, 0, 5};

        int count = 0;
        for (int i = 0; i <= 13; ++ i ) {
            if (oldArr[i] != 0 ) {
                ++ count;
            }
        }

        int [] newArr = new int [count];
        int j = 0;

        for (int i = 0; i <= 13; ++ i ) {
            if (oldArr[i] != 0 ) {
                newArr[j ++ ] = oldArr[i];
            }
        }

        for (int i = 0; i < count; ++ i ) {
            System.out.print(newArr[i] + " ");
        }


    }
}
