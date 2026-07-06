class Solution 
{
    public boolean isPowerOfThree(int n) 
    {
        if(n<=0)
        {
            return false;
        }
        long x=1;
        while(x<n)
        {
            x=x*3;
        }
        if(x==n)
        {
            return true;
        }
        else{
            return false;
        }
    }
}