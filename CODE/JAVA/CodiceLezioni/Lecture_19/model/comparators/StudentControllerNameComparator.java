package Lecture_19.model.comparators;

import Lecture_19.controller.StudentController;

public class StudentControllerNameComparator implements MyComparator {

    private StudentNameComparator snc;

    public StudentControllerNameComparator(StudentNameComparator s){
        this.snc = s;
    }
    @Override
    public int compare(StudentController o1, StudentController o2) {
        return snc.compare(o1.getSt(), o2.getSt());
    }

    public StudentNameComparator getInnerComparator() { return snc; }
}
