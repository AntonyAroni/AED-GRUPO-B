import java.util.Stack;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner lectura = new Scanner (System.in);
        System.out.println("Ingrese su cadena: ");
        String cadena = lectura.next();
        boolean isBalanced = isBalanced(cadena);
        if (isBalanced) {
            System.out.println("Cadena: "+cadena+": SI");
        } else {
            System.out.println("Cadena"+cadena+": NO");
        }
    }
    public static boolean isBalanced(String str){
        Stack<Character> stack = new Stack<>();
        for(int i=0; i<str.length(); i++){
            if(str.charAt(i)=='(' || str.charAt(i)=='[' || str.charAt(i)=='{'){
                stack.push(str.charAt(i));
            }else{
                if(stack.isEmpty()){
                    return false;
                }
                char c = stack.pop();
                if((c=='(' && str.charAt(i)!=')') || (c=='[' && str.charAt(i)!=']') || (c=='{' && str.charAt(i)!='}')){
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }
}