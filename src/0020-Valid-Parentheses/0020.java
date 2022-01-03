package leetcodeChecks;

import java.util.*;
public class oo2o {
    class Solution {
        public boolean isValid(String s) {

            if(s.isEmpty()){
                return true;
            }

            Stack<Character> st = new Stack<Character>();
            for(int i=0; i < s.length();i++){

                if(s.charAt(i)=='(' || s.charAt(i)=='[' ||s.charAt(i)=='{'){
                    st.push(s.charAt(i));
                }
                else{
                    if(st.isEmpty()){
                        return false;
                    }
                    char c= st.peek();


                    if(s.charAt(i)==')' && c=='('|| s.charAt(i) == ']' && c=='['|| s.charAt(i) =='}' && c=='{'){
                        st.pop();
                    }else{
                        return false;
                    }
                }
            }

            if(st.isEmpty()){
                return true;
            }
            else{
                return false;
            }


        }
    }
}
