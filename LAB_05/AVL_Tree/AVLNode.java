//AVLNode
public class AVLNode<T extends Comparable<T>> {
    T data;
    AVLNode<T> left, right;
    int height;
    int size;

    public AVLNode(T data) {
        this.data = data;
        this.left = null;
        this.right = null;
        this.height = 0;
        this.size = 1;
    }
}