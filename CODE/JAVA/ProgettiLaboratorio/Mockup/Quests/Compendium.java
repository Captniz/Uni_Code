package Quests;

import java.util.List;
import java.util.LinkedList;

import UI.StatBar;

public class Compendium {
    List<Main_Quest> mainQuests;
    List<Side_Quest> sideQuests;
    List<Contract_Quest> contractQuests;   
    List<Dlc_Quest> dlcQuests;

    public Compendium(StatBar stats ){
		mainQuests = new LinkedList<Main_Quest>();
		sideQuests = new LinkedList<Side_Quest>();
		contractQuests = new LinkedList<Contract_Quest>();
		dlcQuests = new LinkedList<Dlc_Quest>();

        mainQuests.add(new Main_Quest(null, "Lilac and Gooseberries",2,"White Orchard",stats));
        mainQuests.add(new Main_Quest(mainQuests.getLast(), "The Nilfgaardian Connection", 3, "Velen", stats));
		mainQuests.add(new Main_Quest(mainQuests.getLast(), "Pyres of Novigrad", 5, "Novigrad", stats));
		
		sideQuests.add(new Side_Quest("A Favor for a Friend", 2, 10, "Keira Metz", stats));
		sideQuests.add(new Side_Quest("The Last Wish", 6, 30, "Bloody Baron", stats));
		
		contractQuests.add(new Contract_Quest("Swamp Thing", 12, 40, null, new String[]{"Drowners", "Foglet"}, stats));
		contractQuests.add(new Contract_Quest("Coast of Wrecks", 4, 50, "Novigrad", new String[]{"Drowners"}, stats));
		contractQuests.add(new Contract_Quest("Dirty Funds", 1, 20, "Velen", new String[]{"Wolves", "Drowners"}, stats));

		dlcQuests.add(new Dlc_Quest(null,mainQuests.get(0), "Envoys, Wineboys", 8, "Velen", stats));
		dlcQuests.add(new Dlc_Quest(dlcQuests.getLast(),mainQuests.get(0), "Capture the Castle", 9, "Toussaint", stats)); 
	}


	public List<Main_Quest> getMainQuests() {
		return mainQuests;
	}

	public List<Side_Quest> getSideQuests() {
		return sideQuests;
	}

	public List<Contract_Quest> getContractQuests() {
		return contractQuests;
	}

	public List<Dlc_Quest> getDlcQuests() {
		return dlcQuests;
	}
}
