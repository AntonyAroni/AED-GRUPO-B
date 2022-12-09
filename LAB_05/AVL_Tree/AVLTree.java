
import static java.lang.Math.max;
public class AVLTree<T extends Comparable<T>> {
    private AVLNode<T> root;

    public AVLTree() {
        root = null;
    }

    public boolean isEmpty() {
        return root == null;
    }

    public int height() {
        return height(root);
    }

    private int height(AVLNode<T> node) {
        if (node == null) {
            return -1;
        }

        return node.height;
    }

    public int size() {
        return size(root);
    }

    private int size(AVLNode<T> node) {
        if (node == null) {
            return 0;
        }

        return node.size;
    }

    public boolean contains(T data) {
        return contains(root, data);
    }

    private boolean contains(AVLNode<T> node, T data) {
        if (node == null) {
            return false;
        }

        int cmp = data.compareTo(node.data);

        if (cmp < 0) {
            return contains(node.left, data);
        } else if (cmp > 0) {
            return contains(node.right, data);
        } else {
            return true;
        }
    }

    public void insert(T data) {
        root = insert(root, data);
    }

    private AVLNode<T> insert(AVLNode<T> node, T data) {
        if (node == null) {
            return new AVLNode<>(data);
        }

        int cmp = data.compareTo(node.data);

        if (cmp < 0) {
            node.left = insert(node.left, data);
        } else if (cmp > 0) {
            node.right = insert(node.right, data);
        } else {
            return node;
        }

        node.height = 1 + max(height(node.left), height(node.right));
        node.size = 1 + size(node.left) + size(node.right);

        return balance(node);
    }

    private AVLNode<T> balance(AVLNode<T> node) {
        if (node == null) {
            return null;
        }

        if (height(node.left) - height(node.right) > 1) {
            if (height(node.left.left) >= height(node.left.right)) {
                node = rotateRight(node);
            } else {
                node = rotateLeftRight(node);
            }
        } else if (height(node.right) - height(node.left) > 1) {
            if (height(node.right.right) >= height(node.right.left)) {
                node = rotateLeft(node);
            } else {
                node = rotateRightLeft(node);
            }
        }

        return node;
    }

    private AVLNode<T> rotateRightLeft(AVLNode<T> node) {
        node.right = rotateRight(node.right);
        return rotateLeft(node);
    }

    private AVLNode<T> rotateLeftRight(AVLNode<T> node) {
        node.left = rotateLeft(node.left);
        return rotateRight(node);
    }

    private AVLNode<T> rotateLeft(AVLNode<T> left) {
        AVLNode<T> right = left.right;
        left.right = right.left;
        right.left = left;

        left.height = 1 + max(height(left.left), height(left.right));
        left.size = 1 + size(left.left) + size(left.right);

        right.height = 1 + max(height(right.left), height(right.right));
        right.size = 1 + size(right.left) + size(right.right);

        return right;
    }

    private AVLNode<T> rotateRight(AVLNode<T> node) {
        AVLNode<T> left = node.left;
        node.left = left.right;
        left.right = node;

        node.height = 1 + max(height(node.left), height(node.right));
        left.height = 1 + max(height(left.left), height(left.right));

        node.size = 1 + size(node.left) + size(node.right);
        left.size = 1 + size(left.left) + size(left.right);

        return left;
    }

    public void delete(T data) {
        root = delete(root, data);
    }
    private AVLNode<T> delete(AVLNode<T> node, T data) {
        if (node == null) {
            return null;
        }

        int cmp = data.compareTo(node.data);

        if (cmp < 0) {
            node.left = delete(node.left, data);
        } else if (cmp > 0) {
            node.right = delete(node.right, data);
        } else {
            if (node.left == null) {
                return node.right;
            } else if (node.right == null) {
                return node.left;
            } else {
                AVLNode<T> temp = node;
                node = min(temp.right);
                node.right = deleteMin(temp.right);
                node.left = temp.left;
            }
        }

        node.height = 1 + max(height(node.left), height(node.right));
        node.size = 1 + size(node.left) + size(node.right);
        return node;
    }

    private AVLNode<T> deleteMin(AVLNode<T> right) {
        if (right.left == null) {
            return right.right;
        }

        right.left = deleteMin(right.left);
        right.height = 1 + max(height(right.left), height(right.right));
        right.size = 1 + size(right.left) + size(right.right);
        return right;
    }

    private AVLNode<T> min(AVLNode<T> right) {
        if (right.left == null) {
            return right;
        } else {
            return min(right.left);
        }
    }
    public AVLNode<T> NodeRoot() {
        return root;
    }
    private AVLNode<T> NodeRoot(AVLNode<T> node) {
        return node;
    }
}