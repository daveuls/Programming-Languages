//         Course: CS3820 Programming Languages
//           Name: Ulikowski, David
//     Assignment: Exercise I1
//          Part1: Write a java program that consists of a class named ExerciseI1Part1
//				   with the method main that does the following:
//	a.	Read the first name, last name, ID number, the pay rate, and the number of hours worked by an employee.
//	b.	Compute the gross pay (hours time the pay rate)
//	c.	Compute the tax deduction (20% of the gross pay)
//	d.	Compute the net pay (gross pay minus tax deduction).
//	e.	Print the results using formatted output as follows:
//	Name:				Mark, peter
//	Hours:				35
//	Pay Rate:			$10.0
//	Gross Pay:			$350.00
//	Tax Deduction:		$70.00
//	Net Pay:			$280.00

import java.util.Scanner;

public class ExerciseI1Part1 {
	
	public static void main(String[] args) {
	Scanner input = new Scanner(System.in);
	
	String firstName, lastName;
	int IdNum, hours;
	float payRate, grossPay;
	double taxDeduction, netPay;
	
	System.out.println("Enter employee information");
	
	firstName = input.next();
	lastName = input.next();
	IdNum = input.nextInt();
	payRate = input.nextFloat();
	hours = input.nextInt();
	
	grossPay = hours * payRate;
	taxDeduction = 0.2 * grossPay;
	netPay = grossPay - taxDeduction;
	
	System.out.println("Name:\t\t" + lastName +", " + firstName);
	System.out.println("Hours:\t\t" + hours);
	System.out.println("Pay Rate:\t$" + payRate);
	System.out.println("Gross Pay:\t$" + grossPay);
	System.out.println("Tax Deduction:\t$" + taxDeduction);
	System.out.println("Net Pay:\t$" + netPay);
	
	}
}
