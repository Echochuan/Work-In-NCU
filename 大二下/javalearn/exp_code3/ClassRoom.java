//ClassRoom.java
package exp_code3;

public class ClassRoom {
    public static void main (String args[ ]) {
        System.out.println("教学活动从教室开始");
       Teacher zhang = new Teacher();
       Student huang = new Student();
       zhang.introduceSelf();
       huang.introduceSelf(); 
    }
}
