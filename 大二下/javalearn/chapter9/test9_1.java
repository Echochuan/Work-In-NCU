package chapter9;

public class test9_1 {

    static class Rectangle {
        double width = 1;
        double height = 1;

        Rectangle() {
        }

        Rectangle(double newWidth, double newHeight) {
            width = newWidth;
            height = newHeight;
        }

        double getArea() {
            return width * height;
        }

        double getPerimeter() {
            return ( width + height ) * 2;
        }
    }

    public static void main(String[] args) {
        Rectangle rectangle1 = new Rectangle(4, 40);
        Rectangle rectangle2 = new Rectangle(3.5, 35.9);

        System.out.println("第一个矩形的宽为 " + rectangle1.width + " 高为 " + rectangle1.height + " 面积是 " + rectangle1.getArea() + " 周长为 " + rectangle1.getPerimeter());
        System.out.println("第二个矩形的宽为 " + rectangle2.width + " 高为 " + rectangle2.height + " 面积是 " + rectangle2.getArea() + " 周长为 " + rectangle2.getPerimeter());
    }
}
