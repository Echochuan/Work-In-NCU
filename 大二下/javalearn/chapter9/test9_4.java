package chapter9;

import java.util.Random;

public class test9_4 {
    public static void main(String[] args) {
        Random generator1 = new Random(1000);
        for (int i = 0; i < 50 ; i++) {
            System.out.print(generator1.nextInt(100) + " ");
        }
    }
}
