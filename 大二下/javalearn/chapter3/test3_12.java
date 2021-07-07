package chapter3;

/*
    回文数字
 */

import java.util.Scanner;

public class test3_12 {
    public static void main(String[] args) {
        System.out.print("Please enter a three-digit integer: ");

        Scanner input = new Scanner(System.in);

        int num = input.nextInt();

        //接下来提取他们的百位和个位，判断是否相同，如果相同，则是回文数。

        int bai = num / 100;
        int ge = num % 10;

        if (bai == ge) {
            System.out.println(num + " is a palindrome");
        }
        else {
            System.out.println(num + " is not a palindrome");
        }
    }
}
