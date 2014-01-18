package in.kashyapp.hackerrank;

import java.util.Scanner;

/**
 * User: kashyapp
 * Date: 20/12/13
 */
public class LatLong {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(); in.nextLine();
        for (; n>0; n--) {
            String s = in.nextLine();
            System.out.println(valid(s)?"Valid":"Invalid");
        }
    }

    private static boolean valid(String s) {
        return s.matches("\\(" +
                "[+-]?" +
                "([1-8]?[0-9](|\\.[0-9]+)|90(|\\.0+))" +
                ", " +
                "[+-]?" +
                "((1[0-7]|[1-9]?)[0-9](|\\.[0-9]+)|180(|\\.0+))" +
                "\\)");
    }
}
