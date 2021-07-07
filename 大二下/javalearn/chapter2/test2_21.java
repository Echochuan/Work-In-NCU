package chapter2;

/*
    金融应用，计算未来投资回报
 */

import java.util.Scanner;

public class test2_21 {
    public static void main(String[] args) {
        System.out.print("Enter investment amount: ");

        Scanner input = new Scanner(System.in);
        double i = input.nextDouble();

        System.out.print("Enter annual interest rate in percentage: ");
        double rate = input.nextDouble();

        System.out.print("Enter number of years: ");
        int years = input.nextInt();

        double future = i * Math.pow((1 + rate * 0.01), years * 12);
        System.out.print("Future value is $" + future);
    }
}
