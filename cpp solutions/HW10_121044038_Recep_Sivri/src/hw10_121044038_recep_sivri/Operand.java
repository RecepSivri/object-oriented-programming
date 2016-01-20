/**
 * @author Recep Sivri
 *  Operand.java part of HW10_121044038_Recep_Sivri
 * Created by Recep Sivri on 3.01.2016.
 */
public class Operand implements expElemList
{
    private int Number=0;
    private String str="\0";
    private int index;
    public Operand()
    {
        Number=0;
        str="\0";
    }
    public Operand(int value)
    {
        Number=value;
        str=value+"";
    }
    /**
     * setter for Index value.
     * @param Element is a value of index.
     */
    public void setIndex(int Element)
    {
        index=Element;
    }
    /**
     * getter for Index value.
     * @return index value.
     */
    public int getIndex()
    {
        return index;
    }
    /**
     * setter for Operand Class.
     * @param Element is a value of operand.
     */
    public void setElementOpnd(String Element)
    {
        Number= Integer.valueOf(Element);
        str=Element;
    }
    /**
     * determines string format for Operand Class.
     * @return String format of Operand.
     */
    public String toString()
    {
        return Number+"";
    }
}
