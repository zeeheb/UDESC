public class Employee {

    String name, sname;
    double salario;

    public Employee(String name, String sname, double salario){
        this.name = name;
        this.sname = sname;
        if (salario > 0.0) {
            this.salario = salario;
        }
    }

    public void setName() {
        this.name = name;
    }

    public void setSName() {
        this.sname = sname;
    }

    public void setSalario(double salario) {
        if (salario > 0.0) {
        this.salario = salario;
        }
    }

    public double getSalario() {
        return salario;
    }

    public String getName() {
        return name;
    }

    public String getSName() {
        return sname;
    }


}
