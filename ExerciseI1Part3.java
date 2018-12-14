import java.util.Scanner;

public class ExerciseI1Part1 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        String firstName, lastName;
        int IdNum, hours;
        float payRate, grossPay;
        double taxDeduction, netPay;
        ExerciseI1Part1 newObj = new ExerciseI1Part1();

        System.out.println("Enter employee information");

        // get employee information
        firstName = input.next();
        lastName = input.next();
        IdNum = input.nextInt();
        payRate = input.nextFloat();
        hours = input.nextInt();

        // calculate gross pay, tax deduction, and net pay
        grossPay = hours * payRate;
        taxDeduction = computeTax(grossPay);
        netPay = newObj.computeNetPay(grossPay);

        // output employee information
        System.out.println("Name:\t\t" + lastName +", " + firstName);
        System.out.println("Hours:\t\t" + hours);
        System.out.println("Pay Rate:\t$" + payRate);
        System.out.println("Gross Pay:\t$" + grossPay);
        System.out.println("Tax Deduction:\t$" + taxDeduction);
        System.out.println("Net Pay:\t$" + netPay);

    }
    // compute tax deduction
    static double computeTax(double gross) {
        double taxDeduction = 0.2 * gross;

        return(taxDeduction);
    }
    // compute net pay
    double computeNetPay(double gross) {
        double tax, netPay;
        tax = computeTax(gross);
        netPay = gross - tax;

        return(netPay);
    }
}
