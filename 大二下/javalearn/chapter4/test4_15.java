package chapter4;

import java.util.Scanner;

public class test4_15 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter a letter: ");

        char enter = input.next().charAt(0);
        enter = Character.toLowerCase(enter);

        int a = (int) enter;
        int b = 0;

        if ( a >= 97 && a <= 99) {
            b = 2;
        }
        else if (a >= 100 && a <= 102) {
            b = 3;
        }
        else if (a >= 103 && a <= 105) {
            b = 4;
        }
        else if (a >= 106 && a <= 108) {
            b = 5;
        }
        else if (a >=109 && a <= 111) {
            b = 6;
        }
        else if (a >= 112 && a <= 115) {
            b = 7;
        }
        else if (a >= 116 && a <= 118) {
            b = 8;
        }
        else if (a >= 119 && a <= 122) {
            b = 9;
        }
        else {
            System.out.println(enter + " is an invalid input");
        }

        System.out.println("The corresponding number is " + b);
    }
}
