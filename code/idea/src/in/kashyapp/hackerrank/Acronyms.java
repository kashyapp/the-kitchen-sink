package in.kashyapp.hackerrank;

import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * User: kashyapp
 * Date: 20/12/13
 */
public class Acronyms {
    public static void main(String[] args) {
        final Scanner in = new Scanner(System.in);
        int n = in.nextInt(); in.nextLine();
        String[] snippets = new String[n];
        for (int i = 0; i < n; i++) {
            snippets[i] = in.nextLine();
        }
        for (int i = 0; i < n; i++) {
            String q = in.next();
//            System.err.print(q + ":\t\t");
            System.out.println(expand(snippets, q));
        }
    }

    private static String expand(String[] snippets, String q) {
        for (String snippet : snippets) {
            Matcher matcher = Pattern.compile("(?i)\\b" + q + "\\b").matcher(snippet);
            if (matcher.find()) {
                int limit = matcher.start();
                return define(q, snippet, limit);
            }
        }
        return q;
    }

    private static String define(String q, String snippet, int limit) {
        final String searchSpace = snippet.substring(0, limit);

        final String regex = "\\b" + q.replaceAll("\\B", "[A-Za-z0-9' -]*?") + "[A-Za-z0-9' -]*?\\b";
//        System.err.println(regex);
        {
            final Matcher matcher = Pattern.compile(regex).matcher(searchSpace);
            if (matcher.find()) {
                return matcher.group();
            }
        }
        {
            final Matcher matcher = Pattern.compile(regex, Pattern.CASE_INSENSITIVE).matcher(searchSpace);
            if (matcher.find()) {
                return matcher.group();
            }
        }

        return q;
    }
}
