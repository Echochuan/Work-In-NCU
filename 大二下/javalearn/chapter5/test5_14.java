package chapter5;

/*
    计算最大公约数
 */

import java.util.Scanner;

public class test5_14 {
    public static void main(String[] args) {
        System.out.print("请输入两个正整数： ");
        Scanner input = new Scanner(System.in);

        int n1 = input.nextInt();
        int n2 = input.nextInt();

        System.out.println("开始计算...");

        int d = 0;
        int end = 0;

        if (n1 < n2) {
            d = n1;
            n1 = n2;
            n2 = d;
        }
        else {
            d = n2;
        }

        while (end == 0) {
            int sub = n1 - n2;
            end = (d - sub) == d ? 1 : 0;
            d--;
        }

        System.out.println("最大公约数为 " + d);
    }
}
