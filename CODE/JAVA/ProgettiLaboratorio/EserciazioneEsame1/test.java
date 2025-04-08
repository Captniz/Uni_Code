/*import java.lang.reflect.Modifier;
import java.util.HashMap;
import java.util.Map;
import org.reflections.Reflections;

// Abstract spell class
abstract class AbsSpell {
    abstract void cast();
}

// Spell implementations
class Fireball extends AbsSpell {
    void cast() {
        System.out.println("Casting Fireball!");
    }
}

class IceBlast extends AbsSpell {
    void cast() {
        System.out.println("Casting Ice Blast!");
    }
}

// Enum for spell types
enum SpellType {
    FIREBALL,
    ICE_BLAST;
}

// Player class managing spells
class Player {
    private Map<SpellType, AbsSpell> spellBook = new HashMap<>();

    public Player() {
        autoRegisterSpells();
    }

    // Automatically finds and registers all spells
    private void autoRegisterSpells() {
        Reflections reflections = new Reflections("your.spell.package"); // Change to actual package
        for (Class<? extends AbsSpell> spellClass : reflections.getSubTypesOf(AbsSpell.class)) {
            try {
                if (!Modifier.isAbstract(spellClass.getModifiers())) { // Avoid abstract classes
                    AbsSpell spellInstance = spellClass.getDeclaredConstructor().newInstance();
                    SpellType type = SpellType.valueOf(spellClass.getSimpleName().toUpperCase());
                    spellBook.put(type, spellInstance);
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    public void castSpell(SpellType type) {
        AbsSpell spell = spellBook.get(type);
        if (spell != null) {
            spell.cast();
        } else {
            System.out.println("You haven't learned this spell!");
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Player player = new Player();
        player.castSpell(SpellType.FIREBALL);  // Output: Casting Fireball!
        player.castSpell(SpellType.ICE_BLAST); // Output: Casting Ice Blast!
    }
}
*/