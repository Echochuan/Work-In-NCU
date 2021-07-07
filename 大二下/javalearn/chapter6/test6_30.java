package chapter6;

public class test6_30 {

    public static int[] roll() {
        int a = (int)(Math.random()*6)+1;
        int b = (int)(Math.random()*6)+1;

        int[] arr = new int[2];
        arr[0] = a;
        arr[1] = b;

        return arr;
    }

    public static void main (String [] args) {
        int[] array = new int[2];
        array = roll();
        int a = array[0];
        int b = array[1];

        switch (a+b) {
            case 2:

            case 3:

            case 12:
                System.out.println("you rolled " + a + " + " + b + " = " + (a+b));
                System.out.println("you lose");
                break;

            case 7:

            case 11:
                System.out.println("you rolled " + a + " + " + b + " = " + (a+b));
                System.out.println("you win");
                break;

            default:

                System.out.println("you rolled " + a + " + " + b + " = " + (a+b));
                System.out.println("point is " + (a + b));

                int c = roll()[0];
                int d = roll()[1];

                while (c + d != 7 && c + d != a + b) {
                    c = roll()[0];
                    d = roll()[1];
                }

                if (c + d == 7) {
                    System.out.println("you rolled " + c + " + " + d + " = " + (c+d));
                    System.out.println("you lose");
                }
                else {
                    System.out.println("you rolled " + c + " + " + d + " = " + (c+d));
                    System.out.println("you win");
                }


        }
    }
}
