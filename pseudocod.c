class Semaphor {
    semaphore(int v);
    void P(void);
    void V(void);
}

//implementazione di sezione critica con semafori 

Semaphore s = new Semaphore(1);
process P {
    while (true){
        s.P();
        //critical section
        s.V();
        //non-critical section 
    }
}

// per ogni semaforo occorre mantenere una struttura dati contenente l'insieme 
// dei processi sospesi 

// quando un processo deve essere svegliato, è necessario selezionare uno dei processi sospesi


//Primitive P and V

void P(){
    [enter critical section] // per la CS usiamo tecniche software: dekkeeper, Peterson o hardware: test&set, swap, etc.
    if(value > 0)
        value--;
    else {
        pid = <id del processo che invoca P>:
        queue,add(pid); // il proccess id del processo bloccaato viene messo in una strutture d'attesa del semaforo
        suspend(pid); //con l'operatore <SUSPEND> il S.O. matte il processo nello stato waiting
    }
    [exit critical section]
}

void V(){
    [enter critical section]
    if(queue.isEmpty())
        value++;
    else {
        pid = queue.remove();  //politica di sblocco FIFO
        wakeup(pid); // con wakeup il S.O. mette il processo nello stato ready
    }
    [exit critical section]
}