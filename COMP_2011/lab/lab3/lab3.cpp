#include <iostream>
using namespace std;

// Hardcoded class capacities for now
const int CAPACITY_COURSE_1 = 30;
const int CAPACITY_COURSE_2 = 25;
const int CAPACITY_COURSE_3 = 20;



/**
 * Check if the entered password is correct.
 * 
 * This function compares an entered password against a predefined correct password and
 * returns a boolean value indicating whether the entered password matches the correct one.
 * 
 * Input:
 *   password (int): The password entered by the user, expected to be an integer value.
 * 
 * Expected Output:
 *   Returns a boolean value based on the entered password:
 * 
 *   If the entered password matches the predefined correct password (1234):
 *     Returns true, indicating the password is correct.
 * 
 *   If the entered password does not match the correct password:
 *     Returns false, indicating the password is incorrect.
 * 
 *   There is no console output for either case; the function simply returns the boolean result.
 */

bool checkPassword(int password) {
    // Hardcoded password for now
    const int CORRECT_PASSWORD = 1234;
    //-------------------------------------------------------
    // ** Your TODO here #1 **

    if (password == CORRECT_PASSWORD)
        return true;
    else 
        return false;

    //-------------------------------------------------------
}



/**
 * Transform an integer input into a boolean value representing a yes/no response.
 * 
 * This function interprets an integer response to a yes/no question. The expected input
 * is either 0 or 1, where 0 represents "no" and 1 represents "yes". If any other integer
 * is provided, the function will consider it as an invalid input and default to "yes",
 * and also notify the user of this defaulting behavior.
 * 
 * Input:
 *   response (int): The integer response to the yes/no question, where 0 means "no" and 1 means "yes".
 * 
 * Expected Output:
 *   Returns a boolean value based on the following cases:
 * 
 *   If the response is 0:
 *     Returns false (interpreted as "no").
 *   
 *   If the response is 1:
 *     Returns true (interpreted as "yes").
 * 
 *   If the response is any integer other than 0 or 1:
 *     Outputs "Invalid input. Defaulting to YES." and returns true (interpreted as "yes").
 * 
 *   Note that the function only outputs a message in the case of an invalid input. There is no output
 *   for valid inputs (0 or 1).
 */

bool yesOrNo(int response)
{
    //-------------------------------------------------------
    // ** Your TODO here #2 **
    if (response == 0)
        return false;
    else if (response == 1)
        return true;
    else {
        cout << "Invalid input. Defaulting to YES." << endl;
        return true;
    }




    //-------------------------------------------------------
}


/**
 * Handle course enrollment
 * 
 * This function is designed to manage the enrollment process for a course. It evaluates 
 * whether a student meets the prerequisites, has no schedule conflicts, and if the course 
 * still has available seats. Depending on these checks, the function will output different 
 * results and update the current enrollment number accordingly.
 * 
 * Input:
 *   prereqsPassed (bool): Indicates if the student has passed all the required prerequisites.
 *   HasScheduleConflict (bool): Indicates if enrolling in the course would cause a schedule conflict.
 *   currentEnrollment (int&): The current number of students enrolled in the course. This value is 
 *                             updated if the student is successfully enrolled.
 *   capacity (int): The maximum number of students that can be enrolled in the course.
 * 
 * Expected Output:
 *   a. If the prerequisites are not passed:
 *     Outputs "You have not completed all the prerequisites."
 *     
 *   b. If there is a schedule conflict:
 *     Outputs "You have a schedule conflict." 
 *   
 *   c. If the course is full (current enrollment has reached capacity):
 *     Outputs "The course is full."
 * 
 *   d. If there are multiple items among a, b, or c that could be satisfied,
 *      the output should correspond to the first applicable condition in the order of the checks:
 *      prerequisites first, then schedule conflict, and finally course capacity.   
 *   
 *   e. If the student can be enrolled (prerequisites passes, no schedule conflict and class is not full):
 *     Outputs "You have been successfully enrolled in the course." , increments the current enrollment by 1.
 *    
 *   For the successful enrollment case: also outputs "Updated enrollment is: ??" at the end, where "??" is the current enrollment number 
 *   of the class after the sucessful enrollment.
 * 
 *   For the unsuceesful enrollment case (either case a, b or c listed above): also outputs "You fail to enroll the course." at the end.
 */

