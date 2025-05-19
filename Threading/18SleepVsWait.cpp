//SLEEP IS :
//"I’m done with my timeslice, and please don’t give me another one for at least n milliseconds."
//The OS doesn’t even try to schedule the sleeping thread until the requested time has passed.
//POINTS :
//	It will keep the lock and sleep.
//	Sleep is directly to thread, it is a thread function.
//WAIT IS :
//"I’m done with my timeslice. Don’t give me another timeslice until someone calls notify()."
//As with sleep(), the OS won’t even try to schedule your task unless someone calls notify() 
//(or one of a few other wakeup scenarios occurs).
//POINTS :
//	It releases the lock and waits.
//	Wait is on a condition variable, meaning there is a condition variable in a thread, and wait() is applied 
//	to that CV, putting the thread in a waiting state.


