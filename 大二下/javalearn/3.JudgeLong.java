import java.util.Scanner;
class Text {
    public static void main(String[] args) {
        int cho = 1;
        long Max_num = Long.MAX_VALUE, n;
        String char_n;
        System.out.print("Enter an number for judge:");
        Scanner input = new Scanner(System.in);
        char_n = input.nextLine();
        try {
            n = Long.parseLong(char_n);
        }
        catch(NumberFormatException e) {
            cho = 0;
            System.out.println(char_n + "不在long长整数类型范围内");
        }
        finally {
            if(cho == 1) {
                System.out.println(char_n + "在long长整数类型范围内");
            }
        }
    }
}