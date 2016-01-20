import java.util.ArrayList;

/**
 * @author Recep Sivri
 *  Expression.java part of HW10_121044038_Recep_Sivri
 * Created by Recep Sivri on 3.01.2016.
 */
public class Expression implements expElemList {
    private ArrayList<expElemList> Exparray = new ArrayList<expElemList>();
    private Paranthesis paranth;
    private Operator op;
    private Operand operd;
    private int index;
    private String str = "\0";
    /**
     * setter for Index value.
     * @param Element is a value of index.
     */
    public void setIndex(int Element) {
        index = Element;
    }
    /**
     * getter for Index value.
     * @return index value.
     */
    public int getIndex() {
        return index;
    }
    /**
     * setter for Expression Class.
     * @param Element is a String for element of expression.
     */
    public void setElementExp(String Element) {
        if (Element.equals("(") || Element.equals(")")) {
            paranth = new Paranthesis();
            paranth.setElementPar(Element);
            Exparray.add(paranth);

        } else if (Element.equals("+") || Element.equals("-") || Element.equals("/") || Element.equals("*")) {//controls if elements are operand.
            op = new Operator();
            op.setElementOp(Element);
            Exparray.add(op);
        } else {
            if (CheckOperand(Element)) {//checks element.
                operd = new Operand();
                operd.setElementOpnd(Element);
                Exparray.add(operd);
            } else {
                System.out.println(Element + " is not a operand!");
            }
        }

    }
    /**
     * checks operands.
     * @param str is a element of Expression which is a operand.
     * @return boolean value if operand is valid or invalid.
     */
    private boolean CheckOperand(String str) {
        int i;
        if (str.length() == 0 || str == null || str.charAt(0) == '-' && str.length() == 1)//checks if string str contains str.
            return false;
        else {
            if (str.charAt(0) == '-') {
                for (i = 1; i < str.length(); ++i) {
                    if (str.charAt(i) < '0' || str.charAt(i) > '9')
                        return false;
                }
            } else if (str.charAt(0) != '-') {//if str contains neg number implement this.
                for (i = 0; i < str.length(); ++i) {
                    if (str.charAt(i) < '0' || str.charAt(i) > '9')
                        return false;
                }
            }

        }
        return true;
    }
    /**
     * toString for Expression Class.
     * @return string format of Expression object.
     */
    public String toString() {
        int i;
        String str="\0";
        for (i = 0; i < Exparray.size(); ++i)
            str = str + " " + Exparray.get(i).toString();
        return str;
    }
    /**
     * checks operators .
     * @return if operator is before or after a other operator returns false else true.
     */
    private boolean checkOperatorNums()
    {
        int i;
        for(i=0;i<Exparray.size()-1;++i)
        {
            if(Exparray.get(i).getClass().toString().equals("class Operator"))
            {
                if(Exparray.get(i+1).getClass().toString().equals("class Operator"))
                    return false;
            }
        }
        return true;
    }
    /**
     * checks pharantesis status .
     * @return if pharantesis is valid true else false.
     */
    public int checkPharantesis() {
        int i = 0, left = 0, right = 0, j = 0, counter = 0;
        ArrayList<String> Carr = new ArrayList<String>();//Arraylist for determine pharantesis.

        for (i = 0; i < Exparray.size(); ++i) {
            if (Exparray.get(i).toString().equals("(") || Exparray.get(i).toString().equals(")"))
                Carr.add(Exparray.get(i).toString());
            if (Exparray.get(i).toString().equals("("))
                ++left;
            if (Exparray.get(i).toString().equals(")"))
                ++right;
        }

        if (countPharanthesis()&&(Carr.get(0).toString().equals(")") || Carr.get(Carr.size() - 1).toString().equals("(")))//if begin and end of Expression contains reverse pharantesis implement this.
            return -1;
        else
        if (right != left)
            return -1;
        else {
            i = 0;
            j = Carr.size() - 1;
            while (i < j) {// i is index from begin of Expression and j is index from end of Expression.
                while (Carr.get(i).toString().equals("(")) {//counts number of left pharantesis.
                    ++i;
                }
                if (Carr.get(i).toString().equals(")") && Carr.get(i - 1).toString().equals("(")) {// controls () phrantesis.
                    Carr.set(i, ".");
                    Carr.set(i - 1, ".");
                }
                ++i;
                while (Carr.get(j).toString().equals(")")) {//counts number of right pharantesis.
                    --j;
                }
                if (Carr.get(j).toString().equals("(") && Carr.get(j + 1).toString().equals(")")) {// controls () phrantesis.
                    Carr.set(j, ".");
                    Carr.set(j + 1, ".");
                }
                --j;
            }
            i = 0;
            j = Carr.size() - 1;//in this part program goes to in to in pharantesis and find in to in index of pharantesis.
            while (i < j) {// i is index from begin of Expression and j is index from end of Expression.
                while (i < j && !Carr.get(i).toString().equals("("))
                    ++i;
                while (i < j && !Carr.get(j).toString().equals(")"))
                    --j;
                if (i < j) {
                    Carr.set(j, ".");
                    Carr.set(i, ".");
                }
                ++i;
                --j;
            }

            for (i = 0; i < Carr.size(); ++i) {//counts size of inner expression.
                if (!Carr.get(i).toString().equals(")") && !Carr.get(i).toString().equals(")"))
                    ++counter;
            }
            if (counter != Carr.size())
                return -1;
        }
        return 0;
    }
    /**
     * equals function for Expression class.
     * @return if objects are equal true else false.
     * @param other is a  expression object which compare with this object.
     */
    public boolean equals(Object other)
    {
        ArrayList<String> str=new ArrayList<String>();
        ArrayList<String> str2=new ArrayList<String>();
        Expression exp;
        String s1,s2;
        exp=(Expression)other;
        str=Result();
        str2=exp.Result();
        if(str.get(str.size()-1).equals(str2.get(str2.size()-1)))
            return true;
        else
            return false;
    }
    /**
     * compares result for expressions with paranthesis.
     * @return result which contains operators.
     */
    private String evaluate() {
        int i, j, counter = 0, result = 0, max = 0, control = 0;
        String str2 = "\0";
        j = Exparray.size() - 1;
        i = 0;
        while (i < j) {
            while (i < j && !Exparray.get(j).toString().equals(")"))
                --j;
            while (i < j && !Exparray.get(i).toString().equals("("))
                ++i;

            ++i;
            --j;
        }

        while (!Exparray.get(i).toString().equals("("))
            --i;
        counter = i;
        while (!Exparray.get(i).toString().equals("("))
            ++i;
        max = i;
        while (countOperator(counter, "*", "/")) {// if opretors are * or / implements this part.
            i = counter;

            while (i<Exparray.size()&&!Exparray.get(i).toString().equals(")")) {
                if (Exparray.get(i).getClass().toString().equals("class Operator")) {//checks if element of Expression is a operator.
                    if (Exparray.get(i).toString().equals("*")) {
                        if (Exparray.get(i - 1).getClass().toString().equals("class Operand") &&//checks if element of Expression befor and after are operand.
                                Exparray.get(i + 1).getClass().toString().equals("class Operand")) {//checks if element of Expression befor and after are operand.
                            result = Integer.valueOf(Exparray.get(i - 1).toString()) * Integer.valueOf(Exparray.get(i + 1).toString());
                            operd = new Operand(result);
                            Exparray.remove(i - 1);//makes operation and removes old values.
                            Exparray.remove(i - 1);
                            Exparray.set(i - 1, operd);

                        }
                    }
                    if (Exparray.get(i).toString().equals("/")) {
                        if (Exparray.get(i - 1).getClass().toString().equals("class Operand") &&//checks if element of Expression befor and after are operand.
                                Exparray.get(i + 1).getClass().toString().equals("class Operand")) {//checks if element of Expression befor and after are operand.
                            result = Integer.valueOf(Exparray.get(i - 1).toString()) / Integer.valueOf(Exparray.get(i + 1).toString());
                            operd = new Operand(result);
                            Exparray.remove(i - 1);//makes operation and removes old values.
                            Exparray.remove(i - 1);
                            Exparray.set(i - 1, operd);

                        }
                    }
                }
                ++i;//increases index.
            }
        }
        i = counter;
        while (countOperator(counter, "+", "-")) {// counts addition and subtition in expression.
            i = counter;

            while (i<Exparray.size()&&!Exparray.get(i).toString().equals(")")) {
                if (Exparray.get(i).getClass().toString().equals("class Operator")) {//checks if element of Expression is a operator.
                    if (Exparray.get(i).toString().equals("+")) {
                        if (Exparray.get(i - 1).getClass().toString().equals("class Operand") &&//checks if element of Expression befor and after are operand.
                                Exparray.get(i + 1).getClass().toString().equals("class Operand")) {//checks if element of Expression befor and after are operand.
                            result = Integer.valueOf(Exparray.get(i - 1).toString()) + Integer.valueOf(Exparray.get(i + 1).toString());
                            operd = new Operand(result);
                            Exparray.remove(i - 1);//makes operation and removes old values.
                            Exparray.remove(i - 1);
                            Exparray.set(i - 1, operd);

                        }
                    }
                    if (Exparray.get(i).toString().equals("-")) {
                        if (Exparray.get(i - 1).getClass().toString().equals("class Operand") &&//checks if element of Expression befor and after are operand.
                                Exparray.get(i + 1).getClass().toString().equals("class Operand")) {//checks if element of Expression befor and after are operand.
                            result = Integer.valueOf(Exparray.get(i - 1).toString()) - Integer.valueOf(Exparray.get(i + 1).toString());
                            operd = new Operand(result);
                            Exparray.remove(i - 1);//makes operation and removes old values.
                            Exparray.remove(i - 1);
                            Exparray.set(i - 1, operd);

                        }
                    }
                }
                ++i;
            }
        }
        //determines bound of result Expression.
        i = counter;
        Exparray.remove(i);
        Exparray.remove(i + 1);
        while (i<Exparray.size()&&!Exparray.get(i).toString().equals(")")) {
            ++i;
        }
        //combines elements of result Expression.
        for (i = 0; i < Exparray.size(); ++i) {
            str2 = str2 + Exparray.get(i).toString() + " ";
        }

        return str2;
    }
    /**
     * counts operator for Expressions with parantesis.
     * @param begin is index of Expression which determined bound.
     * @param str1 is a operator name which is determied.
     * @param str2 is a operator name which is determied.
     * @return if pair of operator is in Expression true else false.
     */
    private boolean countOperator(int begin,String str1,String str2)
    {
        int i;
        i=begin;

        while(!Exparray.get(i).toString().equals(")")){
            if(Exparray.get(i).toString().equals(str1) || Exparray.get(i).toString().equals(str2) )//if substring contains operator return true.
                return true;
            ++i;
        }
        return false;
    }
    /**
     * calculates result of expression which doesn't have paranthesis.
     * @return result of Expression which doesn't have pharantesis.
     */
    public ArrayList<String> calculateFunction()
    {
        String Str="\0";
        ArrayList<String> strArray=new ArrayList<String>();
        int i=0,control=0;
        Str = evaluate();
        strArray.add(Str);
        while(checkPharantesisInOutput(Str))//until Expression doesn't have pharantesis.
        {
            Str = evaluate();
            strArray.add(Str);
        }
        return strArray;
    }
    /**
     * checks phrantesis is in a Expression
     * @return true if Expression contains phrantesis else false.
     */
    private boolean checkPharantesisInOutput(String str)
    {
        int i=0;
        for(i=0;i<str.length();++i)
        {
            if(str.charAt(i)=='(' ||str.charAt(i)==')')//if Expression contains pharantesis return true.
                return true;
        }
        return false;
    }
    public String evaluateWithNoPharantesis()
    {
        int i,result=0;
        String str="\0";

        while (checkOperators("*","/")) {
            for (i = 0; i < Exparray.size(); ++i) {
                if (Exparray.get(i).getClass().toString().equals("class Operator")) {// determines if type of element is operator.
                    if (Exparray.get(i).toString().equals("*")||Exparray.get(i).toString().equals("/")) {
                        if (i > 0 && Exparray.get(i - 1).getClass().toString().equals("class Operand") && i < Exparray.size() - 1 &&// determines if before element and after elements are operand operator element.
                                Exparray.get(i + 1).getClass().toString().equals("class Operand")) {// determines if before element and after elements are operand operator element.
                            if(Exparray.get(i).toString().equals("*"))
                                result = Integer.valueOf(Exparray.get(i - 1).toString()) * Integer.valueOf(Exparray.get(i + 1).toString());//implements operator.
                            if(Exparray.get(i).toString().equals("/"))
                                result = Integer.valueOf(Exparray.get(i - 1).toString()) / Integer.valueOf(Exparray.get(i + 1).toString());//implements operator.
                            operd = new Operand(result);
                            Exparray.remove(i - 1);
                            Exparray.remove(i - 1);
                            Exparray.set(i - 1, operd);

                        }
                    }
                }
            }
        }
        while (checkOperators("+","-")) {
            for (i = 0; i < Exparray.size(); ++i) {
                if (Exparray.get(i).getClass().toString().equals("class Operator")) {
                    if (Exparray.get(i).toString().equals("+")||Exparray.get(i).toString().equals("-")) {// determines if type of element is operator.
                        if (i > 0 && Exparray.get(i - 1).getClass().toString().equals("class Operand") && i < Exparray.size() - 1 &&// determines if before element and after elements are operand operator element.
                                Exparray.get(i + 1).getClass().toString().equals("class Operand")) {// determines if before element and after elements are operand operator element.
                            if(Exparray.get(i).toString().equals("+"))
                                result = Integer.valueOf(Exparray.get(i - 1).toString()) + Integer.valueOf(Exparray.get(i + 1).toString());//implements operator.
                            if(Exparray.get(i).toString().equals("-"))
                                result = Integer.valueOf(Exparray.get(i - 1).toString()) - Integer.valueOf(Exparray.get(i + 1).toString());//implements operator.
                            operd = new Operand(result);
                            Exparray.remove(i - 1);
                            Exparray.remove(i - 1);
                            Exparray.set(i - 1, operd);

                        }
                    }
                }
            }

        }
        //combines elements of result expression.
        for(i=0;i<Exparray.size();++i)
            str=str+Exparray.get(i).toString()+" ";

        return str;
    }
    /**
     * checks operator  is in a Expression which is not contains pharantesis.
     * @param str1 is aoperator name which is determined.
     * @param str2 is aoperator name which is determined.
     * @return true if Expression contains operator else false.
     */
    private boolean checkOperators(String str1,String str2)
    {
        int i;
        for(i=0;i<Exparray.size();++i)
        {
            if(Exparray.get(i).toString().equals(str1)||Exparray.get(i).toString().equals(str2) )//checks if Expression contains operators which name contained by str1 and str2 parameters.
                return true;
        }
        return false;
    }
    /**
     * checks pharantesis  is in a Expression which is not contains pharantesis.
     * @return true if Expression contains pharantesis else false.
     */
    public boolean countPharanthesis()
    {
        String str="\0";
        int i;
        for(i=0;i<Exparray.size();++i)
            str=str+Exparray.get(i).toString()+" ";

        for(i=0;i<Exparray.size();++i)
        {
            if(Exparray.get(i).toString().equals(")")||Exparray.get(i).toString().equals("(") )// if expression contains pharantesis returns true.
                return true;
        }
        return false;
    }
    /**
     * counts operators in Expression which doesn't contains pharantesis.
     * @return true if Expression contains pharantesis else false.
     */
    public boolean countOperators(String str)
    {
        int i=0;
        for(i=0;i<str.length();++i)
        {
            if(str.charAt(i)=='*'||str.charAt(i)=='/'||str.charAt(i)=='+'||str.charAt(i)=='-'&&i+1<str.length()&&str.charAt(i+1)==' ')//if expression contains operator return true.
                return true;
        }
        return false;
    }
    /**
     * calculates Expression step by step.
     * @return  result of Expression each step.
     */
    public ArrayList<String> Result()
    {
        int i=0;
        ArrayList<String> Result=new ArrayList<String>();
        String str2;
        if(!checkOperatorNums())
        {
            Result.add("Invalid Expression!");
        }
        else
        {
            if (countPharanthesis()) {//if Expression contains pharantesis
                Result = calculateFunction();
                if (countOperators(Result.get(Result.size() - 1)))
                    Result.add(evaluateWithNoPharantesis());
            } else {//if Expression doesn't contains pharantesis
                str2 = evaluateWithNoPharantesis();
                Result.add(str2);
                while (countOperators(str2)) {
                    str2 = evaluateWithNoPharantesis();//implements step of solution of Expression
                    Result.add(str2);
                }
            }
        }
        return Result;
    }
    /**
    *clears Exparray.
     */
    public void clearFunction()
    {
        Exparray.clear();//clears Exparray.
    }
}