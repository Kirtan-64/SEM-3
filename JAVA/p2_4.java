import java.lang.*;
import java.util.*;

public class p2_4{
    public static void main(String[] a)
    {
        String st = "hi";
        StringBuilder tmp = new StringBuilder(st.length());
        for(int i = 0; i < st.length(); i++)
        {
            tmp.append(st.charAt(i));
            tmp.append(st.charAt(i));
        }
        System.out.println(tmp);
    }
}