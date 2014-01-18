package in.kashyapp.maxsum;

import com.google.common.collect.Lists;

import java.util.ArrayList;
import java.util.Scanner;

import static com.google.common.collect.Lists.newArrayList;

/**
 * User: kashyapp
 * Date: 07/12/13
 */
public class MaxSumSubArray {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        ArrayList<Integer> data = newArrayList();
        ArrayList<Integer> sums = newArrayList();
        ArrayList<Integer> starts = newArrayList();

        while (in.hasNextInt()) {
            data.add(in.nextInt());
        }

        sums.add(data.get(0)); starts.add(0);

        for (int i = 1; i < data.size(); i++) {
            int start = i;
            int sum = data.get(i);
            int sumPrevious = sums.get(i-1);
            if (sumPrevious > 0) {
                sum += sumPrevious;
                start = starts.get(i-1);
            }
            sums.add(sum);
            starts.add(start);
        }

        System.out.println(sums);
        System.out.println(starts);
    }
}
