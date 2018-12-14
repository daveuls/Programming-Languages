//         Course: CS3820 Programming Languages
//           Name: Ulikowski, David
//     Assignment: Exercise I2
//          Part2:

import java.util.Scanner;

public class ExerciseI1Part2 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        String firstName, lastName;
        int IdNum, hours;
        float payRate, grossPay;
        double taxDeduction, netPay;

        System.out.println("Enter employee information");

        // get employee information
        firstName = input.next();
        lastName = input.next();
        IdNum = input.nextInt();
        payRate = input.nextFloat();
        hours = input.nextInt();

        // calculate gross pay
        grossPay = hours * payRate;
		// call class (static) methods to calculate tax deduction and net pay
        taxDeduction = computeTax(grossPay);
        netPay = computeNetPay(grossPay);

        // output employee information
        System.out.println("Name:\t\t" + lastName +", " + firstName);
        System.out.println("Hours:\t\t" + hours);
        System.out.println("Pay Rate:\t$" + payRate);
        System.out.println("Gross Pay:\t$" + grossPay);
        System.out.println("Tax Deduction:\t$" + taxDeduction);
        System.out.println("Net Pay:\t$" + netPay);

    }
    // class (static) method to compute tax deduction
    static double computeTax(double gross) {
        double taxDeduction = 0.2 * gross;

        return(taxDeduction);
    }
    // class (static) method to compute net pay
    static double computeNetPay(double gross) {
        double tax, netPay;
        tax = computeTax(gross);
        netPay = gross - tax;

        return(netPay);
    }
}
