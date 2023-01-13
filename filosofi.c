// vita di un filosofo
process Philo[i]{// i = 0, 1, 2, 3, 4
  while (true){
    think();
    take_chopsticks(i);   
    eat();
    put_chopsticks(i);
  }
}

// le bacchette sono chopstick[i] con i=0,...,4
// il filosofo i prende le bacchette chopstick[i] e chopstick[(i+1)%5]

//cena con filosofi 

Semaphore chopsticks = {new Semaphore(1),...,NEW /Semaphore(1)};

process Philo[i]{ // i = 0...3 // i filosofi 1,2,3 prendono prima la bacchetta a destra 
  while (true){
    think();
    chopsticks[i].P();
    chopsticks[(i+1)].P();
    eat();
    chopsticks[i].V();
    chopsticks[(i+1)].V();
  }
}
process Philo[4]{ // inseriamo un filosofo mancino che prende prima la baccchetta di sinistra
    while (true){ // il filosofo mancino impedisce la situazione di deadlock
        think();
        chopsticks[0].P();
        chopsticks[4].P();
        eat();
        chopsticks[0].V();
        chopsticks[4].V();
      }
}

//soluzione 2 i filosofi pari sono mancini e dispari destri

process Philo[i]{ // i = 2,4
    while (true){
        think();
        chopsticks[i].P();
        chopsticks[(i+1)%5].P();
        eat();
        chopsticks[i].V();
        chopsticks[(i+1)%5].V();
    }
}

process Philo[i]{ // i = 1,3
    while (true){
        think();
        chopsticks[(i+1)%5].P();
        chopsticks[i].P();
        eat();
        chopsticks[(i+1)%5].V();
        chopsticks[i].V();
    }
}
