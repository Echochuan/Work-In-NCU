package chapter10;

import java.util.ArrayList;
import java.util.Scanner;

public class test10_25 {
    public static ArrayList<String> split(String s, String regex) {
        ArrayList<String> arr= new ArrayList<String> ();
        int i = 0;
        int j = 0;

        while (i < s.length()) {
            if (s.substring(i, i + 1).matches(regex)) {
                if(i!=0)
                {
                    arr.add(s.substring(0,i));
                }
                j++;
                arr.add(s.substring(i,i+1));
                j++;
                s=s.substring(i+1, s.length());
            }
            else {
                i++;
            }
        }
        arr.add(s);
        return arr;
    }

    public static void main (String... args) {
        Scanner str = new Scanner(System.in);
        String s = str.next();

        System.out.println(split(s, "#"));
    }
}
