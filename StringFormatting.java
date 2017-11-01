import java.util.*;
class StringFormatting {
	
	public static void main(String args[]) {
		
		Scanner sc = new Scanner(System.in);
		String input="";
		input = sc.nextLine();
		String arr[] = input.split(" ");
		String position = sc.nextLine();
		String arr2[] = position.split(" ");
		StringBuilder output = new StringBuilder();
		int i=0;
		for(String str : arr2) {
			if(str.charAt(0)=='{') {
				if(str.charAt(1)=='}') {
					output.append(arr[i]);
					i++;
				}
				else if(Character.isDigit(str.charAt(1))) {
					output.append(arr[str.charAt(1)-'0']);
				}
				else {
					output.append(str.replaceAll("{", "" ).replaceAll("}",""));
				}
			} else{
				output.append(str);
			}
			output.append(" ");
		}
		System.out.println(output);
	}
}
