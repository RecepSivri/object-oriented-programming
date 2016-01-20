/**
 * @author Recep Sivri
 *  Paranthesis.java part of HW10_121044038_Recep_Sivri
 * Created by Recep Sivri on 3.01.2016.
 */
public class Paranthesis implements expElemList{


    private String LeftPharantesis="\0";
    private String RightPharantesis="\0";
    private int index;

    public Paranthesis()
    {
        String LeftPharantesis="\0";
        String RightPharantesis="\0";
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
     * @return index.
     */
    public int getIndex()
    {
        return index;
    }
    /**
     * first setter for pharantesis class.
     * @param Element is a parameter which sets LeftPharantesis.
     */
    public void setElementPar(String Element)
    {
        LeftPharantesis=Element;
    }
    /**
     * first getter for pharantesis class.
     * @return which kind of pharantesis.
     */
    public String getElementPar()
    {
        return LeftPharantesis;
    }
    /**
     * second getter for pharantesis class.
     * @return which kind of pharantesis.
     */
    public String getElement2Par()
    {
        return RightPharantesis;
    }
    /**
     * second setter for pharantesis class.
     * @param Element is a parameter which sets RightPharantesis.
     */
    public void setElement2(String Element)
    {
        RightPharantesis=Element;
    }
    /**
     * toString for Parantesis class.
     * @return string format of parantesis class.
     */
    public String toString()
    {
        if(RightPharantesis.equals("\0"))
            return LeftPharantesis;
        else
            return RightPharantesis;
    }
}
