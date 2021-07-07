package chapter5;

/*
    计算将来的学费
 */

public class test5_7 {

    public static double add(double a, int year) {
        return a * Math.pow((1+0.05), year);
    }

    public static void main(String[] args) {

        double endSum = add(10000, 10);

        double sum = add(endSum, 1) + add(endSum,2) + add(endSum, 3) + add(endSum,4);

        System.out.println("十年后的学费为 " + endSum + " 。从现在开始的十年后算起，四年的总学费为 " + sum);
    }
}
