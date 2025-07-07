package com.company.src.models.elements.brotypes;

import com.company.src.models.elements.attacktypes.AbsAttack;
import com.company.src.models.utility.BroSubtype;
import javafx.scene.control.Alert;

public abstract class AbsBro implements Comparable<AbsBro> {
    private int hp;
    private int level;
    private String name;
    private AbsAttack attack;
    private BroSubtype type;

    public AbsBro(){
        hp=0;
        name = "";
        attack = null;
        type = null;
        level=1;
    };

    public AbsBro(String name, BroSubtype type,  AbsAttack absAttack){
        this.level=1;
        this.type = type;
        this.hp = type.getMinLife();
        this.name = name;
        this.attack = absAttack;
    }

    public AbsBro(String name, BroSubtype type,  AbsAttack absAttack, int level){
        this.type = type;
        this.hp = type.getMinLife();
        this.name = name;
        this.attack = absAttack;
        this.level = 1;

        try{
            while (this.level < level){
                levelUp();
            }
        }catch (MaxLevel e){
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Max Level");
            alert.setHeaderText("Errore nella creazione del bro, livello troppo alto");
            alert.showAndWait();
            e.printStackTrace();
        }
    }

    public void levelUp() throws MaxLevel{
        if (level == 11){
            throw new MaxLevel();
        }

        level++;
        attack.updateDamage(attack.getBaseDamage()/10);

        if (hp+(type.getMinLife()/10)>type.getMaxLife()){
            hp=type.getMaxLife();
            return;
        }
        hp += (type.getMinLife()/10);
    }

    public BroSubtype getType() {
        return type;
    }

    public String getName() {
        return name;
    }

    public AbsAttack getAttack() {
        return attack;
    }

    public int getHp() {
        return hp;
    }

    public int getLevel() {
        return level;
    }

    @Override
    public int compareTo(AbsBro o) {
        if(this.name.compareTo(o.getName())==0){
            if(this.hp<o.getHp()){
                return -1;
            }
            else if(this.hp==o.getHp()){
                return 0;
            }
            return 1;
        }
        return this.name.compareTo(o.getName());
    }

    public class MaxLevel extends Exception{

    }
}
