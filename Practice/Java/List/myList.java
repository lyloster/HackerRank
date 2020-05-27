import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        List<Integer> myList = new ArrayList<Integer>();
        for(int i = 0; i < n; ++i){
            myList.add(scan.nextInt());
        }
        
        int queries = scan.nextInt();
        for(int i = 0; i < queries; ++i){
            String command = scan.next();
            //System.out.println("command == " + command);
            if(command.equals("Insert")){
                int x = scan.nextInt();
                int y = scan.nextInt();
                //System.out.println( "x == " + x);
                //System.out.println( "y == " + y);
                myList.add(x,y);

            }else{
                //System.out.println(Arrays.toString(myList.toArray()));
                int x = scan.nextInt();
                myList.remove(x);
            }
        }
        for(int i = 0; i < myList.size(); ++i){
            System.out.print(myList.get(i) + " ");
        }
        scan.close();
    }
}
