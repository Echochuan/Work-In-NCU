package chapter3;

/*
    游戏：将三个数相加
 */

import java.util.Scanner;

public class test3_2 {
    public static void main(String[] args) {
        int number1 = (int)(System.currentTimeMillis() % 10);
        int number2 = (int)(System.currentTimeMillis() / 10 % 10);
        int number3 = (int)(System.currentTimeMillis() / 100 % 10);

        Scanner input = new Scanner(System.in);

        System.out.println(
                "what is " + number1 +" + " + number2 + " + " + number3 + " ? "
        );

        int answer = input.nextInt();

        System.out.println(
                number1 + " + " + number2 + " + " + number3 + " = " + answer + " is " +
                        (number1 + number2 + number3 == answer)
        );
    }
}
