package in.kashyapp;

import com.google.common.collect.Queues;

import java.io.File;
import java.util.Deque;
import java.util.Iterator;

/**
 * User: kashyapp
 * Date: 10/01/14
 */
public class FSIterator {
    static Iterator<File> iterator(File root) {
        return new FSItr(root);
    }

    private static class FSItr implements Iterator<File> {
        Deque<File> queue = Queues.newArrayDeque();

        public FSItr(File root) {
            queue.add(root);
        }

        public boolean hasNext() {
            return !queue.isEmpty();
        }

        public File next() {
            File head = queue.pop();
            if (head.isDirectory()) {
                File[] files = head.listFiles();
                if (files == null) {
                    System.err.println("Bad directory: " + head);
                } else {
                    for (File file : files) {
                        queue.push(file);
                    }
                }
            }
            return head;
        }

        public void remove() {
            throw new UnsupportedOperationException("Not yet");
        }
    }

    public static void main(String[] args) {
        Iterator<File> itr = iterator(new File("/var/tmp"));
        while (itr.hasNext()) {
            System.out.println(itr.next());
        }
    }
}
