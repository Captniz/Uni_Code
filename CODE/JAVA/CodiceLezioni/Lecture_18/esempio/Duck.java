package Lecture_18.esempio;

import Lecture_18.esempio.flyable.Flyable;
import Lecture_18.esempio.quackable.Quackable;

public class Duck implements DuckLike{
    protected Flyable flybehaviour;
    protected Quackable quackbehaviour;

    @Override
    public String quack() {
        return this.quackbehaviour.quack();
    }

    @Override
    public String fly() {
        return this.flybehaviour.fly();
    }

    public void display(){
        System.out.println("I am a "+this.getClass()+", i can quack liek this: "+this.quack()+" and fly like this: "+this.fly());
    }
    public void setFlybehaviour(Flyable f){
        this.flybehaviour = f;
    }
    public void setQuackbehaviour(Quackable q){
        this.quackbehaviour = q;
    }
}
