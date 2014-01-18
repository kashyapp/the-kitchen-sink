package in.kashyapp.hackerrank;

import java.util.Scanner;
import java.util.SortedSet;
import java.util.TreeSet;

/**
 * User: kashyapp
 * Date: 11/01/14
 * https://www.hackerrank.com/challenges/quadrant-queries
 */
public class QuadrantQueries {
    static final int[][] boo = {{2, 1}, {3, 0}};
    static final int[] X = {3, 2, 1, 0};
    static final int[] Y = {1, 0, 3, 2};

    enum Op {X, Y;

        public void apply(SortedSet<Object> pending, int start, int end) {

        }
    };

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int[] qds = new int[n];

        for (int i = 0; i < n; ++i) {
            int x = in.nextInt() > 0 ? 1 : 0;
            int y = in.nextInt() > 0 ? 1 : 0;
            int q = boo[x][y];
            qds[i] = q;
        }

        SortedSet<Object> pending = new TreeSet<Object>();

        int queries = in.nextInt();
        while (queries > 0) {
            --queries;
            char c = in.next().charAt(0);
            int start = in.nextInt() - 1;
            int end = in.nextInt();
            switch (c) {
                case 'C':
                    count(qds, start, end);
                    break;
                case 'X':
                    Op.X.apply(pending, start, end);
                    break;
                case 'Y':
                    Op.Y.apply(pending, start, end);
                    break;
                default:
                    assert(false);
            }
        }
    }

    private static void count(int[] qds, int start, int end) {
        int[] counts = new int[4];
        for (int i = start; i < end; i++) {
            counts[qds[i]]++;
        }
        for (int i : counts) {
            System.out.print(i + " ");
        }
        System.out.println("");
    }

    private static void mirror(int[] qds, int start, int end, int[] mirrer) {
        for (int i = start; i < end; i++) {
            qds[i] = mirrer[qds[i]];
        }
    }
}
