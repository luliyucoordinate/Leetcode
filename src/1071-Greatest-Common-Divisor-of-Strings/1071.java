class Solution 
{
    public String gcdOfStrings(String s1, String s2) 
    {
        return (s1 + s2).compareTo(s2 + s1) == 0 ? s1.substring(0, gcd(s1.length(), s2.length())) : "";
    }
    
    private int gcd(int a, int b)  {
        return b > 0 ? gcd(b, a % b) : a;
    }
}