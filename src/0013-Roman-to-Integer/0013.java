class Solution {
    public int romanToInt(String s) {
      	int num = 0;
        String sCopy = new String(s);
        sCopy = sCopy.replace("IV", "IIII");
        sCopy = sCopy.replace("IX", "VIIII");
        sCopy = sCopy.replace("XL", "XXXX");
        sCopy = sCopy.replace("XC", "LXXXX");
        sCopy = sCopy.replace("CD", "CCCC");
        sCopy = sCopy.replace("CM", "DCCCC");

        for (int i = 0; i < sCopy.length(); i++)
        {
            switch (sCopy.charAt(i)) 
            {
                case 'I':
                    num++; break;
                case 'V':
                    num += 5; break;
                case 'X':
                    num += 10; break;
                case 'L':
                    num += 50; break;
                case 'C':
                    num += 100; break;
                case 'D':
                    num += 500; break;
                case 'M':
                    num += 1000; break;
            }
        }        
        return num;
        
    }
}