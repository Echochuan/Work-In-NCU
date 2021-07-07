package chapter2;

/*
    求一个整数各位数的和
 */

import java.util.Scanner;

public class test2_6 {
    public static void main(String[] args) {
        System.out.print("Enter a number between 0 and 1000: ");
        Scanner input = new Scanner(System.in);

        int a = input.nextInt();

        //获取这个数的百位
        int bai = a / 100;
        //获取这个数的十位
        int shi = a % 100 / 10;
        //获取这个数的个位
        int ge = a % 10;

        int sum = bai + shi + ge;
        System.out.println("The sum of the digits is " + sum);

    }
}
