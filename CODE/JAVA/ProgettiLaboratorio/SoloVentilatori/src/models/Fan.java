package src.models;

import src.models.alimentation.Abs_Alim;
import src.models.types.Abs_Type;

public class Fan{

    private int costo;
    private String marca;
    private Abs_Alim alimentazione;
    private Abs_Type tipo;

    public Fan(String marca, Abs_Alim alimentazione, Abs_Type tipo) {
        if ((alimentazione.getAlimType() == Abs_Alim.Alim.MECCANICO) && (tipo.getType() == Abs_Type.Types.SOFFITTO)){
            throw new IllegalArgumentException("Un ventilatore a soffitto non può essere meccanico.");
        }

        this.marca = marca;
        this.alimentazione = alimentazione;
        this.tipo = tipo;
        this.costo = calculateCost();
    }

    private int calculateCost() {
        return (10 + tipo.getTypeCost()) * alimentazione.getAlimMult();
    }

    public String getMarca() {
        return marca;
    };

    public int getCosto() {
        return costo;
    };

    public Abs_Alim.Alim getAlimentazione() {
        return alimentazione.getAlimType();
    };

    public Abs_Type.Types getTipo() {
        return tipo.getType();
    };
}
