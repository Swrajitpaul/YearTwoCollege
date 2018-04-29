import javax.swing.JOptionPane;

public class Lab6Program1 {

	public static void main(String[] args) {
	
		int[] numberArray = new int [100];
		int arrayLength = inputFromFile(args[0], numberArray);
		
		for (int i= 0; i < arrayLength; i++)
			System.out.println(numberArray[i]);
	} //main

	public static int inputFromFile(String filename, int[] Array) {
		TextFileInput file = new TextFileInput(filename);
		int lengthFilled =0;
		String line = file.readLine();
		while (lengthFilled < Array.length && line != null){
			Array[lengthFilled++] = Integer.parseInt(line);
			line = file.readLine();
		}
		if (line != null) {
			System.out.println("There are too many words.");
			System.exit(1);
		}
		file.close();
		return lengthFilled;
	}
	
	

} // class Lab4Program1
