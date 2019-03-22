import java.util.LinkedList;

class qsynch
    {
		int balance = 0;

        // Function called by producer thread
        synchronized void put(int amount, String name) throws InterruptedException
        {
            System.out.println(name + " produced - " + amount);
			balance = balance + amount;
			System.out.println("Bank balance - " + balance);
        	notify(); // notifies the consumer thread that now it can start consuming
        }//end put

        // Function called by consumer thread
        synchronized void get(int amount, String name) throws InterruptedException
        {
        	//wait until balance is sufficient for withdrawal
        	while (balance - amount < 0)
            {
            	wait();
			}
            System.out.println(name + " consumed - " + amount);
            balance = balance - amount;
			System.out.println("Bank balance - " + balance);
        }//end consume
    }//end pcsync
