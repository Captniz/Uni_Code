package Lecture_19.model.comparators;

import Lecture_19.controller.StudentController;
import Lecture_19.model.Student;
import java.util.Comparator;

public interface MyComparator extends Comparator<StudentController> {
    Comparator<Student> getInnerComparator();
}
