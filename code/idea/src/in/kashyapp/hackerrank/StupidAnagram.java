package in.kashyapp.hackerrank;

import java.util.Scanner;

/**
 * User: kashyapp
 * Date: 20/12/13
 */
public class StupidAnagram {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        while (n > 0) {
            n--;
            String s = in.next();
            int len = s.length();
            int result = -1;
            if (len%2 == 0) {
                result = check(s);
            }
            System.out.println(result);
        }
    }

    private static int check(String s) {
        int l = s.length() / 2;
        int[] left = new int[26];
        for (int i = 0; i < l; ++i) {
            int p = s.charAt(i) - 'a';
            left[p]++;
        }
        for (int i = l; i < 2*l; ++i) {
            int p = s.charAt(i) - 'a';
            left[p]--;
        }
        int count = 0;
        for (int i = 0; i < 26; ++i) {
            count += Math.abs(left[i]);
        }
        return count/2;
    }
}
