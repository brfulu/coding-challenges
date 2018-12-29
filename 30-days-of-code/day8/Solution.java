import java.util.*;
import java.io.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<String, String> phoneBook = new HashMap<>();

        for (int i = 0; i < n; i++) {
            String name = sc.next();
            String number = sc.next();
            phoneBook.put(name, number);
        }

        while (sc.hasNext()) {
            String queryName = sc.next();
            if (phoneBook.containsKey(queryName))
                System.out.println(queryName + "=" + phoneBook.get(queryName));
            else
                System.out.println("Not found");
        }
    }
}