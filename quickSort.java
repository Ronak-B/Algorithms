import java.util.Arrays;
import java.util.Scanner;

public class quickSort {
    public static void main(String[] args) {
        Scanner s = new Scanner (System.in);
        System.out.println("Enter number of elements");
        int n = s.nextInt();
        System.out.println("Enter elements");
        int []a = new int[n];
        for (int i=0;i<n;i++) {
            a[i] = (int)(Math.random()*1000);
        }

        System.out.println("Unsorted Array: "+ Arrays.toString(a));
        sort(a,0,a.length-1);
        System.out.println("Sorted Array: "+ Arrays.toString(a));
    }
    private static void sort(int[] a,int l,int r) {
        if(l<r) {
            int pv=partition(a,l,r);
            sort(a,l,pv-1);
            sort(a,pv+1,r);
        }
    }
    private static int partition(int[] a,int l,int r) {
        int pivot=a[l];
        int i=l,j=r+1;
        while(i<j) {
            do {
                i++;
            } while(a[i]<=pivot && i<r);
            do {
                j-- ;
            } while (a[j]>pivot && j>l);

            if(i<j) {
                int temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }

        int temp=a[j];
        a[j]=a[l];
        a[l]=temp;
        return j;
    }
}
