import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

public class RandomWord {

    public static void main(String[] args) {
        String champion = "", testWord = "";
        int i = 0;

        while (!StdIn.isEmpty()) {
            i += 1;
            testWord = StdIn.readString();
            if (StdRandom.bernoulli(1.0 / (double) i)) {
                champion = testWord;
            }
        }
        StdOut.println(champion);
    }

}
