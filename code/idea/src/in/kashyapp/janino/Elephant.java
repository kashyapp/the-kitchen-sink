package in.kashyapp.janino;

import com.google.common.base.Objects;
import com.google.common.collect.Lists;

import java.util.Arrays;
import java.util.List;

/**
* User: kashyapp
* Date: 15/01/14
*/
public class Elephant {
    private final Elephant father;
    private final Elephant mother;
    private final List<Elephant> siblings = Lists.newArrayList();
    private String name = "Baby";

    public Elephant(Elephant father, Elephant mother) {
        this.father = father;
        this.mother = mother;
    }

    public Elephant siblings(Elephant... ees) {
        siblings.addAll(Arrays.asList(ees));
        return this;
    }

    public Elephant name(String n) {
        this.name = n;
        return this;
    }

    public Elephant getFather() {
        return father;
    }

    public Elephant getMother() {
        return mother;
    }

    @Override
    public String toString() {
        return Objects.toStringHelper(this)
            .omitNullValues()
            .add("name", name)
            .add("father", father)
            .add("mother", mother)
            .add("siblings", siblings)
            .toString();
    }
}
