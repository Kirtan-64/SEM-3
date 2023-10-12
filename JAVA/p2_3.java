import java.lang.*;
import java.util.*;

public class p2_3{
    public static void main(String[] a)
    {
        int arr[] = {5,5,5,5,9};
        System.out.println(array_count9(arr));
    }

    static boolean array_count9(int arr[])
    {
        for(int i = 0; i < Math.min(4,arr.length); i++)
        {
            if((arr[i] == 9))
            {
                return true;
            }
        }
        return false;
    }
}