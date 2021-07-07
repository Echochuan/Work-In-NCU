package chapter10;

public class test10_4 {

    static class MyPoint {
        double x;
        double y;

        MyPoint() {
            x = 0;
            y = 0;
        }

        MyPoint(double a, double b) {
            x = a;
            y = b;
        }

        double distance (double a, double b, MyPoint c) {
            return Math.pow((Math.pow((a - c.x), 2) + Math.pow((b - c.y), 2)), 0.5);
        }

        double distance (double a, double b, double c, double d) {
            return Math.pow((Math.pow((a - c), 2) + Math.pow((b - d), 2)), 0.5);
        }

        static double distance (MyPoint a, MyPoint b) {
            return Math.pow((Math.pow((a.x - b.x), 2) + Math.pow((a.y - b.y), 2)), 0.5);
        }
    }

    public static void main (String [] args) {
        MyPoint a = new MyPoint();
        MyPoint b = new MyPoint(10, 30.5);

        double d = MyPoint.distance(a, b);
        System.out.println("他们之间的距离为 " + d);
    }
}
