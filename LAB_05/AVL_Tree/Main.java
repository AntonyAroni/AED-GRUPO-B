import javax.swing.*;
import java.util.*;
public class Main {

    public static void main(String[] args) {

        AVLTree<Integer> tree = new AVLTree<>();

        for (int i = 0; i < 10; i++) {
            tree.insert(i*2);
        }

        System.out.println("Tree height: " + tree.height());
        System.out.println("Tree size: " + tree.size());
        System.out.println("Tree contains 5: " + tree.contains(5));
        System.out.println("Tree contains 10: " + tree.contains(10));

        tree.delete(5);

    }
}
