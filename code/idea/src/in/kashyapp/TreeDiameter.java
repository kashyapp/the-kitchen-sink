package in.kashyapp;

import static in.kashyapp.TreeDiameter.Tree.*;

/**
 * User: kashyapp
 * Date: 12/01/14
 */
public class TreeDiameter {
    private static Result diameter(Tree t) {
        if (t == null) {
            return Result.as(0, 0);
        }
        Result rLeft = diameter(t.left());
        Result rRight = diameter(t.right());
        int diameter = 1 + rLeft.depth + rRight.depth;
        diameter = Math.max(diameter, rLeft.diameter);
        diameter = Math.max(diameter, rRight.diameter);
        return Result.as(1 + Math.max(rLeft.depth, rRight.depth), diameter);
    }

    static class Result {
        private final int depth;
        private final int diameter;

        public Result(int depth, int diameter) {
            this.depth = depth;
            this.diameter = diameter;
        }

        public static Result as(int depth, int diameter) {
            return new Result(depth, diameter);
        }
    }

    static class Tree {
        static final Tree leaf = T(null, null);

        private final Tree left;
        private final Tree right;

        private Tree(Tree left, Tree right) {
            this.left = left;
            this.right = right;
        }

        static Tree T(Tree left, Tree right) {
            return new Tree(left, right);
        }

        public Tree left() {
            return left;
        }

        public Tree right() {
            return right;
        }
    }

    public static void main(String[] args) {
        verify(1, leaf);
        verify(5, T(
            null,
            T(
                T(leaf, leaf),
                T(leaf, leaf))));
        verify(9, T(
            T(leaf, T(leaf, leaf)),
            T(
                null,
                T(
                    null,
                    T(
                        T(leaf, leaf),
                        leaf)))));
    }

    private static void verify(int expected, Tree t) {
        int found = diameter(t).diameter;
        if (found != expected)
            System.err.println("Found: " + found + ", Expected: " + expected);
    }
}
