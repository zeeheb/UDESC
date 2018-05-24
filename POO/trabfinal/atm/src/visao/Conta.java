
package visao;


public class Conta {
    private String nome;
    private double saldo;
    private int nroConta;
    private int pin;
    
        Conta(String nome, double saldo, int nroConta, int pin) {
          this.nome = nome;
          this.saldo = saldo;
          this.nroConta = nroConta;
          this.pin = pin;
        }
    
        
    void setNome(String nome) {
        this.nome = nome;
    }
    
    void setSaldo(double saldo) {
        this.saldo = saldo;
    }
    
    void setNroConta(int nroConta) {
        this.nroConta = nroConta;
    }
    
    void setPin(int pin) {
        this.pin = pin;
    }
    
    double getSaldo() {
        return saldo;
    }
    
    int getNroConta() {
        return nroConta;
    }
    
    int getPin() {
        return pin;
    }
}
