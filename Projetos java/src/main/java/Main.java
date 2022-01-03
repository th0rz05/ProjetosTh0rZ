import java.util.Timer;

public class Main {
    public static void main(String[] args) {
        Timer timer1 = new Timer();
        Timer timer2 = new Timer();
        Snake snake1 = new Snake(1,1, timer1);
        Snake snake2 = new Snake(2,2, timer2);
        snake1.move();
        snake2.move();
    }

}
