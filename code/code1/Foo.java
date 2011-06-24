public class Foo {
    public static void main(String args[]) {
        String[] values = "Kashyap|Help|Me|I am a dumbao".split("\\|");
        for (String s : values) {
            System.out.println(s);
        }
    }
}
