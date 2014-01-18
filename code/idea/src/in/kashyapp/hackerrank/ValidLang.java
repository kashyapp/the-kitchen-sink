package in.kashyapp.hackerrank;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * User: kashyapp
 * Date: 25/12/13
 */
public class ValidLang {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(); in.nextLine();
        while (n > 0) {
            n--;
            in.nextInt();in.skip(" ");
            String s = in.nextLine();
            System.out.println(languages.contains(s) ? "VALID" : "INVALID");
        }
    }

    private static final Set<String> languages = new HashSet<String>(Arrays.asList(
            "BASH",
            "BRAINFUCK",
            "C",
            "CLISP",
            "CLOJURE",
            "CPP",
            "CSHARP",
            "D",
            "DART",
            "ERLANG",
            "GO",
            "GROOVY",
            "HASKELL",
            "JAVA",
            "JAVASCRIPT",
            "LUA",
            "OBJECTIVEC",
            "OCAML",
            "PASCAL",
            "PERL",
            "PHP",
            "PYTHON",
            "R",
            "RUBY",
            "SBCL",
            "SCALA"
    ));
}
