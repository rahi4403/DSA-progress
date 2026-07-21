class Solution { //Sieve of Eratosthenes method 
public:
    int countPrimes(int n) {
        int count=0;
        vector<bool> prime(n+1,true); //this is to create a boolean array,and we assume that every number is prime,hence we place true at the beginning
        prime[0]=prime[1]=false; //since 0 and 1 are not prime we omit them at the very beginning
        for(int i=2;i<n;i++){ //0 & 1 have been omitted already so we start the loop from 2
            if(prime[i]){
                count++;
                for(int j=2*i;j<n;j+=i) //this loop visits all the multiples of the number which has been called prime in the if(prime[i]),the entire loop checks for the multiples since the multiples will never be prime right?
                prime[j]=0;//which is why we call them not prime(0-false)
                }
        }
        return count;
    }
};