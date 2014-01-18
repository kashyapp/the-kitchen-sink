package in.kashyapp.hackerrank;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;
import java.util.regex.Pattern;

/**
 * User: kashyapp
 * Date: 22/12/13
 */
public class Segmentation {
    private static final Set<String> dictionary = new HashSet<String>();

    public static void main(String[] args) throws FileNotFoundException {
        init();

        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        while (n > 0) {
            n--;
            String q = in.next();
            String qs = scrub(q);
            segment(qs);
        }
    }

    private static void segment(String qs) {
        Pattern allDigits = Pattern.compile("\\d+");
        int[] jump = new int[qs.length() + 1];
        jump[qs.length()] = qs.length();

        for (int i = qs.length() - 1; i >= 0; i--) {
            inner:
            for (int j = qs.length(); j > i; j--) {
                if (jump[j] != 0) {
                    String temp = qs.substring(i, j);
                    if (dictionary.contains(temp) || allDigits.matcher(temp).matches()) {
                        jump[i] = j;
                        break inner;
                    }
                }
            }
        }
        if (jump[0] > 0) {
            for (int i = 0; i < qs.length(); i = jump[i]) {
                if (i > 0) System.out.print(' ');
                System.out.print(qs.substring(i, jump[i]));
            }
            System.out.println();
        } else {
            System.out.println(qs);
        }
    }

    private static void init() throws FileNotFoundException {
        Scanner fin = new Scanner(new File("words.txt"));
        while (fin.hasNextLine()) {
            String str = fin.nextLine();
            dictionary.add(str.toLowerCase());
        }
    }

    private static String scrub(String q) {
        return q.replace("#","")
                .replaceAll("^w+\\.","")
                .replaceAll("\\..*$","")
                ;
    }
}
