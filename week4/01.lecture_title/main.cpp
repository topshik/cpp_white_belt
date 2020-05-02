#include <iostream>

struct Specialization {
    std::string value;
    explicit Specialization(const std::string& val) {
        value = val;
    }
};

struct Course {
    std::string value;
    explicit Course(const std::string& val) {
        value = val;
    }
};

struct Week {
    std::string value;
    explicit Week(const std::string& val) {
        value = val;
    }
};

struct LectureTitle {
    std::string specialization;
    std::string course;
    std::string week;

    LectureTitle(Specialization new_spec, Course new_course, Week new_week) {
        specialization = new_spec.value;
        course = new_course.value;
        week = new_week.value;
    }
};


int main() {
    LectureTitle title(
            Specialization("C++"),
            Course("White belt"),
            Week("4th")
    );
    return 0;
}
