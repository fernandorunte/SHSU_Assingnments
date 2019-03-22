// Producer class
import java.util.*;
class Producersynch implements Runnable
{
    qsynch q;
    Random r = new Random();
    int money;
    int sleeptime;
    String name;

    Producersynch(qsynch q, String name)
    {
        this.q = q;
        this.name = name;
        new Thread(this, this.name).start();
    }

    public void run()
    {
		while(true)
		{
        	money = r.nextInt(100);					//get money amount
        	try
			{	q.put(money, name);					// producer put items
				sleeptime = r.nextInt(20000);
				Thread.sleep(sleeptime);
			}catch(Exception e){}

		}
    }
}//end producer

