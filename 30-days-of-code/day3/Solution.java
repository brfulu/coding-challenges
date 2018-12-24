import java.util.*;
import java.io.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        
        if (n % 2 == 1) {
            System.out.println("Weird");
        } else if (n <= 5) {
            System.out.println("Not Weird");
        } else if (n <= 20) {
            System.out.println("Weird");
        } else {
            System.out.println("Not Weird");
        }
    }
}