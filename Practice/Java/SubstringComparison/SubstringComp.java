import java.util.Scanner;

public class Solution {

    public static String getSmallestAndLargest(String s, int k) {
        String smallest = s.substring(0,k);
        String largest = s.substring(0,k);

        // Complete the function
        // 'smallest' must be the lexicographically smallest substring of length 'k'
        // 'largest' must be the lexicographically largest substring of length 'k'
        String temp = "";

        for(int i = 1; i < s.length() - k; ++i){
            temp = s.substring(i, i+k);
            int tempIsSmaller = temp.compareTo(smallest);
            //the value 0 if the argument string is equal to this string;
            // a value less than 0 if this string is lexicographically
            // less than the string argument; and a value greater than 0
            //if this string is lexicographically greater than the string argument.
            int tempIsLarger = temp.compareTo(largest);
            if(tempIsSmaller < 0){
                smallest = temp;
            }
            if(tempIsLarger > 0){
                largest = temp;
            }
        }
        return smallest + "\n" + largest;
    }
