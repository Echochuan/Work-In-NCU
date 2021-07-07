package chapter5;

/*
    重复加法运算
 */

import java.util.Scanner;

public class test5_2 {
    public static void main(String[] args) {
        final int NUMBER_OF_QUESTIONS = 10;
        int correctCount = 0;
        int count = 0;
        long startTime = System.currentTimeMillis();
        String output = " ";
        Scanner input = new Scanner(System.in);

        while (count < NUMBER_OF_QUESTIONS) {
            int number1 = (int)(Math.random() * 15);
            int number2 = (int)(Math.random() * 15);

            System.out.print(number1 + " + " + number2 + " = ");
            int answer = input.nextInt();

            if (number1 + number2 == answer) {
                System.out.println("yes, you are right");
                correctCount++;
            }
            else {
                System.out.println("No, you are wrong");
            }

            count++;
        }

        long endTime = System.currentTimeMillis();
        long time = endTime - startTime;

        System.out.println("回答正确的个数为 " + correctCount + " 回答花费的时间是 " + time / 1000 + "s");
    }
}
