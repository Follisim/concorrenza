/*
Descrizione
     un database è condiviso tra un certo numero di processi
     esistono due tipi di processi
     i lettori accedono al database per leggerne il contenuto
     gli scrittori accedono al database per aggiornarne il contenuto
Proprietà
     se uno scrittore accede a un database per aggiornarlo,
        esso opera in mutua esclusione;
        nessun altro lettore o scrittore può accedere al database
     se nessuno scrittore sta accedendo al database, un numero
        arbitrario di lettori può accedere al database in lettura */


// lettore 
process Reader {
    while(true){
        startrRead(); // contiene le operazioni per accedere al database
        read();
        endRead();
    }
}

process Writer {
    while(true){
        startWrite();// contiene le operazioni per accedere al database
        write();
        endWrite();
    }
}

// soluzione basata su semafori
// schema Andrews

//definimao <await>
//S = statment =>  <S> = esegue S in modo atomico
//<await(boolean)-> S > = attendi che B sia verificata quindi esegui S , attesa e comando sono eseguiti in modo atomico 

//definiamo 2 variabili 

//nr -> numero di lettori che stanno leggendo il database
//nw -> numero di scrittori che stanno scrivendo il database

//invariante: (nr >= 0 && nw ==0) || (nr == 0 && nw == 1)

process Reader{
    <await(nw == 0) → nr++>
    read the database
    <nr-->}

process Writer{
    < await (nr == 0 && nw == 0) → nw++ >
    write the database
    < nw-- >
}

