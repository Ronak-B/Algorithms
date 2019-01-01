import java.util.Arrays;
import java.util.Scanner;

public class mergeSort {
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
        if(l<r)
        {
            int m=(l+r)/2;  //middle
            sort(a,l,m);
            sort(a,m+1,r);
            merge(a,l,m,r);
        }
    }
    private static void merge(int[] a,int l,int m ,int r) {

        //creating sub arrays

        int n1,n2;
        n1=m-l+1;
        n2=r-m;
        int[] L=new int[n1];
        int[] R=new int[n2];

        //filling data into sub-arrays

        for(int i=0;i<n1;++i) {
            L[i]=a[l+i];
        }

        for(int j=0;j<n2;++j) {
            R[j]=a[m+j+1];
        }

        int i=0,j=0;  //initial index of sub arrays

        int k=l;    //initial index of merged sub array

        while(i<n1 && j<n2) {
            if(L[i]<=R[j]) {
                a[k++]=L[i++];
            }
            else {
                a[k++]=R[j++];
            }
        }

        //copy remaining elements of L[] if any
        while(i<n1) {
            a[k++]=L[i++];
        }

        //copy remaining elements of R[] if any
        while(j<n2) {
            a[k++]=R[j++];
        }
    }
}
