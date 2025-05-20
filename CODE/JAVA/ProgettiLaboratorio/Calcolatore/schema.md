# Farmacia

## Dati
- Soldi attuali
- Medicine
    - Nome
    - Costo
    - Scadenza
        - Indicata solo se sana | altrimenti scrivere `Scaduta`
    - Da banco o con ricetta
        - Quelle con ricetta possono essere ripetibili per `n` volte
        - Quelle con ricetta hanno uno sconto
            - Se ripetibili 5$
            - Se non ripetibili 10$
- Ricette
    - Medicina corrispondente
    - Data di scadenza
        - Indicata solo se non scaduta | altrimenti scrivere `Scaduta`
    - Contatore delle volte d'uso

## Finestra

### Layout
- Dim : 750 x 500
- Padding tra elementi della GUI : 10

### Elementi
- Orario in basso ( `java.util.Date()` )
- Lista Medicine
    - Testo incolonnato
    - Sinistra
- Singola medicina 
    - Guarda in figura
    - Se selezionata appare un pop-up centrale con la possibilità di comprarla
    - Il pop-up sparisce se non vi sono porblemi e viene deselezionata la ricetta
        - Possibili problematiche sono: 
            - (1) Pochi soldi
            - (2) Med. scaduta
            - (3) Ricetta corrispondente non è tra quelle dell'utente
            - (4) Ricetta corrispondente non selezionata
            - (5) Ricetta ripetutat più volte di quanto indicato dalla medicina
- Lista ricette
    - Destra
    - Bottoni incolonnati
- Ricetta singola
    - Guarda in figura
    - Disabilitata se scaduta
    - Disabilitata se selezionata
    - Se selezionata viene scritto
    - Ri abilitata se viene comprata la medicina

