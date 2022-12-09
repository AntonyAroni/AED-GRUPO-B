import javax.swing.*;
import java.awt.*;

public class DrawAVLTree extends JFrame {

    public DrawAVLTree() {
        setTitle("AVL Tree");
        setSize(700, 500);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public void paint(Graphics g) {
        super.paint(g);
        AVLTree<Integer> tree = new AVLTree<>();
        for (int i = 0; i < 12; i++) {
            tree.insert(i*2);
        }
        drawTree(g, tree.NodeRoot(), 350, 50, 350, 50,0);
    }

    public void drawTree() {
        repaint();
    }

    private void drawTree(Graphics g, AVLNode<Integer> node, int x, int y, int parentX, int parentY,int count) {
        count+=40;
        if (node == null) {
            return;
        }

        g.setColor(Color.BLACK);
        g.fillOval(x, y, 30, 30);
        g.setColor(Color.WHITE);
        g.drawString(node.data.toString(), x + 10, y + 20);

        if (parentX != x || parentY != y) {
            g.setColor(Color.BLACK);
            g.drawLine(x + 15, y, parentX + 15, parentY + 30);
        }

        drawTree(g, node.left, x - 140+count, y + 50, x, y,count);
        drawTree(g, node.right, x + 140-count, y + 50, x, y,count);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                DrawAVLTree frame = new DrawAVLTree();
                frame.setVisible(true);
            }
        });
    }
}