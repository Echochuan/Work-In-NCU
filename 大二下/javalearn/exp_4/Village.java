package exp_4;

public class Village {
        static int waterAmount;   //模拟水井的水量
        private int peopleNumber;        //村庄的人数
        String name;            //村庄的名字
        Village(String s) {
            name = s;
        }
        static void setWaterAmount(int m) {
            if(m>0)
                waterAmount = m;
        }
        void drinkWater(int n){
            if( waterAmount-n>=0) {
                waterAmount = waterAmount-n;
                System.out.println(name+"喝了"+n+"升水");
            }
            else
                waterAmount = 0;
        }
        static int getWaterAmount() {
            return waterAmount;
        }
        void setPeopleNumber(int n) {
            peopleNumber = n;
        }
        int getPeopleNumber() {
            return peopleNumber;
        }
    }
