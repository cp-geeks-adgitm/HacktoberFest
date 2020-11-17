package GFG;
import java.util.*;
public class FindFibonacciSeqFromString {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	class Solution {
	    List<Integer> ans;
	    public List<Integer> splitIntoFibonacci(String s) {
	      // if(s.charAt(0)=='0')  return new ArrayList<>();
	        ans=new ArrayList<>();
	        cuts(s,0,new ArrayList<>());
	        return ans;
	    }
	    
	 
	    public boolean cuts(String s,int i,List<Integer> list){
	        if(i>=s.length()){  
	            if(list.size()>2 && ans.size()==0){
	                 ans=new ArrayList<>(list);
	                return true;
	            }
	           
	            return false;
	        }
	        for(int idx=i;idx<s.length();idx++){
	            if(s.charAt(i)=='0' && idx>i) return false;// for handling 0                                                                            the 0 case in starting 
	            String c=s.substring(i,idx+1);
	            long num=Long.parseLong(c);
	            
	            if(num>Integer.MAX_VALUE) break;// as acc to ques value cant be greater than Integermaxvalue
	            
	            if(list.size()<2){
	             list.add((int)num);   
	            }else{
	                if(num==list.get(list.size()-1)+list.get(list.size()-2)){
	                    list.add((int)num);
	                }else{
	                    continue;
	                }     
	            }
	            if( cuts(s,idx+1,list)) return true;
	            
	            list.remove(list.size()-1);   
	        }
	        return false;
	    }
	}

}
