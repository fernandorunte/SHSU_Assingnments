// Consumer class
import java.util.*;
import java.util.Scanner;
class Consumersynch implements Runnable
{
    qsynch q;
    Random r = new Random();
    int money;
	int sleeptime;
	String name;

    Consumersynch(qsynch q, String name)
    {
        this.q = q;
        this.name = name;
        new Thread(this,this.name).start();
    }

    public void run()
    {
		while(true)
		{
        	money = r.nextInt(100);			//get money amount
        	try
        	{	q.get(money, name);			//consumer gets money
				sleeptime = r.nextInt(25000);
        		Thread.sleep(sleeptime);	//consumer sleeps after
			}catch(Exception e){}

		}//end while
    }
}//end Comsumer