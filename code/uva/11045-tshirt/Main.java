import java.util.*;

class Main {
    enum Size {XS, S, M, L, XL, XXL};
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int nTest = in.nextInt();

        while (nTest-- > 0) {
            int n = in.nextInt();
            int m = in.nextInt();

            int numSizes = Size.values().length;
            int[] sizes = new int[numSizes];
            int[][] allOptions = new int[m][];

            for (int i = 0; i < m; ++i) {
                int s1 = Size.valueOf(in.next()).ordinal();
                int s2 = Size.valueOf(in.next()).ordinal();
                allOptions[i] = new int[]{s1, s2};
            }

            for (int i = 0; i < numSizes; ++i) { sizes[i] = n / numSizes; }

            System.out.println(solve(sizes, allOptions, 0) ? "YES" : "NO");
        }
    }

    static boolean solve(int[] sizes, int[][] optionsItr, int index) {
        if (optionsItr.length == index) return true;
        int[] options = optionsItr[index];
        for (int option : options) {
           if (sizes[option] > 0) {
               sizes[option] = sizes[option] - 1;
               boolean inner = solve(sizes, optionsItr, index + 1);
               sizes[option] = sizes[option] + 1;
               if (inner) {
                   //System.err.printf("%s\n", Size.values()[option]);
                   return inner;
               }
           }
        }
        return false;
    }
}
