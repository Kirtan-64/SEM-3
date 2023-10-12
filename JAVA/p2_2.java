import java.lang.*;
import java.util.*;

public class p2_2{
    public static void main(String[] a)
    {
        int arr[] = {9,9,9,9,5};
        System.out.println(array_count9(arr));
    }

    static int array_count9(int arr[])
    {
        int count = 0;
        for(int i = 0; i < arr.length; i++)
        {
            if(arr[i] == 9)
            {
                count++;
            }
        }
        return count;
    }
}