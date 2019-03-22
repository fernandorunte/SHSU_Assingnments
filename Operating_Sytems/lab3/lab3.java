import java.util.*;
import java.io.*;

//Preemptie priority, round-robin secondary with Q = 2. (Higher priority takes control)
//we want to let the user vary the quantum time
//sleep() will be used to speed up or slow down the process
//output process being dispatched, preempted, completed, ect
//At the end, output the turnaround time for each and average turnarount time

public class lab3
{

	public static void main(String [] args)throws IOException
	{
		// get filename
		String filename;

		if (args.length != 0)
		{
			filename = args[0];
		}
		else
		{
			filename = "inp.txt";
		}


		Scanner infile = new Scanner(new File(filename));		// Open file for input
		ArrayList<Character> label = new ArrayList<Character>(); 		//dynamic allocation
		ArrayList<Integer> arrival = new ArrayList<Integer>();
		ArrayList<Integer> priority = new ArrayList<Integer>();
		ArrayList<Integer> cpuburst = new ArrayList<Integer>();
		int value;
		String line;
		Scanner input;
		char alpha = 'A';
		int inc = 0;
		int flip = 0;
		while(infile.hasNextLine())
		{
			line = infile.nextLine(); //reads in a line
			input = new Scanner(line); //make a new scanner on this line
			label.add(alpha);	//adds proceses A...B...C...
			alpha++;			//Increments our A to B

			System.out.println("Process name " + label.get(inc) + ":");
			System.out.println("\t Arrival, Priority, CPU Burst: ");
			inc++;
			while(input.hasNextInt())
			{
				value = input.nextInt(); //get next int value on this line
				System.out.print( "\t  " + value + "|| ");
				if (flip == 0)
				{
					arrival.add(value);

				}
				else if (flip == 1) priority.add(value);
				else if (flip == 2) cpuburst.add(value);
				flip ++;


			}
			if (flip == 1){priority.add(0); cpuburst.add(0);}
			System.out.println("");
			flip = 0;

		}



		infile.close();

		for (Integer test: arrival){System.out.print(test + " || ");}    System.out.println();
		for (Integer test: priority){System.out.print(test + " || ");} System.out.println();
		for (Integer test: cpuburst){System.out.print(test + " || ");} System.out.println();

	}//end main




	public static void readvalue(int loc, int opcode, int operand)
	{
		System.out.println(loc + ":\t" + opcode + "\t" + operand);
	}



}//end SchedulingSim