package in.kashyapp.hackerrank;

import com.google.common.base.Joiner;
import com.google.common.collect.Sets;
import com.google.common.io.CharStreams;

import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.SortedSet;
import java.util.TreeSet;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * User: kashyapp
 * Date: 20/12/13
 */
public class HtmlTags {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(); in.nextLine();

        StringBuilder sb = new StringBuilder();
        while(n > 0) {
            n--;
            sb.append(in.nextLine());
        }

        String ss = sb.toString().replaceAll("<!--.?-->","");

        Matcher matcher = Pattern.compile("< *([a-z0-9]+).*?>", Pattern.CASE_INSENSITIVE).matcher(ss);
        SortedSet<String> tags = new TreeSet<String>();
        while (matcher.find()) {
            tags.add(matcher.group(1).toLowerCase());
        }

        boolean first = true;
        for (String tag : tags) {
            if (!first) {
                System.out.print(";");
            } else {
                first = false;
            }
            System.out.print(tag);
        }
        System.out.println("");
    }

    public static void main2(String[] args) throws IOException {
        SortedSet<String> tags = Sets.newTreeSet();
        Pattern pattern = Pattern.compile("< *([a-z]+)[^>]*>");
        String bzz = CharStreams.toString(new InputStreamReader(System.in));
        Matcher matcher = pattern.matcher(bzz);
        while (matcher.find()) {
            tags.add(matcher.group(1));
        }
        System.out.println(Joiner.on(';').join(tags));
    }
}
