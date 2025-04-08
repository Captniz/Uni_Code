package interfaces;

import data.*;

public interface StdMut {
    public void applyMutation(Attributes attr);
    public void removeMutation(Attributes attr);
    public String getName();
}