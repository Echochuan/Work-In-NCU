package exp_4;

public class MypointNum {
    static class Mypoint {
        double x;
        double y;

        Mypoint() {
            x = 0;
            y = 0;
        }

        Mypoint(double a, double b) {
            x = a;
            y = b;
        }

        double distance(double a, double b) {
            double d_2 = Math.pow((x - a), 2) + Math.pow((y - b), 2);
            double d = Math.pow(d_2, 0.5);
            return d;
        }


        static double distance(Mypoint a, Mypoint b){
            return Math.pow(Math.pow((a.x - b.x), 2) + Math.pow((a.y - b.y), 2), 0.5);
        }

    }

    public static void main(String[] args) {
        Mypoint a = new Mypoint(0, 0);
        Mypoint b = new Mypoint(10, 30.5);

        System.out.println("其距离为" + a.distance(a,b));
        System.out.println("其距离为" + b.distance(0,0));
    }
}
