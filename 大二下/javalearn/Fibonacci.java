
public class Fibonacci {
    public static void main (String [] args) {
        int[] Fibonacci = new int[20];
        Fibonacci[0] = 1;
        Fibonacci[1] = 1;

        for (int i = 2; i < 20; i++) {
            Fibonacci[i] = Fibonacci[i-1] + Fibonacci[i-2];
        }

        //System.out.println(Arrays.toString(Fibonacci));
    }
}