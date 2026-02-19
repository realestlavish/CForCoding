package Java;

class ArrayCreator {
    public static String CanwegetaPen(String a[]) {
        int nums[] = new int[4];
        for (int i = 0; i < 4; i++) {
            System.out.println(nums[i]);
        }
        return "0";
    }
}

class Balancechecker {
    public String CanwegetaPen(int cost) {
        int avalbal = 99;
        if (cost < avalbal)
            return "We can buy a Pen";
        else
            return "Insufficient Balance";
    }
}

class MusicPlayer {
    public String Playmusic() {
        return "Playing...";
    }

    public String StopMusic() {
        return "Stopping...";
    }
}

public class objects {
    public static void main(String[] args) {
        MusicPlayer music = new MusicPlayer();
        Balancechecker balance = new Balancechecker();

        String status = music.Playmusic();
        System.out.println(status);

        String penconfirmation = balance.CanwegetaPen(105);
        System.out.println(penconfirmation);
    }
}
