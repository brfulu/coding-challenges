import java.io.*;
import java.util.*;
import java.io.*;

public class Solution {
    public static long calculateTotalCost(double mealCost, int tipPercent, int taxPercent) {
        double tipCost = mealCost * (tipPercent / 100.0);
        double taxCost = mealCost * (taxPercent / 100.0);
        return Math.round(mealCost + tipCost + taxCost);
    }
        
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        double mealCost = scan.nextDouble();
        int tipPercent = scan.nextInt();
        int taxPercent = scan.nextInt();

        long result = calculateTotalCost(mealCost, tipPercent, taxPercent);
        System.out.println(result);
    }
}
