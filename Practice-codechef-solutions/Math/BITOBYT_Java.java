import java.util.Scanner;
class Codechef{

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t=scan.nextInt();
        while(t-->0){
            int n=scan.nextInt();
            n--;
            
            long bits=1,nibbles=0,bytes=0;
            while(n>1)
            {
                
                if(n>=2)
                {
                    n=n-2;
                    nibbles=bits;
                    bits=0;
                    
                }
                else
                {
                    break;
                }
                if(n>=8)
                {
                    n=n-8;
                    bytes=nibbles;
                    nibbles=0;
                    
                }
                else{
                    break;
                }    
                if(n>=16)
                {
                    n=n-16;
                    bits=2*bytes;
                    bytes=0;
                }
                else
                    break;
            }
            System.out.println(bits+" "+nibbles+" "+bytes);
        }
    }
}    
