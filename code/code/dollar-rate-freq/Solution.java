import java.io.*;
import java.util.HashMap;
import java.util.Scanner;


public class Solution {
    public static void main(String args[] ) throws Exception {
        //HashMapto store the data points.
        HashMap<Integer, Integer> dataPoints = new HashMap<Integer, Integer>();
        //Use hashmap with dollar rate as key and number of occurences as value.
        //Assumption is that the dollar rate is integer.
        HashMap<Integer, Integer> freqCount = new HashMap<Integer, Integer>();
        Scanner scanIn = new Scanner(System.in);
		int dataPointCount = scanIn.nextInt();
        int maxDataPoint = Integer.MIN_VALUE;
        for(int i=0;i<dataPointCount;i++){
            int day = scanIn.nextInt();
            int value = scanIn.nextInt();
            dataPoints.put(day,value);    
            if(day > maxDataPoint)
                maxDataPoint = day;
        }
        int startDay = scanIn.nextInt();
        int endDay = scanIn.nextInt();
        
        for(int day = startDay;day<endDay;day++){
        	int dollarRate = getDollarRate(day, dataPoints);
            if(day > maxDataPoint)
                break;
            //System.out.println(day + " : " + dollarRate);
            updateFrequency(dollarRate, freqCount);
        }
        
        int maxValue = 0, maxOccurence = 0;
        for(Integer value:freqCount.keySet()){
          System.out.println(value + " -> " + freqCount.get(value));
            if(freqCount.get(value) > maxOccurence){
                maxValue = value;
                maxOccurence = freqCount.get(value);
            }
        }
        System.out.println(maxValue);
        scanIn.close();
    }
    
    private static void updateFrequency(int dollar, HashMap<Integer, Integer> freq){
        if(freq.containsKey(dollar)){
            freq.put(dollar, freq.get(dollar)+1);
        }else{
           freq.put(dollar,1);
        }
    }
    
    
   private static int getDollarRate(int day, HashMap<Integer, Integer> map){
        //If end day is beyond last day, we assume that the last day 
        //rate is applicable on that day(mentioned in the problem).
        while(!map.containsKey(day)){
            day--;
        }
        return map.get(day);
    }
    
    
}
