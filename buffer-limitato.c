/*
Definizione
     è simile al problema del produttore / consumatore
     in questo caso, però, lo scambio tra produttore e
    consumatore non avviene tramite un singolo elemento, ma
    tramite un buffer di dimensione limitata, i.e. un vettore di
    elementi
Proprietà da garantire
     Producer non deve sovrascrivere elementi del buffer prima
    che Consumer abbia effettivamente utilizzato i relativi valori
     Consumer non deve leggere due volte lo stesso valore, ma
    deve attendere che Producer abbia generato il successivo
     assenza di deadlock
     assenza di starvation */


// Path: buffer-limitato.c


Queue q(maxsize = SIZE);
Semaphore empty = new Semaphore(SIZE);
Semaphore full = new Semaphore(0);
Semaphore mutex = new Semaphore(1);





process Producer {
    while (true){
        object val = produce();
        empty.P();
        mutex.P();
        q.enqueue(val);
        mutex.V();
        full.V();
    }
}


process Consumer {
    while (true){
        Object val;
        full.P();
        mutex.P();
        val = q.dequeue();
        mutex.V();
        empty.V();
        consume(val);
    }
}