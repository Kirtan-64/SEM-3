import java.lang.*;
import java.util.*;

public class p2_1{
    public static void main(String[] a)
    {
        System.out.println(front_times("h",3));
    }

    static String front_times(String word, int num)
    {
        int len = word.length();
        String tmp;
        if(len < 3)
        {
            tmp = new String(word.substring(0, len));
        }
        else
        {
            tmp = new String(word.substring(0, 3));
        }
        String result = new String("");
        while((num != 0))
        {
            result = result.concat(tmp);
            num --;
        }
        return result;
    }
}