public class Mando {
    public Mando() {
        if(this.isTheWay()) {
            System.out.println("This is the way");
        }
    }

    private boolean isTheWay(){
        return true;
    }

    public static void main(String args[]) {
        Mando mando = new Mando();
    }
}
