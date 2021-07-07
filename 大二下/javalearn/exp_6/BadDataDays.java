package exp_6;

/*
    在BadDataDay中绘制窗体，
    然后再actionPerformed方法中设置输入后调用getDayName方法获取输入之后相对应的星期，
    当超出范围时抛出异常。
 */

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class BadDataDays extends JFrame implements ActionListener {
    private JTextField dayNumberField, dayNameField;
    private int dayNumber;
    private String dayName;

    public BadDataDays() {
        super("日子数与星期几转换");
        Container container = getContentPane();
        container.setLayout(new GridLayout(2,2));
        container.add(new JLabel("输入数字", SwingConstants.LEFT));
        dayNumberField = new JTextField();
        container.add(dayNumberField);
        dayNumberField.addActionListener(this);
        container.add(new JLabel("星期几", SwingConstants.LEFT));
        dayNameField = new JTextField(10);
        container.add(dayNameField);
        setSize(200,100);
        setVisible(true);
    }

    public String getDayName(int dayNumber) throws BadDataException {
        switch(dayNumber) {
            case 7: return "Sunday";
            case 1: return "January";
            case 2: return "Tuesday";
            case 3: return "Wednesday";
            case 4: return "Thursday";
            case 5: return "Friday";
            case 6: return "Saturday";
            default:throw new BadDataException("您输入的数字不是1-7");
        }

    }

    static class BadDataException extends RuntimeException {
        private static final long seriaVersionUID = 1L;
        public BadDataException() {
            super();
        }
        public BadDataException(String message) {
            super(message);
        }
    }

    public void actionPerformed(ActionEvent event) {
        dayNameField.setText("");
        try {
            dayNumber = Integer.parseInt(dayNumberField.getText());
            dayName = getDayName(dayNumber);
            dayNameField.setText(dayName);
        }
        catch (BadDataException e) {
            JOptionPane.showMessageDialog(BadDataDays.this,e.toString(),"无效日期", JOptionPane.WARNING_MESSAGE);
        }
        catch (NumberFormatException ex) {
            System.out.println("I detected Exception" + ex.toString());
        }
    }

    public static void main(String[] args) {
        BadDataDays application = new BadDataDays();
        application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
