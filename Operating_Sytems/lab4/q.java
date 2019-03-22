// Java implementation of a producer and consumer
// that use semaphores to control synchronization.

import java.util.concurrent.Semaphore;

class Q
{
    //an item
	int balance = 0;
	int money;
    // semCon initialized with 0 permits
    // to ensure put() executes first
    static Semaphore semCon = new Semaphore(0);
	static Semaphore isEnough = new Semaphore(0);
    static Semaphore semProd = new Semaphore(1);

    // to get an item from buffer
    void get(int money, String name)
    {
        try {


			while(balance - money < 0) //if balance goes below zero
			{
				isEnough.acquire();	//prevent children from taking
			}

								//balance has enough money
			semCon.acquire();	//allow children to take

            // Before consumer can consume an item,
            // it must acquire a permit from semCon

        	//this works -->    //semCon.acquire();
        }
        catch(InterruptedException e) {
            System.out.println("InterruptedException caught");
        }
        this.money = money;
		balance = balance - money;
        // consumer consuming an item
        System.out.println(name + " consumed money : " + money);
        System.out.println("Current balance : " + balance);

        // After consumer consumes the item,
        // it releases semProd to notify producer
        //semProd.release();
        semCon.release(); //Gabe noticed this, maybe no?
    }

    // to put an item in buffer
    void put(int money, String name)
    {
        try {
            // Before producer can produce an item,
            // it must acquire a permit from semProd
            semProd.acquire();
        } catch(InterruptedException e) {
            System.out.println("InterruptedException caught");
        }

        // producer producing an item
        this.money = money;
		balance = balance + money;

        System.out.println(name + " produced money : " + money);
		System.out.println("Current balance : " + balance);
        // After producer produces the item,
        // it releases semCon to notify consumer

		/*while(isEnough.availablePermits() < 0 ) //while there is
		{
			isEnough.release();
		}*/
        isEnough.release();
        semCon.release();
        semProd.release();
    }
}//end class