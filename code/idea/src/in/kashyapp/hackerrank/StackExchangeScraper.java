package in.kashyapp.hackerrank;

import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * User: kashyapp
 * Date: 25/12/13
 */
public class StackExchangeScraper {
    enum Language {C, CPP}
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        while (in.hasNext()) {
            sb.append(' ').append(in.nextLine());
        }
        Matcher matcher = Pattern.compile("<a href=\"/questions/(\\d+)/[^\"]*\" class=\"question-hyperlink\">(.*?)</a>.*?class=\"relativetime\">(.*?)</span>").matcher(sb);
        while (matcher.find()) {
            System.out.format("%s;%s;%s\n", matcher.group(1), matcher.group(2), matcher.group(3));
        }
        
    }
}
