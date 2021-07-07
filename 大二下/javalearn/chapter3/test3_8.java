package chapter3;

/*
    对三个整数排序
 */

import java.util.Scanner;

public class test3_8 {
    public static void main(String[] args) {
        System.out.print("Please enter three numbers: ");

        Scanner input = new Scanner(System.in);
        int a = input.nextInt();
        int b = input.nextInt();
        int c = input.nextInt();
        int mid = 0;

        if (a > b) {
            mid = b;
            b = a;
            a = mid;
            //经过这次排序之后 a 小于 b
            if ( b > c ) {
                mid = c;
                c = b;
                b = mid;
            }
        }
        else {
            if (b > c) {
                mid = c;
                c = b;
                b = mid;
                //经过这次变化之后 b 小于 c
                if ( a > b ) {
                    mid = b;
                    b = a;
                    a = mid;
                }
            }
        }
        System.out.print(a + " " + b + " " + c);
    }
}
