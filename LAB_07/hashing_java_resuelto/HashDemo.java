public class HashDemo {
    public static void main(String[] args) {
        Object[] ob = new Object[] { 22, 7 };
        System.out.println("Primer hash: " + ob.hashCode());
        System.out.println("Segundo hash: "
                + (new Object[] { 3.5, 8.5 }).hashCode());

        /* User */
        User u = new User(2, "lucia", "luc@unsa.edu.pe");
        System.out.println("User hash: " + u.hashCode());
    }

}
