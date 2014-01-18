package in.kashyapp;

import com.google.common.collect.*;

import java.util.Arrays;
import java.util.Set;
import java.util.SortedSet;

/**
 * User: kashyapp
 * Date: 18/01/14
 */
public class LongestArithmeticProgression {
    public static void main(String[] args) {
        verify(0);
        verify(1, 1);
        verify(2, 1, 7, 11, 19);
        verify(3, 1, 2, 3);
        verify(3, 1, 2, 3, 5);
        verify(5, 1, 2, 3, 5, 7, 9);
        verify(3, 1, 7, 10, 15, 27, 29);
    }

    private static int lapl(int[] numbers) {
        if (numbers.length > 1) {
            int result = 0;
            Arrays.sort(numbers);
            HashMultimap<Integer, Integer> graph = buildGraph(numbers);
            for (int start : numbers) {
                for (int next : graph.get(start)) {
                    int len = 2 + walk(graph, next, next - start);
                    if (len > result) result = len;
                }
            }
            return result;
        } else {
            return numbers.length;
        }
    }

    private static int walk(final Multimap<Integer, Integer> graph, final int next, final int step) {
        if (graph.remove(next, next + step)) {
            return 1 + walk(graph, next + step, step);
        }
        return 0;
    }

    private static HashMultimap<Integer, Integer> buildGraph(int[] numbers) {
        HashMultimap<Integer, Integer> graph =  HashMultimap.create();
        for (int i = 0; i < (numbers.length - 1); i++) {
            for (int j = i+1; j < numbers.length; j++) {
                graph.put(numbers[i], numbers[j]);
            }
        }
        return graph;
    }

    private static void verify(int expected, int... input) {
        int output = lapl(input);
        if (expected != output)
            System.err.printf("Bad: %s, expected: %d, got: %d\n", Arrays.toString(input), expected, output);
    }
}
