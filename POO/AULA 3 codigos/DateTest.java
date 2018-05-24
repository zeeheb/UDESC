public class DateTest {
    public static void main(String[] args) {

        Date data1 = new Date(4, 30, 2000);
        Date data2 = new Date(2, 8, 1997);

        data1.displayDate();
        data2.displayDate();

        Date data3 = new Date(0,0,0);
        System.out.println("Digite outro dia\n");
        int dia3 = input.nextInt();
        data3.setDia(dia3);
        System.out.println("Digite outro mes\n");
        int mes3 = input.nextInt();
        data3.setMes(mes3);
        System.out.println("Digite outro ano\n");
        int ano3 = input.nextInt();
        data3.setAno(ano3);

        data3.displayDate();

    }
}
