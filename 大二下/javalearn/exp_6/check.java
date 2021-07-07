package exp_6;

/*
    按照要求，分别建立各个类。
    对于未介绍的Goods类，需要包含构造方法，命名与取名的方法，判定是否危险的方法以及输出是否危险的方法。
    利用数组，将需要检查的内容放入数组里，依次进行检验。
    在Machine中，设定发现是danger时抛出错误，否则按要求输出。
    使用try结构，当检测到异常时，调用toShow方法输出结果，否则正常输出。
 */

public class check {

    public static class Goods {
        String name;
        boolean isDanger;

        Goods(boolean isDanger, String name){
            this.name = name;
            this.isDanger = isDanger;
        }

        public void setName(String name) {
            this.name = name;
        }

        public String getName() {
            return name;
        }

        public void setIsDanger(boolean b){
            isDanger = b;
        }

        public boolean isDanger(){
            return isDanger;
        }
    }


    static class DangerException extends Exception {
        void toShow() {
            System.out.print("危险品！");
        }
    }

    static class Machine {
        public void checkBag(Goods goods) throws DangerException {
            if(goods.isDanger()) {
                throw new DangerException();
            }
            else
                System.out.println(goods.getName()+"不是危险品!"+goods.getName()+"检查通过");
        }
    }

    public static void main (String[] args){
        Machine machine = new Machine();
        Goods goods = new Goods(false, null);
        String[] arr ={"苹果","炸药","西服","硫酸","手表","硫磺"};
        for (int i = 0; i < arr.length; i++) {
            goods.setName(arr[i]);
            if (arr[i].equals("硫酸") || arr[i].equals("炸药") || arr[i].equals("硫磺")) {
                goods.setIsDanger(true);
            }
            else {
                goods.setIsDanger(false);
            }

            try {
                machine.checkBag(goods);
            } catch (DangerException e) {
                e.toShow();
                System.out.println(goods.getName() + "被禁止!");
            }
        }
    }
}
