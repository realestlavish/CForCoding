package Java;


class Balancechecker{
    public String CanwegetaPen(int cost){
        int avalbal=99;
        if(cost<avalbal) return "We can buy a Pen";
        else return "Insufficient Balance";
}}

class MusicPlayer{
    public String Playmusic(){
        return "Playing...";
    }
    public String StopMusic(){
        return "Stopping...";
    }
}

public class objects {
    public static void main(String[] args) {
        MusicPlayer music= new MusicPlayer();
        Balancechecker balance= new Balancechecker();
        
        String status =music.Playmusic();
        System.out.println(status);
        
        String penconfirmation = balance.CanwegetaPen(105);
        System.out.println(penconfirmation);
    }
}
