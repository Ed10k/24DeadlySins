import java.security.NoSuchAlgorithmException;
import java.security.SecureRandom;

public class Rule20 {

	/*
	 * 
	 */
	public static void main(String[] args) throws NoSuchAlgorithmException {
		//Creating a SecureRandom object instead of a Random.
		SecureRandom rand=new SecureRandom();
		
		byte [] arr=new byte[20];
		//example using the SecureRandom generator.
		rand.nextBytes(arr);
		System.out.println(arr.toString()); 
	}

}
