//         Course: CS3820 Programming Languages
//           Name: Ulikowski, David
//     Assignment: Exercise I4
//     Exercise I3 rewritten to include two source files

/*....... Source File ExerciseI4Methods .......*/
import java.util.Scanner;

class ExerciseI4Methods{
/*....... Static Method readTestScores() .......*/
// receives a positive integer value n as argument
// n test scores into an array and then returns that array
    static double [] readTestScores(int size){
        Scanner input = new Scanner(System.in);
        double [] testScores = new double[size];    // array to hold student test scores

        System.out.println("Enter Student Test Scores");

        // enter test scores to be stored in array
        for(int i = 0; i < size; i++){
            testScores[i] = input.nextDouble();
        }

        return(testScores);
    }

/*....... Instance Method getLetterGrade() .......*/
// receive student score as a value parameter and determines the
// letter grade, A, B, C, D, F, and returns it to calling method
    char getLetterGrade(double score){
        char letterGrade;   // will hold letter grade

        if (score >= 90)
            letterGrade = 'A';
        else if (score >= 80)
            letterGrade = 'B';
        else if (score >= 70)
            letterGrade = 'C';
        else if (score >= 60)
            letterGrade = 'D';
        else
            letterGrade = 'F';

        return(letterGrade);
    }

/*....... Static Method printComment() .......*/
// receives student letter grade as a value parameter and prints the
// corresponding comments, defined in the method below
    static void printComment(char grade){
        if (grade == 'A')
            System.out.println("Very Good");
        else if (grade == 'B')
            System.out.println("Good");
        else if (grade == 'C')
            System.out.println("Satisfactory");
        else if (grade == 'D')
            System.out.println("Need Improvement");
        else
            System.out.println("Poor");
    }

/*....... Instance Method printTestResults() .......*/
// receives an array of test scores and prints a table with three columns
// consisting a test score in the first column, corresponding letter grade
// in the second column, and corresponding comment in the third column
    void printTestResults(double [] testList){
        ExerciseI4Methods result = new ExerciseI4Methods();
        double score;	// holds student test score
        char letterGrade;	// hold test score corresponding letter grade

        System.out.println("Test Score\t LetterGrade\t Comment");
        for(int i = 0; i < testList.length; i++) {
           score = testList[i];	// assign test score from array testList[]
           letterGrade = result.getLetterGrade(score);	// returned letter grade
           System.out.print(score + "\t\t\t" + letterGrade + "\t");
           printComment(letterGrade);
        }
    }
} /*....... End of Class ExerciseI3Methods .......*/