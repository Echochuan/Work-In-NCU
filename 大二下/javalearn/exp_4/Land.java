package exp_4;

public class Land {
    public static void main(String args[]) {
       Village.setWaterAmount(200); //用类名调用setWaterAmount(int m),并向参数传值200

        int leftWater = Village.waterAmount; //用Village类的类名访问waterAmount

        System.out.println("水井中有 "+leftWater+" 升水");
        Village zhaoZhuang,maJiaHeZi;
        zhaoZhuang = new Village("赵庄");
        maJiaHeZi = new Village("马家河子");
        zhaoZhuang.setPeopleNumber(80);
        maJiaHeZi.setPeopleNumber(120);

        zhaoZhuang.drinkWater(50);//zhaoZhuang调用drinkWater(int n),并向参数传值50

        leftWater =maJiaHeZi.getWaterAmount();//maJiaHeZi调用getWaterAmount()方法
        String name=maJiaHeZi.name;
        System.out.println(name+"发现水井中有 "+leftWater+" 升水");
        maJiaHeZi.drinkWater(100);

        leftWater =zhaoZhuang.getWaterAmount();//zhaoZhuang调用getWaterAmount()方法
        name=zhaoZhuang.name;
        System.out.println(name+"发现水井中有 "+leftWater+" 升水");

        int peopleNumber = zhaoZhuang.getPeopleNumber();
        System.out.println("赵庄的人口:"+peopleNumber+"人");
        peopleNumber = maJiaHeZi.getPeopleNumber();
        System.out.println("马家河子的人口:"+peopleNumber+"人");
    }
}
