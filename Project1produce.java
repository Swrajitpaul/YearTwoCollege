public class ProduceItem {
	private static String code;
	private static String name;
	private static float price;
	private static String reLine;
	
	public ProduceItem (String number, String id, String value){
		 code = number;
		 name = id;
		 price = Float.parseFloat(value);
		 
		 reLine = code + " " + name + " " + price;
		
	}
	
	public String returnString() {
		return reLine;
	}
	
	
}