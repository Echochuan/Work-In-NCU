package chapter6;

import java.util.Scanner;

public class test6_20 {

    public static int countLetters(String s) {
        int n = 0;

        String[] arr = new String[s.length()];

        arr = s.split("");

        for (String value : arr) {
            if ((int) value.charAt(0) <= 122 && (int) value.charAt(0) >= 97) {
                n++;
            } else if ((int) value.charAt(0) <= 90 && (int) value.charAt(0) >= 65) {
                n++;
            }
        }

        return n;
    }

    public static void main (String [] args) {
        System.out.print("请输入需要计数的字符串： ");

        Scanner input = new Scanner(System.in);
        String str = input.next();

        System.out.println("该字符串中字母的数量为: " + countLetters(str));
    }
}
