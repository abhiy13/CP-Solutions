/* package codechef; // don't place package name! */
 
import java.util.*;
import java.lang.*;
import java.io.*;
 
/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
      public static int[] rAA(int[] arr, int d){
        int n = arr.length;
        int[] rotated = new int[n]; 
        System.arraycopy(arr, d, rotated, 0, n - d);
        System.arraycopy(arr, 0, rotated, n - d, d);
 
        return rotated;
    }
    
    public static void main(String[] args) throws java.lang.Exception
    {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] numbers = new int[n];
        for(int i = 0; i < n; i++){
            numbers[i] = scanner.nextInt();
        }
        int d = scanner.nextInt();
        scanner.close();
        numbers = rAA(numbers, d);
        for(int i : numbers) {
            System.out.print(i + " ");
        }
        System.out.println();
    } 
}
 
