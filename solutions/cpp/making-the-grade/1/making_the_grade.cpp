#include <array>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

// Round down all provided student scores.
std::vector<int> round_down_scores(const std::vector<double>& student_scores) {
    std::vector<int> result(student_scores.size());

    std::transform(student_scores.begin(),
                   student_scores.end(),
                   result.begin(),
                   [](const double& score) { return static_cast<int>(score); }
    );

    return result;
}

// Count the number of failing students out of the group provided.
int count_failed_students(const std::vector<int>& student_scores) {
    return std::count_if(
        student_scores.begin(),
        student_scores.end(),
        [](const int& score) { return score <= 40; }
    );
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(const int& highest_score) {
    std::array<int, 4> thresholds;
    const int interval = (highest_score - 40) / thresholds.size();

    std::generate(thresholds.begin(),
                 thresholds.end(),
                 [threshold = 41 - interval, &interval] () mutable { // start at lowest threshold and calculate the following
                     return threshold += interval; 
                 }
    );
    
    return thresholds;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    const std::vector<int>& student_scores,
    const std::vector<std::string>& student_names
) {
    assert(student_scores.size() == student_names.size());
    std::vector<std::string> result(student_scores.size());

    std::transform(
        student_scores.begin(),
        student_scores.end(),
        student_names.begin(),
        result.begin(),
        [rank = 1](const int& score, const std::string& name) mutable {
            return std::to_string(rank++) + ". " + name + ": " + std::to_string(score);
        }
    );

    return result;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(const std::vector<int>& student_scores,
                          const std::vector<std::string>& student_names) {
    auto it = std::find(student_scores.begin(), student_scores.end(), 100);
    return it != student_scores.end() ? student_names.at(std::distance(student_scores.begin(), it)) : "";
}
