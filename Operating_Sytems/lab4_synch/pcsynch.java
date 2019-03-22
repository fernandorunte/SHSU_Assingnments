// Driver class
import java.util.*;

class pcsynch
{
    public synchronized static void main(String args[])
    {
        qsynch q = new qsynch();
		Scanner sc = new Scanner(System.in);
		System.out.println("How many children do you want?");
		int children = sc.nextInt();
		String name;

		new Producersynch(q, "Parent 1");
		new Producersynch(q, "Parent 2");
		for(int x = 0; x <= children; x ++)
		{
			name = "Child " + x;
			new Consumersynch(q, name);
		}
    }//end main
}//end PC