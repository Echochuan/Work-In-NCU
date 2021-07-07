package exam;

        /*
            时间不够，总结一下
            将time修改为将多次run后得出的面积与体积一同输出存入数组里，然后在数组里将他们逆序排位，最后输出即可完成目标B。
            每run一次都会新增两个对象，从而达到随机生成不同数目的对象的目标
            由于界定了新增对象的基础值为0，所以不会出现负数的情况
         */

public class exam3 {
    public static class GemometricObject {
        String frColor;
        String bgColor;
        boolean isFilled;
        int numberofCreatedObject;

        GemometricObject() {
            frColor = "black";
            bgColor = "white";
            isFilled = false;
            numberofCreatedObject = 0;
        }

        GemometricObject(String f, String b, int n) {
            frColor = f;
            bgColor = b;
            isFilled = false;
            numberofCreatedObject = n;
        }

        void setFr(String fr) {
            frColor = fr;
            isFilled = true;
        }

        void setBg(String bg) {
            bgColor = bg;
            isFilled = true;
        }

        void setFi(boolean a) {
            isFilled = a;
        }

        void setNum(int a) {
            numberofCreatedObject = a;
            isFilled = true;
        }

        String getFr() {
            return frColor;
        }

        String getBg() {
            return bgColor;
        }

        boolean getFi() {
            return isFilled;
        }

        int getNum() {
            return numberofCreatedObject;
        }

        public double GetArea() {return 0;}

        public double getPerimeter() {return 0;}
    }

    public static class Circle extends GemometricObject {
        private double radius;

        public Circle(double r) {
            super();
            radius = r;
        }

        public double GetArea() {
            return Math.PI * radius * radius;
        }

        public double GetPerimeter() {
            return 2 * Math.PI * radius;
        }
    }

    public static class Rectangle extends GemometricObject {
        private double length,width;

        public Rectangle(double l, double w) {
            super();
            length = l;
            width = w;
        }

        public double GetArea() {
            return length * width;
        }

        public double GetPerimeter() {
            return 2 * (length + width);
        }
    }

    public static class Cylinder {
        double height;

        Cylinder(double h) {
            height = h;
        }

        public double GetArea(Circle c) {
            return c.GetArea() * 2 + c.getPerimeter() * height;
        }

        public double GetPerimeter(Circle c) {
            return c.GetArea() * height;
        }

        public void display(Circle c) {
            System.out.println("圆柱体的高为 "+ height + " 底面半径为 " +c.radius +" 背景色为 " +c.getBg() + " 前景色为 "
                    + c.getFr() +  " 是否修改参数： " +c.getFi());
        }
    }

    public static class Cuboid {
        double height;

        Cuboid(double h) {
            height = h;
        }

        public double GetArea(Rectangle r) {
            return 2 * (r.length * r.width + r.length * height + r.width * height);
        }

        public double GetPerimeter(Rectangle r) {
            return r.length * r.width * height;
        }

        public void display(Rectangle r) {
            System.out.println( " 长方体的高为  " +height + " 宽为 " + r.width +  " 长为 " +r.length +  " 背景色为 "
                    +r.getBg() + " 前景色为 " + r.getFr() +  " 是否修改参数： " +r.getFi());
        }
    }

    public static void time(int i) {
        int count = 0;
        while(i > 0) {
            run(count);
            i--;
        }

    }

    public static void run(int t) {
        String[] color = {"red", "blue", "yellow","black"};
        int n = (int)(Math.random() * 3 + 1);
        int m = (int)(Math.random() * 3 + 1);
        double r = (int)(Math.random() * 19 +1);
        double l = (int)(Math.random() * 19 +1);
        double w = (int)(Math.random() * 19 +1);
        double h = (int)(Math.random() * 19 +1);

        Circle c = new Circle(r);
        c.setBg(color[n]);
        c.setFr(color[m]);
        Rectangle re = new Rectangle(l,w);
        re.setBg(color[n]);
        re.setFr(color[m]);
        Cylinder cylinder = new Cylinder(h);
        Cuboid cuboid = new Cuboid(h);

        cylinder.display(c);
        cuboid.display(re);

        double p1 = cylinder.GetPerimeter(c);
        double a1 = cylinder.GetArea(c);
        double p2 = cuboid.GetPerimeter(re);
        double a2 = cuboid.GetArea(re);

        System.out.println("各图形的体积为：");
        if (p1 >= p2) {
            System.out.println(p2 + " " + p1);
        }
        else{
            System.out.println(p1+ " " + p2);
        }

        System.out.println("各图形的面积为：");
        if (a1 >= a2) {
            System.out.println(a2 + " " + a1);
        }
        else{
            System.out.println(a1+ " " + a2);
        }

        t = t + 2;
        System.out.println("成功创建对象的个数为" + t);
    }

    public static void main(String[] args) {

        int i = (int)(Math.random() * 2 + 1);
        time(i);
    }
}
