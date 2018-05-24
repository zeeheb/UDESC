import java.util.Scanner;

public class EmployeeTest {

    public static void main(String[] args) {
        Employee employee1 = new Employee("Joao", "Silva", 1000.50);
        Employee employee2 = new Employee("Jose", "Silvo", 5000.99);

        System.out.printf("%s %s salario: %.2f\n\n", employee1.getName(), employee1.getSName(), employee1.getSalario());
        System.out.printf("%s %s salario: %.2f\n\n", employee2.getName(), employee2.getSName(), employee2.getSalario());

        System.out.println("Dando aumento de 10%:\n");

        double salario1 = employee1.getSalario();
        double salario2 = employee2.getSalario();

        salario1 = salario1 + salario1 * 0.10;
        salario2 = salario2 + salario2 * 0.10;

        employee1.setSalario(salario1);
        employee2.setSalario(salario2);

        System.out.printf("%s %s salario: %.2f\n\n", employee1.getName(), employee1.getSName(), employee1.getSalario());
        System.out.printf("%s %s salario: %.2f\n\n", employee2.getName(), employee2.getSName(), employee2.getSalario());


    }
}
