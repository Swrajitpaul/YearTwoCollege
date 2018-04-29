import java.util.StringTokenizer;
public class Database {
	public static String[] freshProduce= new String[100];
    public static int count =0;
	
	public Database(String filename){
		readFromFile(filename);
	}
	
	public static void readFromFile(String myFile){
		 TextFileInput data = new TextFileInput(myFile);
		 String line = data.readLine();
		 StringTokenizer token = new StringTokenizer(line, ",");
		 
		 int arrCounter = 0;
		 while(line != null){
			 line = data.readLine();
		     token = new StringTokenizer(line, ",");
		     ProduceItem produce = new ProduceItem(token.nextToken(), token.nextToken(), token.nextToken());
		     freshProduce[arrCounter]= produce.returnString();
		     arrCounter +=1;
		     count++;
		 }
	 }
	
	public String getName(String num){
		String Name = null;
		for(int i=0; i < count; i++){
			StringTokenizer st = new StringTokenizer(freshProduce[i], " ");
			if(num.equals(st.nextToken())){
				st.nextToken();
				Name = st.toString();
				break;
			}
		}
		return Name;
	}
	
	public float getPrice(String num){
		float price = 0.0f;
		for(int i=0; i < count; i++){
			StringTokenizer st = new StringTokenizer(freshProduce[i], " ");
			if(num.equals(st.nextToken())){
				st.nextToken();
				st.nextToken();
				price = Float.parseFloat(st.toString());
				break;
			}
		}
		return price;
		
	}
}
