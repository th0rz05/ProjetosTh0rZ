import java.util.Timer;
import java.util.TimerTask;

public class Snake{

    public Snake(int id, int velocidade,Timer t) {
        this.id = id;
        this.velocidade = velocidade;
        ProgessoNaVelocidade = 0;
        distancia = 0;
        timer = t;
    }

    private int id;
    private int velocidade;
    private int ProgessoNaVelocidade;
    private int distancia;

    private Timer timer;
    private TimerTask tt = new TimerTask() {
        @Override
        public void run() {
            ProgessoNaVelocidade += velocidade;
            if(ProgessoNaVelocidade==4){
                System.out.println("movendo cobra" + id);
                distancia++;
                ProgessoNaVelocidade=0;
            }
            if (distancia==4){
                tt.cancel();
                timer.cancel();
                timer.purge();
                System.out.println("cobra com id " + id + " chegou ao destino.");
            }
        }
    };

    public void move(){
        timer.schedule(tt,1000,1000);
    }
}
