package chapter7;

/*
    输入整数列表，判断是否有四个连续且数值相同的数。
    如果有，则输出The list has consecutive fours.
    否则，输出The list has no consecutive fours
 */

import java.util.Scanner;

public class test7_30 {
    public static void main (String [] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter the number of values: ");
        int n = input.nextInt();

        int[] arr = new int[n];

        System.out.print("Enter the values: ");
        String str = input.next();

        String[] s = str.split(",");

        int count = 1;
        int end = 0;

        for (int i = 1; i < s.length; i++) {
            if (s[i].equals(s[i - 1])) {
                count++;
            }
            else {
                if (end <= count) {
                    end = count;
                }
                count = 1;
            }
        }

        if (end >= 4) {
            System.out.print("The list has consecutive.");
        }
        else {
            System.out.print("The list has no consecutive fours");
        }
    }
}
