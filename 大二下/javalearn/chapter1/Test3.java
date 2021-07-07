// 用于输出8+88+888...等前十项的和
// public class Test3 {
//     public static void main (String[] args) {
//         double a=8;
//         double b=8;
//         int i=1;
//         double power;
//         do{
//             power = Math.pow(10,i);
//             b = 8 * power + b;
//             a = a + b;
//             i = i + 1;
//         }while( i < 10 );
//         System.out.println(a);
//     }
// }

// 用于计算自然数逐次相加之和小于8888的最大正整数
public class Test3 {
    public static void main (String[] args) {
        int i = 1;
        int n = 2;
        do{
            i = i + n;
            n = n + 1;
        }while( i < 8888 );
        System.out.println( n-1 );
    }
}