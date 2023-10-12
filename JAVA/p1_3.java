public class p1_3
{
    public static void main(String a[])
    {
        double var1 = 1234.5678;
        long var2 = (long)var1;
        short var3 = (short)((int)(var1 * 10000) - (int)(var2 * 10000));
        System.out.println("The value is: " + var2 +"." + var3);
    }
}