import javax.swing.JOptionPane;

public class Lab5Program1 {

	public static void main(String[] args) {
	
		String[] wordArray = new String [100];
		String isOrIsNot, inputWord;
		int arrayLength = inputFromFile(args[0], wordArray);
		
		while (true){
		// This line asks the user for input by popping out a single window
		// with text input
		inputWord = JOptionPane.showInputDialog(null, "Enter a word in all lower case:");
		
		if (inputWord.equals("STOP")) System.exit(0);
		// if the inputWord is contained within wordArray return true
		if (wordIsThere(inputWord, wordArray)) 
			isOrIsNot = "is"; // set to is if the word is on the list
		else
			isOrIsNot = "is not"; // set to is not if the word is not on the list
		
		// Output to a JOptionPane window whether the word is on the list or not
		JOptionPane.showMessageDialog(null, "The word " + inputWord + " " + isOrIsNot + " on the list.");
		}
	} //main

	public static int inputFromFile(String filename, String[] wordArray) {
		TextFileInput file = new TextFileInput(filename);
		int lengthFilled =0;
		String line = file.readLine();
		
		while (lengthFilled < wordArray.length && line != null){
			wordArray[lengthFilled++] = line;
			line = file.readLine();
		}
		if (line != null) {
			System.out.println("There are too many words.");
			System.exit(1);
		}
		file.close();
		return lengthFilled;
	}
	
	
	public static boolean wordIsThere(String findMe, String[] theList) {
        for (int i=0; i< theList.length; i++){
		if(findMe.equals(theList[i]))
			return true;
        }
        return false;
	} // wordIsThere
} // class Lab4Program1
