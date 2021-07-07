package chapter6;

public class test6_8 {

    //Convert from Celsius to Fahrenheit
    public static double celsiusToFahrenheit(double celsius) {
        return (9.0 / 5) * celsius + 32;
    }

    //Convert from Fahrenheit to Celsius
    public static double fahrenheitToCelsius(double fahrenheit) {
        return (5.0 / 9) * (fahrenheit - 32);
    }

    public static void main (String [] args) {
        double c = 40.0;
        double f = 120.0;

        System.out.println("摄氏度       华氏度             华氏度         摄氏度");
        System.out.println("——————————————————————————————————————————————————");
        while (f >= 30.0) {

            double newC = celsiusToFahrenheit(c);
            double newF = fahrenheitToCelsius(f);

            System.out.print(c + "\t\t");
            System.out.printf("%.1f", newC);
            System.out.print("\t\t\t\t" + f + "\t\t");
            System.out.printf("%.2f", newF);
            System.out.println();

            c = c - 1.0;
            f = f - 10.0;
        }
    }
}
