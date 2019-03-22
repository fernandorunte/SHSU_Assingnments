// Driver class
import java.util.*;

class PC
{
    public static void main(String args[])
    {
        // creating buffer queue
        Q q = new Q();
		Scanner sc = new Scanner(System.in);
		System.out.println("How many children do you want?");
		int children = sc.nextInt();
		String name;

		new Producer(q, "Parent 1");
		new Producer(q, "Parent 2");
		for(int x = 0; x <= children; x ++)
		{
			name = "Child " + x;
			new Consumer(q, name);
		}


    }//end main
}//end PC