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

//trasformiamo await 

mutex.P();
if (!B){
    waiting[1]++;
    mutex.V()
    sem[i].P();
    waiting[i]--;
}
S_i;
SIGNAL();

void SIGNAL()// non deterministica
{
    if (B_0 && waiting[0] > 0)
    {
        waiting[0]--;
        sem[0].V();
    }
    □ (B_1 && waiting[1] > 0)
    {
        waiting[1]--;
        sem[1].V();
    }
    ...
	□ (B_{n - 1} && waiting[n - 1] > 0)
    {
        waiting[n - 1]--;
        sem[n - 1].V();
    }
    □ (!(B_0 && waiting[0] > 0) &&
       !(B_1 && waiting[1] > 0) &&
       ...!(B_{n - 1} && waiting[n - 1] > 0))
    {
        mutex.V();
    }
}

//prima soluzione. priorita ai lettori 

/* Introduced by transformation */
Semaphore mutex = new Semaphore(1); /* Mutual exclusion */
Semaphore semr = new Semaphore(0);  /* Reader semaphore */
Semaphore semw = new Semaphore(0);  /* Writer semaphore */
int waitingr = 0;                   /* Number of waiting reader */
int waitingw = 0;                   /* Number of waiting writer */
/* Problem variables */
int nr = 0; /* Number of current readers */
int nw = 0; /* Number of current writers */

process Reader
{
    while (true)
    {
        mutex.P();
        if (nw > 0)
        {
            waitingr++;
            mutex.V();
            semr.P();
        }
        nr++;
        SIGNAL();
        read the database
            mutex.P();
        nr--;
        SIGNAL();
    }
}

process Writer
{
    while (true)
    {
        mutex.P();
        if (nr > 0 || nw > 0)
        {
            waitingw++;
            mutex.V();
            semw.P();
        }
        nw++;
        SIGNAL();
        write the database
            mutex.P();
        nw--;
        SIGNAL();
    }
}

void SIGNAL()
{
    if ((nw == 0) && waitingr > 0)
    {
        waitingr--;
        semr.V()
    }
    if ((nw == 0 && nr == 0) && waitingw > 0)
    {
        waitingw--;
        semw.V()
    }
    if (!((nw == 0) && waitingr > 0) &&
        !((nw == 0 && nr == 0) && waitingw > 0))
    {
        mutex.V()
    }
}


// seconda soluzione (SIGNAL ridotto e deteministico)

process Reader {
    while (true) {
        mutex.P();
        if (nw > 0) {
            waitingr++;
            mutex.V();
            semr.P();
            waitingr--;
        }
        nr++;
        if(waiting > 0); //"passaggio del testimone" se ci sono altri writer in 
            semr.V();    // attesa faccio proseguire loro, rischiio di starvetion per i writer
        else
            mutex.V();
        read the database 
        muatex.P();
        nr--;
        if(nr == 0 && waitingw > 0)
            semw.V();
        else
            mutex.V();
    }
}

proces Writer {
    while (true) {
        mutex.P();
        if (nr > 0 || nw > 0) {
            waitingw++;
            mutex.V();
            semw.P();
            waitingw--;
        }
        nw++;
        mutex.V();
        write the database
        mutex.P();
        nw--;
        if(waitingw > 0)
            semw.V();
        else if(waitingw >0)
            semw.V();
        else
            mutex.V();
    }
}

// terza soluzione elimino la possibilita di starvation per i writer


process Reader {
    while (true) {
        mutex.P();
        if (nw > 0 || waitingw > 0) {// modificatao // se c è un writer in attesa si mette in fila dopo di lui 
            waitingr++;
            mutex.V();
            semr.P();
            waitingr--;
        }
        nr++;
        if(waiting > 0); 
            semr.V();    
        else
            mutex.V();
        read the database 
        muatex.P();
        nr--;
        if(nr == 0 && waitingw > 0)
            semw.V();
        else
            mutex.V();
    }
}

proces Writer {
    while (true) {
        mutex.P();
        if (nr > 0 || nw > 0) {
            waitingw++;
            mutex.V();
            semw.P();
            waitingw--;
        }
        nw++;
        mutex.V();
        write the database
        mutex.P();
        nw--;
        if(waitingw > 0)
            semw.V();
        else if(waitingw >0)
            semw.V();
        else
            mutex.V();
    }
}

