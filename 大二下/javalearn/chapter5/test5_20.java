package chapter5;

public class test5_20 {

    public static boolean isPrime(int num) {
        if (num <= 3) {
            return num > 1;
        }
        // 不在6的倍数两侧的一定不是质数
        if (num % 6 != 1 && num % 6 != 5) {
            return false;
        }
        int sqrt = (int) Math.sqrt(num);
        for (int i = 5; i <= sqrt; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) {
                return false;
            }
        }
        return true;
}
    public static void main(String[] args) {
        int n = 0;

        for(int i = 2; i < 1000; i ++) {
            if(isPrime(i)){
                n++;
                if (n % 8 == 0) {
                    System.out.println(i);
                }
                else {
                    System.out.print(i + " ");
                }
            }
        }
    }
}
