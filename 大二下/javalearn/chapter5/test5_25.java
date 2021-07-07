package chapter5;

public class test5_25 {
    public static void main(String[] args) {
        double sum = 0.0;
        int n = 10000;

        do {
            for (int i = 1; i < n; i++) {
                sum = sum + (Math.pow(-1, i+1) / (2 * i - 1));
            }
            System.out.println("此时的值为 " + 4 * sum);
            n = n + 10000;
            sum = 0.0;
        }
        while (n != 100000);
    }
}
