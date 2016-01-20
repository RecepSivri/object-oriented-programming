/**
 * @author Recep Sivri
 *  Operator.java part of HW10_121044038_Recep_Sivri
 * Created by Recep Sivri on 3.01.2016.
 */
public class Operator implements expElemList{

    private String opName="\0";
    private int index;
    /**
     * getter for Operator Class.
     * @return  name of operation.
     */
    public String getElementOp(){return opName;}
    /**
     * setter for Operator Class.
     * @param Element  set value for name of operation.
     */
    public void setElementOp(String Element)
    {opName=Element;}
    /**
     * setter for Index value.
     * @param Element  set value index.
     */
    public void setIndex(int Element)
    {
        index=Element;
    }
    /**
     * getter for Index value.
     * @return index.
     */
    public int getIndex()
    {
        return index;
    }
    /**
     * toString function for Operation Class.
     * @return name of Operation.
     */
    public String toString()
    {
        return opName;

    }
}
