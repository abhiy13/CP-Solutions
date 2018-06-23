import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.util.*;
import java.util.Date;
import java.util.Calendar;
import java.io.*;
class colefib{
public static void main(String[] args)throws IOException {
        Scanner in = new Scanner(System.in);
        int t=in.nextInt();
        in.nextLine();
        for(int a0=0;a0<t;a0++)
        {
            String str=in.next();
            int arr[]=new int[26];
            int i,x,k=0,f1=0,f2=0;
            for(i=0;i<str.length();i++)
            {
                x=(int)str.charAt(i)-97;
                arr[x]++;
            }
            for(i=0;i<26;i++)
            {
                if(arr[i]>0)
                k++;
            }
            int a[]=new int[k];
            k=0;
            for(i=0;i<26;i++)
            {
                if(arr[i]>0)
                a[k++]=arr[i];
            }
            Arrays.sort(a);
            if(k>2)
            {
                 for(i=2;i<k;i++)
                 {
                     if(a[i]!=( a[i-1]+a[i-2]))
                     {
                        f1=1;
                        break;
                     }
                 }
                 x=a[0];
                 a[0]=a[1];
                 a[1]=x;
                 for(i=2;i<k;i++)
                 {
                     if(a[i]!=( a[i-1]+a[i-2]))
                     {
                        f2=1;
                        break;
                     }
                 }
            }
            if(f1==0 || f2==0)
            System.out.println("Dynamic");
            else
            System.out.println("Not");
        }
    }
} 
