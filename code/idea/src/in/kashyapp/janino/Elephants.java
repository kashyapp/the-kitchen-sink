package in.kashyapp.janino;

import in.kashyapp.janino.Elephant;

/**
 * User: kashyapp
 * Date: 15/01/14
 */
public class Elephants {
    public static final Elephant KING = new Elephant(null, null).name("King");
    public static final Elephant QUEEN = new Elephant(null, null).name("Queen");

    public static final Elephant child(Elephant father, Elephant mother) {
        return new Elephant(father, mother);
    }
}
