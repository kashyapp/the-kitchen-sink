package in.kashyapp.maxsum;

import java.util.Scanner;

/**
 * User: kashyapp
 * Date: 07/12/13
 */
public class SubMatrix {
    final int[][] data;
    final int m, n;

    private SubMatrix(int[][] data, int m, int n) {
        this.data = data;
        this.m = m;
        this.n = n;
    }

    private void solve() {

    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int m = in.nextInt();
        int n = in.nextInt();


        int[][] data = new int[m][];

        for (int i = 0; i < m; ++i) {
            data[i] = new int[n];
            for (int j = 0; j < m; ++j) {
                data[i][j] = in.nextInt();
            }
        }

        SubMatrix matrix = new SubMatrix(data, m, n);
    }
}
