class Student {
    def name
    def rollno
    Student(name, rollno) { 
        this.name = name
        this.rollno = rollno
    }
    String toString() { 
        "{${name} ${rollno}}" 
    }
}

def s(name, rollno) { 
    new Student(name, rollno) 
}

batch = [s('kashyap','001'), s('kuntal','002'), s('arun','003'), s('vinay','004')]
marks = ['001':90,'002':95,'003':98,'004':89]

def comp1(markMap) { 
    { it -> 
        println "comp1 ${it}"
        markMap[it.rollno]
    } 
}

def comp2(markMap) { 
    { b,a -> 
        println "comp2 ${a} ${b}"
        markMap[a.rollno] <=> markMap[b.rollno]
    } 
}

sorted = batch.sort(comp1(marks))
println sorted

sorted = batch.sort(comp2(marks))
println sorted
