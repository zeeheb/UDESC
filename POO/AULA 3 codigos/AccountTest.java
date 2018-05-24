import java.util.Scanner;

public class AccountTest {
     public static void main(String[] args) {
         Account account1 = new Account("Jane Green", 50.00);
         Account account2 = new Account("John Blue", -7.00);

     System.out.printf("%s balance: %.2f\n", account1.getName(), account1.getBalance());
     System.out.printf("%s balance: %.2f\n", account2.getName(), account2.getBalance());

     Scanner input = new Scanner(System.in);

     System.out.print("Enter deposit amount for account1: ");
     double depositAmount = input.nextDouble();
     System.out.printf("\n adding %.2f to account1 balance\n\n", depositAmount);
     account1.deposit(depositAmount);

     System.out.printf("%s balance: %.2f\n", account1.getName(), account1.getBalance());
     System.out.printf("%s balance: %.2f\n", account2.getName(), account2.getBalance());

     System.out.print("Enter deposit amount for account2: ");
     double depositAmount2 = input.nextDouble();
     System.out.printf("\n adding %.2f to account2 balance\n\n", depositAmount2);
     account2.deposit(depositAmount2);

     System.out.printf("%s balance: %.2f\n", account1.getName(), account1.getBalance());
     System.out.printf("%s balance: %.2f\n", account2.getName(), account2.getBalance());

     System.out.print("Enter withdraw amount for account1: ");
     double withdrawAmount = input.nextDouble();
     System.out.printf("\n removing %.2f from account1 balance\n\n", withdrawAmount);
     account1.withdraw(withdrawAmount);

     System.out.print("Enter withdraw amount for account2: ");
     double withdrawAmount2 = input.nextDouble();
     System.out.printf("\n removing %.2f from account1 balance\n\n", withdrawAmount2);
     account2.withdraw(withdrawAmount2);

     System.out.printf("%s balance: %.2f\n", account1.getName(), account1.getBalance());
     System.out.printf("%s balance: %.2f\n", account2.getName(), account2.getBalance());

    }
}
