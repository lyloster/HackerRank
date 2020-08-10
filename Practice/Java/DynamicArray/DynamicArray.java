//does not compile

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {
    public static List<Integer> dynamicArray(int n, List<List<Integer>> queries) {
    // Write your code here
    List<List<Integer>> seqList = new ArrayList<>(n);
    int lastAnswer = 0;
    List<Integer> results = new ArrayList<>();
    for(int i = 0; i < queries.size(); ++i){
        if(queries.get(i).get(0) == 1){
                    int seq = ((queries.get(i).get(1) ^ lastAnswer)%n);
                    seqList.get(seq).add(queries.get(i).get(2));
                }else if(queries.get(i).get(0) == 2){
                    int seq = ((queries.get(i).get(1) ^ lastAnswer)%n);
                    lastAnswer = (queries.get(i).get(2) % seqList.get(seq).size());
                    results.add(lastAnswer);
                    //System.out.println(lastAnswer);
                }
    }
    return results;
    }

    // public static List<Integer> dynamicArray(int n, List<List<Integer>> queries) {
    // // Write your code here
    // int[][] seqList = new int[n+1][n];
    // //int used = 0;
    // int lastAnswer = 0;
    // List<Integer> results = new ArrayList<>();
    // for(int i = 0; i < queries.size(); ++i){
    //     if(queries.get(i).get(0) == 1){
    //                 int seq = ((queries.get(i).get(1) ^ lastAnswer)%n);
    //                 seqList[seq][used] = queries.get(i).get(2);
    //                 //++used;
    //             }else if(queries.get(i).get(0) == 2){
    //                 int seq = ((queries.get(i).get(1) ^ lastAnswer)%n);
    //                 lastAnswer = (queries.get(i).get(2) % seqList[seq].length);
    //                 results.add(lastAnswer);
    //                 //System.out.println(lastAnswer);
    //             }
    // }
    // return results;
    // }
}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int n = Integer.parseInt(firstMultipleInput[0]);

        int q = Integer.parseInt(firstMultipleInput[1]);

        List<List<Integer>> queries = new ArrayList<>();

        IntStream.range(0, q).forEach(i -> {
            try {
                queries.add(
                    Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
                        .map(Integer::parseInt)
                        .collect(toList())
                );
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        List<Integer> result = Result.dynamicArray(n, queries);

        bufferedWriter.write(
            result.stream()
                .map(Object::toString)
                .collect(joining("\n"))
            + "\n"
        );

        bufferedReader.close();
        bufferedWriter.close();
    }
}
