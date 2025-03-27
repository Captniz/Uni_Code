package Lecture_19.model.comparators;

import Lecture_19.controller.StudentController;

public class StudentControllerAgeComparator implements MyComparator {
    private StudentAgeComparator sac;

    public StudentControllerAgeComparator(StudentAgeComparator s){
        this.sac = s;
    }
    @Override
    public int compare(StudentController o1, StudentController o2) {
        return sac.compare(o1.getSt(), o2.getSt());
    }

    public StudentAgeComparator getInnerComparator() { return sac; }
}
