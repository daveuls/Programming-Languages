//         Course: CS3820 Programming Languages
//           Name: Ulikowski, David
//     Assignment: Exercise I4
//     Exercise I3 rewritten to include two source files

/*....... Source File ExerciseI4 .......*/
import java.util.Scanner;

public class ExerciseI4{
	static Scanner scan = new Scanner(System.in);
	
    public static void main(String [] args){
        int n;  // n test scores to be held in array
        double [] listGrades;	// array to hold test scores
		
        ExerciseI4Methods grades = new ExerciseI4Methods();

        System.out.println("Enter Number of Test Scores");
        n = scan.nextInt(); //readTestScores(n);

        listGrades = grades.readTestScores(n);

        grades.printTestResults(listGrades);
    }
} 


