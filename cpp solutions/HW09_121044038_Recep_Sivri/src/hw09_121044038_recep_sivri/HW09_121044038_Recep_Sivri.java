/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw09_121044038_recep_sivri;
import java.util.Scanner;
/**
 *
 * @author Recep Sivri
 *  main part of HW09_121044038_Recep_Sivri
 * made by Recep Sivri on 24/12/2015.
 */
public class HW09_121044038_Recep_Sivri {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
           double []darr={1,1};
           double []darr2={1,-1,1};
           double []darr3={1,2,1};
           double []darr4={1,2,1};
           double []darr5={3,4,5};
           double []darr6={5,2,3,4};
           int i;
           polynomial p1=new polynomial(darr);
           polynomial p2=new polynomial(darr2);
           polynomial p3=new polynomial(darr3);
           polynomial p4=new polynomial(darr4);
           polynomial p5=new polynomial(darr5);
           polynomial p6=new polynomial(darr6);
           
           System.out.println("----------Testing toString Function-------------");
           System.out.println("p1=  "+p1.toString());
           System.out.println("p2=  "+p2.toString());
           System.out.println("p3=  "+p3.toString());
           System.out.println("p4=  "+p4.toString());
           System.out.println("p5=  "+p5.toString());
           System.out.println("p6=  "+p6.toString());
           
           System.out.println("----------Testing equals Function-------------");
           if(p1.equals(p2)==1)
               System.out.println("p1==p2   ======>        "+p1+"  ==  "+p2);
           else
               System.out.println("p1!=p2   ======>        "+p1+"  !=  "+p2);  
           if(p3.equals(p4)==1)
               System.out.println("p3==p4   ======>        "+p3+"  ==  "+p4); 
           else
               System.out.println("p3!=p4   ======>        "+p3+"  !=  "+p4); 
           if(p5.equals(p6)==1)
               System.out.println("p5==p6   ======>        "+p5+"  ==  "+p6); 
           else
               System.out.println("p5!=p6   ======>        "+p5+"  !=  "+p6); 
           if(p2.equals(p3)==1)
               System.out.println("p2==p3   ======>        "+p2+"  ==  "+p3); 
           else
               System.out.println("p2!=p3   ======>        "+p2+"  !=  "+p3);
           if(p1.equals(p6)==1)
               System.out.println("p1==p6   ======>        "+p1+"  ==  "+p6); 
           else
               System.out.println("p1!=p6   ======>        "+p1+"  !=  "+p6);
           
           
           System.out.println("----------Testing addFunct Function-------------");
           
           System.out.println("p1+p2 == "+"  "+"("+p1+")"+" +  "+"("+p2+")"+"  "+"==  "+ p1.addFunct(p2).toString() );
           System.out.println("p2+p3 == "+"  "+"("+p2+")"+" +  "+"("+p3+")"+"  "+"==  "+ p2.addFunct(p3).toString() );
           System.out.println("p3+p4 == "+"  "+"("+p3+")"+" +  "+"("+p4+")"+"  "+"==  "+ p3.addFunct(p4).toString() );
           System.out.println("p4+p5 == "+"  "+"("+p4+")"+" +  "+"("+p5+")"+"  "+"==  "+ p4.addFunct(p5).toString() );
           System.out.println("p5+p6 == "+"  "+"("+p5+")"+" +  "+"("+p6+")"+"  "+"==  "+ p5.addFunct(p6).toString() );
           System.out.println("p6+p1 == "+"  "+"("+p6+")"+" +  "+"("+p1+")"+"  "+"==  "+ p6.addFunct(p1).toString() );
           
           System.out.println("----------Testing subFunct Function-------------");
           
           System.out.println("p1-p2 == "+"  "+"("+p1+")"+" -  "+"("+p2+")"+"  "+"==  "+ p1.subFunct(p2).toString() );
           System.out.println("p2-p3 == "+"  "+"("+p2+")"+" -  "+"("+p3+")"+"  "+"==  "+ p2.subFunct(p3).toString() );
           System.out.println("p3-p4 == "+"  "+"("+p3+")"+" -  "+"("+p4+")"+"  "+"==  "+ p3.subFunct(p4).toString() );
           System.out.println("p4-p5 == "+"  "+"("+p4+")"+" -  "+"("+p5+")"+"  "+"==  "+ p4.subFunct(p5).toString() );
           System.out.println("p5-p6 == "+"  "+"("+p5+")"+" -  "+"("+p6+")"+"  "+"==  "+ p5.subFunct(p6).toString() );
           System.out.println("p6-p1 == "+"  "+"("+p6+")"+" -  "+"("+p1+")"+"  "+"==  "+ p6.subFunct(p1).toString() );
           
           System.out.println("----------Testing multFunct Function-------------");
           
           System.out.println("p1*p2 == "+"  "+"("+p1+")"+" *  "+"("+p2+")"+"  "+"==  "+ p1.MultFunct(p2).toString() );
           System.out.println("p2*p3 == "+"  "+"("+p2+")"+" *  "+"("+p3+")"+"  "+"==  "+ p2.MultFunct(p3).toString() );
           System.out.println("p3*p4 == "+"  "+"("+p3+")"+" *  "+"("+p4+")"+"  "+"==  "+ p3.MultFunct(p4).toString() );
           System.out.println("p4*p5 == "+"  "+"("+p4+")"+" *  "+"("+p5+")"+"  "+"==  "+ p4.MultFunct(p5).toString() );
           System.out.println("p5*p6 == "+"  "+"("+p5+")"+" *  "+"("+p6+")"+"  "+"==  "+ p5.MultFunct(p6).toString() );
           System.out.println("p6*p1 == "+"  "+"("+p6+")"+" *  "+"("+p1+")"+"  "+"==  "+ p6.MultFunct(p1).toString() );
           
           System.out.println("----------Testing returnResultOfPolynomial Function-------------");
           
           System.out.println("p1(4) == "+p1.returnResultOfPolynomial(4));
           System.out.println("p2(5) == "+p2.returnResultOfPolynomial(5));
           System.out.println("p3(6) == "+p3.returnResultOfPolynomial(6));
           System.out.println("p4(12) == "+p4.returnResultOfPolynomial(12));
           System.out.println("p5(15) == "+p5.returnResultOfPolynomial(15));
           System.out.println("p6(8) == "+p6.returnResultOfPolynomial(8));
    }
    
    
}
