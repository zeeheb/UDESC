public class Date {
    int mes, dia, ano;

    public Date(int mes, int dia, int ano){
        this.mes = mes;
        this.dia = dia;
        this.ano = ano;
    }

public void setDia(int dia){
    this.dia = dia;
}

public void setMes(int mes){
    this.mes = mes;
}

public void setAno(int mes){
    this.ano = ano;
}

public int getAno(){
    return ano;
}

public int getMes(){
    return mes;
}

public int getDia(){
    return dia;
}

public void displayDate(){
    System.out.printf("%d/%d/%d", dia, mes, ano);
}

}
