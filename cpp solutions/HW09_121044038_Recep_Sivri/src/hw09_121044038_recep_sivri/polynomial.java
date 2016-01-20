/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package hw09_121044038_recep_sivri;
import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author Recep Sivri
 *  polynomial.java part of HW09_121044038_Recep_Sivri
 */
public class polynomial {
    
    private int capacity;
    private int using;
    private double [] darr;
    public polynomial() 
    {
        darr = new double[] {};
        capacity=0;
        using=0;
    }
    /*
    * @param array contains coefficient of polçynomial.
    */
    public polynomial(double [] array) 
    {
        darr = new double[array.length];
        capacity=array.length;
        int i;
        for(i=0;i<array.length;++i)
        {
            darr[array.length-i-1]=array[i];
        }
        using=capacity;
    }
    /*
    * setter for using
    *@param value is number for set using.
    */
    public void setUsing(int value)
    {
        using=value;
    }
    /*
    * getter for using.
    * @return value of using
    */
    public int getUsing()
    {
       return using;
    }
    /*
    *setter for capacity.
    *@param size is set value for capacity.
    */
    public void setCapacity(int size)
    {
        capacity=size;   
    }
    /*
    *getter for capacity. 
    *@return capacity 
    */
    public int getCapacity(){return capacity;}
    /*
    *getter for coefficient array.
    *@return double array which is coefficients of polynomials. 
    */
    public double[]getCoeffiecent(){return darr;}
    /*
    *getter for element in coefficient array.
    *@param index is index of coefficient array which is returned
    *@return element in index of coefficient array.
    */
    public double getElementOfCoffArr(int index)
    {
        if(index<capacity)
            return darr[index];
        else
        {
            System.out.println(index+" is more then capacity!");
            return 0;
        }
    }
    /*
    *setter for a element in coefficient array. 
    *@param value is a element for set a element in coefficient array with index parameter.
    *@param index is a parameter index of element for setting element in coefficient array.
    */
    public void setElementOfCoffArr(double value,int index)
    {
        if(index<capacity)
            darr[index]=value;
        else
            System.out.println(value+" couldn't set because"+index +"  is more then capacity !");
        ++using;
    } 
    /*
    *returns string for polynomial type.
    *@return string which is format of polynomial type.
    */
    public String toString()
    {
        int i;
        String str="\0";
      
        for(i=capacity-1;i>=0;--i)
        {   
            if(i==0)
                str=str+darr[i];
            else  
            str=str+darr[i]+"X^"+i+" + ";
        } 
        return str;
    }
    /*
    *setter for coefficient array in polynomial object.
    *@param coefArr which is coefficient array for set coefficient array in polynomial objects.
    */
    public void setCoeffArray(double [] coefArr)
    {
        int i;
        darr=new double[coefArr.length];
        capacity=coefArr.length;
        using=coefArr.length;
        for(i=0;i<capacity;++i)
            darr[i]=coefArr[i];
    }
    /*
    *setter for size of coefficient array in polynomial object
    *@param size is size of coefficient array in polynomial object.
    */
    public void setCoeffArray(int  size)
    {
        darr=new double[size];
        capacity=size;
        using=0;
    }
    /*
    *addFunct is a fuction which makes addition process for polynomial objects.
    *@param poly2 is a object of polynomial class for adds with another object of polynomial.
    *@return result of addition.
    */
    public polynomial addFunct(polynomial poly2)
    {
        int i,tempSize;
        polynomial p=new  polynomial();
        double []darr2;
        if(capacity<poly2.getCapacity())
        {
            tempSize=capacity;
            p.setCoeffArray(poly2.getCoeffiecent());
            for(i=0;i<tempSize;++i)
            {
                p.setElementOfCoffArr(darr[i]+poly2.getElementOfCoffArr(i),i);
            }
            
        }  
        else
        {  
            tempSize= poly2.getCapacity();
            p.setCoeffArray(darr);
            for(i=0;i<tempSize;++i)
            {
                p.setElementOfCoffArr(darr[i]+poly2.getElementOfCoffArr(i),i);
            }
        }
        return p;
    }
    /*
    *subFunct is a fuction which makes substraction process for polynomial objects.
    *@param poly2 is a object of polynomial class for substracts with another object of polynomial.
    *@return result of substraction.
    */
    public polynomial subFunct(polynomial poly2)
    {
        int i,tempSize;
        polynomial p=new  polynomial();
        double []darr2;
        if(capacity<poly2.getCapacity())
        {
            tempSize=capacity;
            p.setCoeffArray(poly2.getCoeffiecent());
            for(i=0;i<tempSize;++i)
            {
                p.setElementOfCoffArr(darr[i]-poly2.getElementOfCoffArr(i),i);
            }
            for(i=tempSize;i<poly2.getCapacity();++i)
            {
                p.setElementOfCoffArr(poly2.getElementOfCoffArr(i)*-1,i);
            }
        }  
        else
        {  
            tempSize= poly2.getCapacity();
            p.setCoeffArray(darr);
            for(i=0;i<tempSize;++i)
            {
                p.setElementOfCoffArr(darr[i]-poly2.getElementOfCoffArr(i),i);
            }
        }
        return p;
    }
    /*
    *counterMultiplicant is a fuction which makes a size of array for multiplication.
    *@param poly2 is a object of polynomial class for multiple with another object of polynomial.
    *@return size of array of results of multiplication.
    */
    private int counterMultiplicant(polynomial poly2)
    {
        int i,j,counter=0;
        for(i=0;i<capacity;++i)
        {
            for(j=0;j<poly2.getCapacity();++j)
                ++counter;
        }
        return counter;
    }
    /*
    *MultFunct is a fuction which makes multiplication process for polynomial objects.
    *@param poly2 is a object of polynomial class for multiples with another object of polynomial.
    *@return result of multiplication.
    */
    public polynomial MultFunct(polynomial poly2)
    {
        polynomial pol=new polynomial();
        int counter,i,j,index=0;
        counter=counterMultiplicant(poly2);
        
        int []arri=new int[counter];
        double total=0;
        double []arrd=new double[counter];
        for(i=0;i<capacity;++i)
        {
            for(j=0;j<poly2.getCapacity();++j)
            {
                arri[index]=i+j;
                arrd[index]=darr[i]*poly2.getElementOfCoffArr(j);
                ++index;
            }
        }
        pol.setCoeffArray(capacity+poly2.getCapacity());
        for(i=0;i<capacity+poly2.getCapacity()-1;++i)
        {
            for(j=0;j<index;++j)
            {
                if(arri[j]==i)
                {
                    total=total+arrd[j];
                }
            }
            pol.setElementOfCoffArr(total, i);
            total=0;
        }
        pol.capacity=pol.using;
        return pol;
    }
    /*
    *calculates result of polynomial for x value and returns result.
    *@param x is a value for calculate result of polynomial.
    *@return result of polynomial for x value.
    */
    public double returnResultOfPolynomial(double x)
    {
        double result=0,result2=1;
        int i,j;
        for(i=0;i<capacity;++i)
        {
            for(j=0;j<i;++j)
            {
                result2=result2*x;
            }
            result=result+result2*darr[i];
            result2=1;
        }
        return result;
    }
    /*
    *checks if  two objects of polynomial are equal.
    *@param other is a polynomial object which is compared with another polynomial objects.
    *@returns if 1 objects are equals else returns 0.
    */
    int equals(polynomial other)
    {
        int i;
        if(other.getCapacity()==capacity)
        {
            for(i=0;i<capacity;++i)
            {
                if(darr[i]!=other.getElementOfCoffArr(i))
                    return 0;
            }
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

