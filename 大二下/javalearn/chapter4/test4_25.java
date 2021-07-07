package chapter4;

/*
    生成车牌号码
 */

import java.util.Random;

public class test4_25 {
    public static void main(String[] args) {
        Random rand = new Random();
        for (int i = 0; i < 3; i++) {
            int index = rand.nextInt(26);
            System.out.print((char) (index + 65));
        }
        System.out.print((int) (Math.random() * 9000) + 1000);
    }
}
