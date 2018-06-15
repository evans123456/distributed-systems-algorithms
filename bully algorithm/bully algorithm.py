from threading import Thread
import string

def select_coordinator():#function to select the coordinator
    coordinator_id = 0

    #loop through the network and select the computer with the highest id
    for key in ds: 
        if ds[key] > coordinator_id:
            coordinator_id = ds[key]
            coordinator = str(key)
        
    print("\nCoordinator is " + str(coordinator) + " with an id of " + str(coordinator_id) + "\n")



def delay_coordinator():
    print ("(Delayed)coordinator name is " + str(coordinator_id))
    print (ds)
    


def main():
    

    #initiate global variables to store the coordinator
    global coordinator
    global coordinator_id

    coordinator = 0
    coordinator_id = 0

    #initiate variable
    if coordinator == 0:            #check if there is any coordiantor
        select_coordinator()       #select a coordiantor
        
    
    
    print("\nCoordinator is " + str(coordinator) + " with an id of " + str(coordinator_id) + "\n")
    delay_coordinator()

if __name__ == '__main__':
    #create list with all our computers on the
    #network with their IDs
    ds = { "Process A": 6,"Process B": 14,"Process C": 10,"Process D": 19}
    main()