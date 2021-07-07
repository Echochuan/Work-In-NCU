package chapter9;

public class test9_8 {

    static class Fan {

        private int speed;  //设置默认值为SLOW
        private boolean on;    //默认值为false
        private double radius;  //默认值为5
        private String color;  //默认值为blue

        int SLOW = 1;
        int MEDIUM = 2;
        int FAST = 3;

        Fan() {
            speed = SLOW;
            on = false;
            radius = 5;
            color = "blue";
        }

        Fan(int newSpeed, boolean newOn, double newRadius, String newColor) {
            speed = newSpeed;
            on = newOn;
            radius = newRadius;
            color = newColor;
        }

        public String toString() {
            if (on = true) {
                return "速度为 " + speed + " 颜色为 " + color + " 半径为 " + radius;
            }
            else if (on = false) {
                return " fan is off " + " 颜色为 " + color + " 半径为 " + radius;
            }
            else {
                return " ";
            }
        }
    }

    public static void main(String[] args) {

        int SLOW = 1;
        int MEDIUM = 2;
        int FAST = 3;

        Fan fan1 = new Fan(3, true, 10, "yellow");
        Fan fan2 = new Fan(2, false, 5, "blue");

        System.out.println(fan1.toString());
        System.out.println(fan2.toString());
    }
}
