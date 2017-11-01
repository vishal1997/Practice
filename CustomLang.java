
import java.util.*;
import java.io.*;
class CustomLang{

    public static void main(String args[] ) throws Exception {
    
        Map<Integer,String> myMap = new HashMap<Integer,String>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        for (int i = 0; i < 2; i++) {
		String line = br.readLine();
		myMap.put(i,line);
        }

        
        for(int j=0;j<2;j++) {
        
        	String result = "";
		String queries=myMap.get(j);
		String arr[] = queries.split(" ");
		String str = arr[arr.length-1];
		result = str;
		for(int i = 0; i < arr.length-1; i++) {
		
			String word = arr[i];	
			switch(word) {
			
			    case "print":
				break;
			    case "tolower":
				result = result.toLowerCase();
				break;
			    case "toupper":
				result =result.toUpperCase();
				break;
			    case "reverse":
				String mm = new StringBuffer(result).reverse().toString();
				result=mm;
				break;
			    case "append_a":
				StringBuilder sb = new StringBuilder(14);
				result=sb.append(result).append("a").toString();
			    break;
			}
		}
		System.out.println(result);
        }
    }
}

