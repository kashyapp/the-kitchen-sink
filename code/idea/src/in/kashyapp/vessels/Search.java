package in.kashyapp.vessels;

import com.google.common.collect.Lists;
import com.google.common.collect.Maps;
import com.google.common.collect.Queues;

import java.util.*;

import static in.kashyapp.vessels.Search.State.NULL;
import static in.kashyapp.vessels.Search.State.state;

/**
 * User: kashyapp
 * Date: 09/12/13
 */
public class Search {
    final int[] capacities;

    public Search(int... capacities) {
        this.capacities = capacities;
    }

    static class State {
        public static final State NULL = state();
        final int[] values;

        State(int[] values) {
            this.values = values;
        }

        static State state(int... values) {
            return new State(values);
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            State state = (State) o;

            if (!Arrays.equals(values, state.values)) return false;

            return true;
        }

        @Override
        public int hashCode() {
            return Arrays.hashCode(values);
        }

        public int size() {
            return values.length;
        }

        @Override
        public String toString() {
            return Arrays.toString(values);
        }
    }

    public Iterable<? extends State> neighbours(State current) {
        List<State> foo = Lists.newArrayList();

        int n = current.size();
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                {
                    foo.add(transfer(current, i, j));
                    foo.add(transfer(current, j, i));
                }
            }
            emptyAndFill(foo, current, i);
        }

        return foo;
    }

    private void emptyAndFill(final List<State> foo, State current, int i) {
        final int[] values = current.values;
        {
            final int[] valuez = Arrays.copyOf(values, values.length);
            valuez[i] = 0;
            foo.add(state(valuez));
        }
        {
            final int[] valuez = Arrays.copyOf(values, values.length);
            valuez[i] = capacities[i];
            foo.add(state(valuez));
        }
    }

    private State transfer(State current, int i, int j) {
        int[] values = current.values;
        int[] valuez = Arrays.copyOf(values, values.length);
        int transfer = capacities[j] - values[j];
        if (values[i] < transfer) {
            transfer = values[i];
        }
        valuez[i] -= transfer;
        valuez[j] += transfer;
        return state(valuez);
    }


    public void solve(State target) {
        final Queue<State> queue = Queues.newArrayDeque();
        final Map<State, State> edges = Maps.newHashMap();

        final State start = state(new int[capacities.length]);

        queue.add(start);
        edges.put(start, State.NULL);

        while (!queue.isEmpty()) {
            State current = queue.remove();

            for (State s : neighbours(current)) {
                if (!edges.containsKey(s)) {
                    queue.add(s);
                    edges.put(s, current);
                }
            }
        }

        for (State s = target; s != null && s != NULL; s = edges.get(s)) {
            System.out.println(s);
        }
    }

    public static void main(String[] args) {
        final Search search = new Search(0, 4, 9);
        search.solve(state(0, 0, 6));
    }
}
