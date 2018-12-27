import java.util.*;
import java.io.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCount = sc.nextInt();

        for (int t = 0; t < testCount; t++) {
            String S = sc.next();
            String oddLetters = "";
            String evenLetters = "";

            for (int i = 0; i < S.length(); i++) {
                if (i % 2 == 0)
                    evenLetters += S.charAt(i);
                else
                    oddLetters += S.charAt(i);
            }

            System.out.println(evenLetters + " " + oddLetters);
        }
    }
}