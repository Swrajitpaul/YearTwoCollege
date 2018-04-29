import javax.swing.JOptionPane;
public class Project0 {
   public static void main(String[] args) {
       
	  while(true) {
	     // asking the user to type in a sentence
	     String sentence = JOptionPane.showInputDialog(null, "Please type in a sentence.");
       
	     // if sentence equals stop then exit loop
	     if (sentence.equalsIgnoreCase("STOP")) 
		    System.exit(0);
	     // declaring character we are looking for in the string
	     char ucase ='E', lcase ='e';
	   
	     int upper=0, lower=0;
	   
	     // going trough string to see if characters exists
	     for(int i=0; i< sentence.length(); i++) {
	      
            if(ucase ==(sentence.charAt(i)))
               upper++;       
	      
		    else if (lcase ==(sentence.charAt(i)))
               lower++;
	        }
	     JOptionPane.showMessageDialog(null, "Number of lower case e's: " + lower +
			   " \n" + "Number of upper case E's: " + upper);
	    }
    }
}