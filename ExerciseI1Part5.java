//         Course: CS3820 Programming Languages
//           Name: Ulikowski, David
//     Assignment: Exercise I2
//          Part2:

import java.util.Scanner;

public class ExerciseI1Part5{

    static double tax, netPay;

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        String firstName, lastName;
        int IdNum, hours;
        float payRate, grossPay;

        System.out.println("Enter employee information");

        // get employee information
        firstName = input.next();
        lastName = input.next();
        IdNum = input.nextInt();
        payRate = input.nextFloat();
        hours = input.nextInt();

        // calculate gross pay
        grossPay = hours * payRate;
        // call instance method to calculate tax deduction and net pay
        ExerciseI1Part5 newObj = new ExerciseI1Part5();

        // output employee information
        System.out.println("Name:\t\t" + lastName +", " + firstName);
        System.out.println("Hours:\t\t" + hours);
        System.out.println("Pay Rate:\t$" + payRate);
        System.out.println("Gross Pay:\t$" + grossPay);
        newObj.computeTaxNetPay(grossPay);
    }

    // receive gross pay and compute tax deduction
    void computeTaxNetPay(double gross) {
        tax = 0.2 * gross;
        netPay = gross - tax;

        System.out.println("Tax Deduction:\t$" + tax);
        System.out.println("Net Pay:\t$" + netPay);

    }
}