void enrollInCourse(bool prereqsPassed, bool HasScheduleConflict, int &currentEnrollment, int capacity)
{
    //-------------------------------------------------------
    // ** Your TODO here #3 **

    if (!prereqsPassed){
        cout << "You have not completed all the prerequisites." << endl;
        cout << "You fail to enroll the course." << endl;}

    else
    {   if (HasScheduleConflict){
            cout << "You have a schedule conflict." << endl;
            cout << "You fail to enroll the course." << endl;}

        else
        {   if (currentEnrollment == capacity){
                cout << "The course is full." << endl;
                cout << "You fail to enroll the course." << endl;}

            else
            {   currentEnrollment += 1;
                cout << "You have been successfully enrolled in the course." << endl;
                cout << "Updated enrollment is: " << currentEnrollment << endl;}}}
    //-------------------------------------------------------
}


// Main program function
int main() {
    int password;
    cout << "Enter the password to access the enrollment system: " << endl;
    cin >> password;

    if (!checkPassword(password)) {
        cout << "Incorrect password. Access denied." << endl;
        return 0;
    }

    cout << "Course Enrollment Menu:" << endl;
    cout << "1 - COMP1001" << endl;
    cout << "2 - COMP2002" << endl;
    cout << "3 - COMP3003" << endl;
    cout << "Select a course to enroll in (1-3): " << endl;

    int courseSelection;
    cin >> courseSelection;

    int prereqResponse;
    cout << "Have you completed all prerequisite courses? (1 for yes, 0 for no): " << endl;
    cin >> prereqResponse;
    bool prereqsPassed = yesOrNo(prereqResponse);

    int scheduleResponse;
    cout << "Do you have any schedule conflict with the selected course? (1 for yes, 0 for no): " << endl;
    cin >> scheduleResponse;
    bool HasScheduleConflict = yesOrNo(scheduleResponse);

    // Example enrollment data
    int currentEnrollmentCourse1 = 20; // Current enrollment for Course 1
    int currentEnrollmentCourse2 = 25; // Current enrollment for Course 2
    int currentEnrollmentCourse3 = 20; // Current enrollment for Course 3

    // Implement the course selection using the **enrollInCourse** function.
    // Ensure that you pass the correct arguments to the function based on the selected course.
    // Each course has its own current enrollment variable and capacity constant:
    // - If courseSelection is 1, call enrollInCourse with currentEnrollmentCourse1 and CAPACITY_COURSE_1.
    // - If courseSelection is 2, call enrollInCourse with currentEnrollmentCourse2 and CAPACITY_COURSE_2.
    // - If courseSelection is 3, call enrollInCourse with currentEnrollmentCourse3 and CAPACITY_COURSE_3.
    // - If courseSelection is not 1, 2, or 3, output "Invalid course selection." and do not call the enrollInCourse function.
    //-------------------------------------------------------
    // ** Your TODO here #4 **

    if (courseSelection == 1){
        enrollInCourse(prereqsPassed, HasScheduleConflict, currentEnrollmentCourse1, CAPACITY_COURSE_1);
    }
    else if (courseSelection == 2){
        enrollInCourse(prereqsPassed, HasScheduleConflict, currentEnrollmentCourse2, CAPACITY_COURSE_2);
    }
    else if (courseSelection == 3){
        enrollInCourse(prereqsPassed, HasScheduleConflict, currentEnrollmentCourse3, CAPACITY_COURSE_3);
    }

    else
        cout << "Invalid course selection." << endl;




    //-------------------------------------------------------

    return 0;
}
