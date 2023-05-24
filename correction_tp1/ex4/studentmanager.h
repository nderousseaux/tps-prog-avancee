#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

// Forward declaration of Student
class Student;

class StudentManager
{
private:
    static StudentManager uniqueManager_;

public:
    static inline StudentManager& getUniqueManager()
    {
        return StudentManager::uniqueManager_;
    }

private:
    StudentManager() = default;
    ~StudentManager() = default;

public:
    inline void updateStudentMeanScore(Student* student, float meanScore)
    {
        student->meanScore_ = meanScore;
    }
};

StudentManager StudentManager::uniqueManager_{};

#endif // STUDENTMANAGER_H