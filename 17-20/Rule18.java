import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class Rule18 {

	/*
	 * a simple program to display sensitive operations on mobile code according to rule 18.
	 * Writing mobile code in java is one of the safest ways to write mobile code.
	 * 
	 */
	public static void main(String [] args) throws IOException
	{
		
		File outfile=new File("fileoutput.txt");
		if(outfile.createNewFile())
		{
			System.out.println("File created");
		}
		else 
		{
			System.out.println("a file with that name already exists.");
		}
	}
	
}
