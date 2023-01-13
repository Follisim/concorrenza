/*
Definizione
     esiste un processo "produttore" Producer che genera valori
    (record, caratteri, oggetti, etc.) e vuole trasferirli a un processo
    "consumatore" Consumer che prende i valori generati e li
    "consuma"
     la comunicazione avviene attraverso una singola variabile
    condivisa
Proprietà da garantire
     Producer non deve scrivere nuovamente l'area di memoria
    condivisa prima che Consumer abbia effettivamente utilizzato
    il valore precedente
     Consumer non deve leggere due volte lo stesso valore, ma
    deve attendere che Producer abbia generato il successivo
     assenza di deadlock  */

// Path: produttore-consumatore.c

shared Object buffer; 

semaphore empty = new semaphore(1);
semaphore full = new semaphore(0);



process Producer {
    while (true){
        object val+ produce();
        empty.P():
        buffer = val;
        full.V();
    }
}


process Consumer {
    while (true){
        full.P();
        object val = buffer;
        empty.V();
        consume(val);
    }
}