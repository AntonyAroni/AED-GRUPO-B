public class User {
    private int id;
    private String name;
    private String email;
    public User() {
    }
    public User(int pId, String pName, String pEmail) {
        id = pId;
        name = pName;
        email = pEmail;
    }
    @Override
    public int
    hashCode() {
        final int prime = 31;
        int result = id;
        result = prime * result + ((email == null) ? 0 : email.hashCode());
        result = prime * result + (int) (id ^ (id >>> 32));
        result = prime * result + ((name == null) ? 0 : name.hashCode());
        return result;
    }
}
