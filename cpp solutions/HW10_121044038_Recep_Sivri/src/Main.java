import java.util.ArrayList;
import java.util.Scanner;
/**
 * @author Recep Sivri
 *  Main.java part of HW10_121044038_Recep_Sivri
 * Created by Recep Sivri on 3.01.2016.
 */
public class Main {

    /**
     * Test main function for HW10_121044038_Recep_Sivri.
     * @param args commend line argument.
     */
    public static void main(String[] args) {
        int result, i, result2,j;
        Expression exp = new Expression();
        Expression exp2 = new Expression();
        ArrayList<String> Result = new ArrayList<>();
        ArrayList<String> Result2 = new ArrayList<>();
        Scanner scanString = new Scanner(System.in);
        String str = "\0";
        String str2 = "\0";
        String str3 = "y";
        String str4 = "\0";
        System.out.println("****************Testing HW10_121044038_Recep_Sivri*****************************");
        while(str3.equals("y")||str3.equals("Y")) {//until str3 will equal n or N

            System.out.println("Enter your expression, after each operator or operand press enter, to end the expression press(for exp1) =");
            while (str.compareTo("=") != 0) {
                System.out.println("Enter your expression element");//enters user elements of expression.
                str = scanString.nextLine();
                if (!str.equals("="))//until str will equal =.
                    exp.setElementExp(str);
            }
            result = exp.checkPharantesis();
            if (result == -1)
                System.out.println("invalid Expression Array!");
            else {

                System.out.println(exp.toString());
                System.out.println();
                System.out.println("result:");//prints result steps.
                Result = exp.Result();// return results to Arraylist.

                for (i = 0; i < Result.size(); ++i)
                    System.out.println(Result.get(i));
            }
            str = "\0";
            System.out.println("Enter your expression, after each operator or operand press enter, to end the expression press(for exp2) =");
            while (str.compareTo("=") != 0) {
                System.out.println("\nEnter your expression element");//enters user elements of expression.
                str = scanString.nextLine();
                if (!str.equals("="))//until str will equal =.
                    exp2.setElementExp(str);
            }
            result2 = exp2.checkPharantesis();
            if (result2 == -1)
                System.out.println("invalid Expression Array!");
            else {

                System.out.println(exp2.toString());
                Result = exp2.Result();// return results to Arraylist.
                System.out.println();
                System.out.println("result:");//prints result steps.
                for (i = 0; i < Result.size(); ++i)
                    System.out.println(Result.get(i));

            }
            do {
                System.out.println("would you test equal function?[y/n]");
                str4=scanString.nextLine();
            }while(!str4.equals("y")&&!str4.equals("Y")&&!str4.equals("n")&&!str4.equals("N"));
            if(str4.equals("y")||str4.equals("Y"))
            {
                if(exp.equals(exp2))
                    System.out.println("exp1==exp2");
                else
                    System.out.println("exp1!=exp2");
            }
            str="\0";
            Result.clear();//clears Exparrays which is in Expression class.
            Result2.clear();
            exp.clearFunction();
            exp2.clearFunction();
            do {
                System.out.println("would you like continue?[y/n]");
                str3=scanString.nextLine();
            }while(!str3.equals("y")&&!str3.equals("Y")&&!str3.equals("n")&&!str3.equals("N"));


        }
    }
}
