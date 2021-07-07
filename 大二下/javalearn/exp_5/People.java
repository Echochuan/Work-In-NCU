package exp_5;

/*
    按照实验内容中提供的信息，依次创建不同的类，并编写新增的方法和重构父类的方法，最后依次调用运行即可。
 */

    public class People {
        protected double weight,height;
        public void speakHello() {
            System.out.println("您好");
        }
        public void averageHeight() {
            height=173;
            System.out.println("average height:"+height);
        }
        public void averageWeight() {
            weight=70;
            System.out.println("average weight:"+weight);
        }

        public static void main(String[] args) {
            ChinaPeople c = new ChinaPeople();
            AmericanPeople a = new AmericanPeople();
            BeijingPeople b = new BeijingPeople();

            c.speakHello();
            a.speakHello();
            b.speakHello();

            c.averageHeight();
            a.averageHeight();
            b.averageHeight();

            c.averageWeight();
            a.averageWeight();
            b.averageWeight();

            c.chinaGongfu();
            a.americanBoxing();
            b.beijingOpera();

        }
    }

    class ChinaPeople extends People {
        public ChinaPeople () {

        }

        public void chinaGongfu() {
            System.out.println("坐如钟、站如松、睡如弓");
        }

        public void speakHello() {
            System.out.println("您好");
        }

        public void averageHeight () {
            height = 168.78;
            System.out.println("中国人的平均身高：" + height + " 厘米");
        }

        public void averageWeight() {
            weight = 65.0;
            System.out.println("中国人的平均体重：" + weight + " 千克");
        }
    }

    class AmericanPeople extends People {
        public AmericanPeople() {}

        public void americanBoxing() {
            System.out.println("直拳、钩拳、组合拳");
        }

        public void speakHello() {
            System.out.println("how do you do");
        }

        public void averageHeight() {
            height = 176.0;
            System.out.println("American's average height: " + height + " cm");
        }

        public void averageWeight() {
            weight = 75.0;
            System.out.println("American's average weight: " + weight + " kg");
        }
    }

    class BeijingPeople extends People {
        public BeijingPeople() {}

        public void beijingOpera() {
            System.out.println("花脸、青衣、花旦和老生");
        }

        public void speakHello() {
            System.out.println("您好");
        }

        public void averageHeight() {
            height = 172.5;
            System.out.println("北京人的平均身高：" + height + " 厘米");
        }

        public void averageWeight() {
            weight = 70.0;
            System.out.println("北京人的平均体重：" + weight + "千克");
        }
    }

